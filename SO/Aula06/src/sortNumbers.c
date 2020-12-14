#include <stdio.h>
#include <stdlib.h>

#define size(x) sizeof(x) / sizeof(x[0])

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return (x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

//! MEU DEUS ISTO ESTÁ TUDO FODIDO
//! CARALHO FODA O HOMEM, N FAZ CÓDIGO NO PC, TUDO À MAO PUTA DE CONFUSÃO E O CRLH FDS

int main(int argc, char *argv[])
{
    int tmp[100];

    FILE *ftmp = NULL;
    ftmp = fopen(argv[1], "r");

    int NUM = 0;
    while (fscanf(ftmp, "%d", tmp + 1) == 1)
    {
    NUM++;
    }
    fclose(ftmp);

    int numbers[NUM];

    FILE *fp = NULL;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    // com o fscanf()
    int i = 0;     //*onde esta '&numbers[i]' também dá com 'numbers + i'
    while (fscanf(fp, "%d", &numbers[i]) == 1)
    {
        i++;
    }

    /* desta maneira ao printar vai aparecer mais um valor, suponho q seja o &memoria do array q tem a ultima linha do ficheiro
    int i = 0;
    while (fgets(numbers, sizeof(numbers), fp) != NULL)
    {
        numbers[i] = atoi(numbers);
        i++;
    }
    */

    qsort(numbers, size(numbers), sizeof(numbers[0]), compareInts);

    //printar os números ordenados
    for (int i = 0; i < size(numbers); i++)
    {
        printf("%d\n", numbers[i]);
    }

    fclose(fp);
    /* Alinea a)
    int i, numSize;
    int *numbers;
    numSize = argc - 1;
    //Memory allocation for all the numbers in the arguments 
    numbers = (int *) malloc(sizeof(int) * numSize);
    //Storing the arguments in the "array" numbers 
    for(i = 0 ; i < numSize ; i++)
    {
        numbers[i] = atoi(argv[i+1]);
    }
    //void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
    // The qsort() function sorts an array with nmemb elements of size size.
    qsort(numbers, numSize, sizeof(int), compareInts);
    //Printing the sorted numbers 
    printf("Sorted numbers: \n");
    for(i = 0 ; i < numSize ; i++)
    {
        printf("%d\n", numbers[i]);
    }*/
    return EXIT_SUCCESS;
}
