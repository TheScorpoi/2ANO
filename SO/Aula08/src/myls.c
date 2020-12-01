#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// exemplo de output do myls.c
/*
============================================= (esta linha escreve o pai)
drwx --- ----                                 (escrito pelo filho)
drwx --- ----                                 (escrito pelo filho)
============================================= (esta linha escreve o pai, o wait, permite que isto so print depois do filho terminar)

           myls
            |
            | printf("=====...")
            |
            .fork()
            |\
    PAI     | \     FILHO
            |  \
            |   \
            |    |
            |    . exec(ls -la)
    wait()  .
            |
 print("=." .

 para execl("/bin/ls", "ls", "-la", NULL)
 para execlp("ls", "ls", "-la", NULL)

*/

int main(int argc, char const *argv[])
{
    int stat;
    printf("==================================================\n");

    switch(fork()){
		case -1: //Falha
			perror("Erro na criação do processo filho!\n");
			return EXIT_FAILURE;
		case 0: //Processo filho
			sleep(2);
			if(execlp("ls", "ls", "-la", NULL)<0){
				perror("Erro ao executar a função execl()\n");
				return EXIT_FAILURE;
			}
			break;
		default: //Processo pai
			if(wait(&stat)<0){
				perror("Erro na espera pelo processo filho!\n");
				return EXIT_FAILURE;
			}else{
				printf("==================================================\n");
			}
	}
    return EXIT_SUCCESS;
}

