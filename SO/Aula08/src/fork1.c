#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror ("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0) sleep (1);
    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d\n", getpid(), getppid());

    return EXIT_SUCCESS;
}
