#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LINEMAXSIZE 100
#define size(x) sizeof(x) / sizeof(x[0])

void writeFile(char *file)
{
    FILE *fp = fopen(file, "r");
    char line[LINEMAXSIZE];
    char arr[LINEMAXSIZE];

    if (fp == NULL)
    {
        perror("Error - File not found\n");
    }

    FILE *fp2 = fopen("teste.txt", "w");

    int j = 100;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        fprintf(fp2, "%d -> %s", j, line);
        j++;
    }
}

void writeTerminal1(char *file)
{
    int i = 0;

    FILE *fp = fopen("file.txt", "r"); //abrir o ficheiro
    char line[LINEMAXSIZE];            //criar array com o tamanho pre-definido

    // try/catch da wish
    if (fp == NULL)
    {
        perror("Error - File not found\n");
        //return EXIT_FAILURE; COMO É UMA FUNCAO VOID NAO POSSO RETURNAR NADA
    }

    //enq a linha for diferente de NULL, está a ler linhas
    printf("Imprimir a linha mas com valor max de char por linha pre-definido");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%d -> %s", i, line);
        i++;
    }
    printf("\n\n");
}

void writeTerminal2(char *file)
{
    //esta função implementa uma maneira, mais genérica sendo neste caso melhor
    // porem mais **complexa**
    FILE *fp2 = fopen("file.txt", "r");
    char line2[LINEMAXSIZE];

    if (fp2 == NULL)
    {
        perror("Error - File not found\n");
        //eturn EXIT_FAILURE; COMO ÉUMA FUNÇÃO VOID NAO POSSO RETURNAR NADA
    }

    printf("Maneira para só mudar de linha qd encontrar a mudança de linha");
    int fullLine = 1, j = 1;
    while (fgets(line2, sizeof(line2), fp2) != NULL)
    {
        if (fullLine)
        {
            printf("2%d -> ", j);
            fullLine = 0;
        }
        if (line2[strlen(line2) - 1] == '\n')
        {
            fullLine = 1;
            j++;
        }
        printf("%s", line2);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    //* writeFile(<fileName>) é uma função que recebe como argumento
    //* o nome de um ficheiro que irá ler, a informação desse file
    //* será guardada num array de char, neste caso chamada line
    //* a estrutura da leitura é igual ao código que é feito na main
    //* posteriormente cria-se um novo ficheiro, para gravar a
    //* o que foi lido do ficheiro passado como argumento

    //* Primeiramente isto foi tudo feito na main, mas vou criar
    //* as funções writeTerminal1(<filneName>) e writeTerminal2(<fileName>)
    //* só para ganhar algo calo com funções, visto que estou bastante perro
    //* nesta situação toda...

    writeFile("file.txt");
    writeTerminal1("file.txt");
    writeTerminal2("file.txt");
}
