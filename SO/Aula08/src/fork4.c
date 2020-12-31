#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int stat;

    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
               if (execl("./child", "./child", NULL) < 0) { 
                   perror("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               break;
      default: /* processo pai */
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
               if (wait(&stat) < 0) { //fica à espera que o filho termine ou pare, e o wait retorna o PID do filho que parou
                   perror("erro na espera da terminação do processo-filho");
                   return EXIT_FAILURE;
               }
               printf("Pai: o processo-filho terminou. ");
               if (WIFEXITED(stat) != 0) { // MACRO 'WIFEXITED' para saber se terminou
                   printf("O seu status de saída foi %d.\n", WEXITSTATUS(stat)); //MACRO 'WEXITSTATUS'
               }
               else {
                   printf("O processo filho terminou de forma anormal.\n");
               }
    }

    return EXIT_SUCCESS;
}

// Pergunta 4 - Respostas
/*
i) No fork4.c a grande diferença relativamente ao fork3.c é o acrescimento do
metodo wait(), que faz com que o pai fique à espera que o filho acabe,
deste modo 

ii) Ordem de impressão:
Pai (antes do fork) 
Pai(depois do fork)
Filho
Filho
Pai: o processo filho terminou O seu status de said foi

iii) Como agora o processo pai so continua qd o filho acaba o prompt já esta "no sitio certo"

*/
