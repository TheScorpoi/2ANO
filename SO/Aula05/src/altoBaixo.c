#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

// a passagem de argumentos será:
// ./altoBaixo.c min max

int main(int argc, char const *argv[])
{
    printf("Bem Vindo ao Alto e Baixo!\nIntroduza uma tentativa:\n");

    int tentativa, nRandom, min, max, counter = 0;

    //validação do nº de argumentos
    if (argc != 3)
    {
        printf("Número de Argumentos Inválido (%d)\n", argc);
        return EXIT_FAILURE;
    }

    min = atoi(argv[1]);
    max = atoi(argv[2]);

    //validação do intervalo inserido
    if (min == max)
    {
        printf("Mínimo == Máximo: %d = %d\n", min, max);
        return EXIT_FAILURE;
    }
    else if (min > max)
    {
        printf("Min > Max: %d > %d\n", min, max);
        return EXIT_FAILURE;
    }

    //gerar numero random
    srand((unsigned)time(NULL));
    nRandom = min + rand() % (max - min);
    printf("NRANDOM: %d", nRandom);

    do
    {
        scanf("%d", &tentativa);
        counter++;

        if (tentativa > nRandom)
        {
            printf("Tentativa demasiado alta, tente outra vez! \n");
        }
        else if (tentativa < nRandom)
        {
            printf("Tentativa demasiado baixa, tente outra vez! \n");
        }
        else
        {
            printf("YOU WIN, with %d attempts\n", counter);
        }

    } while (tentativa != nRandom);

    return 0;
}