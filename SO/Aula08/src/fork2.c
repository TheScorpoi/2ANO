#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0)
    {
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0) // PAI
    {
        sleep(1);
        printf("PAI\n");
    }
    else //FILHO
    {
        printf("FILHO\n");
    }

    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d\n",
           getpid(), getppid(), ret);

    return EXIT_SUCCESS;
}

// Pergunta 2 - Respostas
/*

Valor de retorno do filho no fork é 0, assim conseguimos saber que esse é o processo-filho




*/