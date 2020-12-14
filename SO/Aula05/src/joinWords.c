#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{    
    //alternativa pelo fgets (mt mais simples)
    /*
    char frase[50];
    fgets(frase, sizeof(frase) / sizeof(frase[0]), stdin); // os 3 arg sao: 1- local onde é guardado o conteudo, 2- qts carateres le, 3- stdin para ler do teclado

    printf("%s\n", frase);
    */

   /*
    no array arg[], vamos guardar os argumentos introduzidos, atraves de um for
    num outro for, vamos meter cada letra dentro do array sentence[]

   */

    //Alternativa pelo terminal
    char arg[100], sentence[100];
    int numchars = 0;

    for (int i = 1; i < argc; i++)
    {
        strcpy(arg, argv[i]);
    
        for (int j = 0; j < strlen(arg); j++)
        {
            sentence[numchars] = arg[j];
            numchars++;
        }
    }
    printf("FRASE: %s\n", sentence);
    
    return 0;
}
