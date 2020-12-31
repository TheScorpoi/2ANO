#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
               if (execlp("ls", "ls","-l", NULL) < 0) { //exec é chamado uma vez e nunca retorna
                   perror("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               printf("Porque é que eu não apareço?\n");// pq qd se faz um exec nada daí pra frente é executado
               break;
      default: /* processo pai */
               sleep(1);
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    }

    return EXIT_SUCCESS;
}

// Pergunta 3 - Respostas
/*

O pai escreve, o filho escreve, o pai espera +/- 1s e dps volta a escrever, enq o filho espera +/- 3s, sendo que
quando o filho vai printar, o processo pai já parou, ent o seu PPID já nao vai ser o do PAI, o upstart irá herdar
o processo filho

a bash so espera pelos filhos, nao espera pelos netos, sendo assim aparece o prompt ainda antes
do processo neto terminar

se quisermos que a bash nao espere pelo filho, usamos o '&' para correr em background, like ./fork3 &

execl(Path do que executar, argv[0], argv[1], ..., NULL);
execl("./child", "./child", "ola", "123",  NULL);
        PATH     argv[0] argv[1]  argv[2]



*/