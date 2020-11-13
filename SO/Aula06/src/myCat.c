#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LINEMAXSIZE 141 // cada linha está suportada até 140 carateres

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line[LINEMAXSIZE];

    for (int i = 1; i < argc; i++)
    {
        errno = 0;
        fp = fopen(argv[1], "r");
        //validação do ficheiro
        if (fp == NULL)
        {
            perror("Error opening file!");
            return EXIT_FAILURE;
        }

        int j = 1;
        //* Para resolver o problema de alinea d), aumentei o LINEMAXSIZE
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            if (line[strlen(line) - 1] == '\n')
            {
                printf("%d-> %s", j, line); //not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file
                j++;
            }
        }
        printf("\n");
        //* Maneira que 'não gosto' da implementação
        //para fazer a alinea d) é usar o line[strlen(line) -1]
        /*
        int i = 1, fullline = 1;
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            if (fullline)
            {
                printf("%2d -> ", i);
                fullline = 0;
            }
            if (line[strlen(line) - 1] == '\n')
            {
                fullline = 1;
                i++;
            }

            printf("%s", line);
        }*/
    }
    fclose(fp);
    /*
    Código A--> alidate number of arguments
    if( argc != 2 )
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    //Open the file provided as argument 
    errno = 0;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }
    //Read all the lines of the file
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("-> %s", line); //not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file 
    }
    printf("\n");
    fclose(fp);
    */
    return EXIT_SUCCESS;
}