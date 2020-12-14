#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid()); // 1x | executado pelo pai
    if ((ret = fork()) < 0) { // executado pelo pai e pelo filho
        perror ("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0) {
    sleep (1); // o if executado pelo pai e pelo filho, o sleep é so executado pelo pai
    }
    
    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d\n", getpid(), getppid()); //2x(2 linhas) (uma pelo pai outro pelo filho)

    return EXIT_SUCCESS; //executado pelo pai e pelo filho
}

// Pergunta 1 - Respostas
/*
Alínea B
i) -> 5 linhas (o 2º printf printa 4 linhas, por causa dos '\n')
ii) -> Feito nos comentários dos cdigos, o PPID é a bash, fazer um cmd ps para confirmar
iii)->
       | printf("Antes do fork...")    
       |     
       .fork        
       |\                                                         
if()   | \  if()                                                      
       |  \     printf("Quem ...")   
slepp1 |   \       return 0
       |    \
printQ |    |
ret 0  |    | 
 
*/