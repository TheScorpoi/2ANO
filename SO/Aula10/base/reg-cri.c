/**
 * reg-cri
 *
 * Programa de ilustração da necessidade de controlo de
 * acesso a regiões críticas, baseado numa proposta inicial
 * do Pedro Mariano.
 *
 * Sintaxe: reg-cri [opcões]
 */

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <libgen.h>
#include <math.h>

#include "sharedMemory.h"
#include "semaphore.h"

#define SHMKEY 0x100
#define NPROC      4
#define BIG     1000

/* mensagem de ajuda */
#define USAGE "Sintaxe: %s [opções]\n"\
    "\t----------+--------------------------------------------\n"\
    "\t   Opção  |          Descrição                         \n"\
    "\t----------+--------------------------------------------\n"\
    "\t -i num   | lança quatro processos, cada um incrementando a variável residente em mem. part. num vezes\n"\
    "\t -c       | cria uma região de memória partilhada onde é definida uma variável\n"\
    "\t -d       | destroi a região de memória partilhada\n"\
    "\t -s num   | inicializa a variável residente em memória partilhada\n"\
    "\t -p       | imprime no 'stdout' o valor da variável\n"\
    "\t -h       | esta ajuda                                 \n"\
    "\t----------+--------------------------------------------\n"

static int set(int value);
static int iter(int value);
static int print(void);
static int create(void);
static int destroy(void);

int main (int argc, char *argv[])
{
    /* processamento da linha de comando */
    const char *optstr = "i:cds:ph";
    int option;

    do { 
        switch ((option = getopt (argc, argv, optstr)))
        { 
            case 'i': return iter (atoi (optarg));
            case 's': return set (atoi (optarg));
            case 'p': return print ();
            case 'c': return create ();
            case 'd': return destroy ();
            case 'h': printf (USAGE, basename (argv[0]));
                 return EXIT_SUCCESS;
            default: fprintf (stderr, "Opção não válida\n");
            case -1: fprintf (stderr, USAGE, basename (argv[0]));
                 return EXIT_FAILURE;
        }
    } while (option >= 0);

    return EXIT_SUCCESS;
}

void delay(int nite)
{
    int k;
    double b = 0.0;
    double c = 0.0;
    double PI = 3.141516;

    for (k = 0; k < nite; k++)
    { 
        b = cos (c + PI/4);
        c = sqrt (fabs (b));
    }
}

static int create(void)
{
    int semid;
    /* cria a memória partilhada, falhando se já existir */
    if (shmemCreate (SHMKEY, sizeof (long)) == -1) { 
        perror ("shmemCreate");
        return EXIT_FAILURE;
    }

    // cria um semáforo, falhando se já existir
    if ((semid = semCreate(SHMKEY, 1)) == -1)
    {
        perror("semCreate");
        return EXIT_FAILURE;
    }

    semUp(semid, 1);
    semSignal(semid);

    return EXIT_SUCCESS;
}

static int destroy(void)
{
    /* ganha acesso à memória partilhada */
    int shmid = shmemConnect (SHMKEY);
    if (shmid == -1) { 
        perror ("shmemConnect");
        return EXIT_FAILURE;
    }

    int semid = semConnect(SHMKEY);
    if (semid == -1)
    {
        perror("semConnect");
        return EXIT_FAILURE;
    }

     if(semDestroy(semid) == -1)
    {
        perror("semDestroy");
        return EXIT_FAILURE;
    }

    /* destroi-a */
    if (shmemDestroy (shmid) == -1) { 
        perror ("shmemDestroy");
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}

static int iter(int niter)
{
    int i, j, auxcnt;

    /* ganha acesso à memória partilhada */
    int shmid = shmemConnect (SHMKEY);
    if (shmid == -1) { 
        perror ("shmemConnect");
        return EXIT_FAILURE;
    }

    /* anexa a memória partilhada ao espaço de endereçamento próprio */
    int *cntp;
    if (shmemAttach (shmid, (void **) &cntp) == -1) { 
        perror ("shmemAttach");
        return EXIT_FAILURE;
    }

    //ganha acesso ao semaforo
    int semid = semConnect(SHMKEY);
    if (semid == -1) { 
        perror ("semConnect");
        return EXIT_FAILURE;
    }    

    /* lança processos incrementadores e espera pelo seu termo */
    for (i = 0; i < NPROC; i++)
    { 
        switch (fork ())
        { 
            case -1: perror ("fork");
                 return EXIT_FAILURE;

            case 0:  // processo incrementador
                 for (j = 0; j < niter; j++)
                 { /* faz cópia do contador em mem. part. */
                     //!da linha 176 até à ate 183 tb é região critica
                     semDown(semid, 1);
                     auxcnt = *cntp;

                     /* generate a time delay */
                     delay (BIG);

                     /* incrementa a cópia e armazena-a em mem. part. */
                     *cntp = auxcnt + 1;
                     semUp(semid, 1);

                     /* generate a time delay */
                     delay (BIG);
                 }

                 /* desanexa a memória partilhada do espaço de endereçamento próprio */
                 if (shmemDettach (cntp) == -1) { 
                     perror ("incrementador - shmemDettach");
                     return EXIT_FAILURE;
                 }

                 return EXIT_SUCCESS;
        }
    }

    /* espera pelos termo dos incrementadores e sai */
    for (i = 0; i < NPROC; i++) {
        wait(NULL);
    }
    return EXIT_SUCCESS;
}

static int set(int value)
{
    /* ganha acesso à memória partilhada */
    int shmid = shmemConnect (SHMKEY);
    if (shmid == -1)
    { 
        perror ("shmemConnect");
        return EXIT_FAILURE;
    }

    /* anexa a memória partilhada ao espaço de endereçamento próprio */
    int *cntp;
    if (shmemAttach (shmid, (void **) &cntp) == -1) { 
        perror ("shmemAttach");
        return EXIT_FAILURE;
    }

    /* inicializa o contador em memória partilhada */
    //!regiao critica
    //! também era para mudar aqui umas coisas, acho que down antes do print e up depois mas n consegui ver bem onde era
    *cntp = value;

    /* desanexa a memória partilhada do espaço de endereçamento próprio */
    if (shmemDettach (cntp) == -1) { 
        perror ("incrementador - shmemDettach");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int print(void)
{
    /* ganha acesso à memória partilhada */
    int shmid = shmemConnect (SHMKEY);
    if (shmid == -1) { 
        perror ("shmemConnect");
        return EXIT_FAILURE;
    }

    /* anexa a memória partilhada ao espaço de endereçamento próprio */
    int *cntp;
    if (shmemAttach (shmid, (void **) &cntp) == -1)
    { 
        perror ("shmemAttach");
        return EXIT_FAILURE;
    }

    /* imprime valor */
    //!regiao critica
    //! também era para mudar aqui umas coisas, acho que down antes do print e up depois mas n consegui ver bem onde era
    printf("Value = %d\n", *cntp);

    /* desanexa a memória partilhada do espaço de endereçamento próprio */
    if (shmemDettach (cntp) == -1)
    { 
        perror ("incrementador - shmemDettach");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
