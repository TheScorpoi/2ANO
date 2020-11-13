#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size(x) sizeof(x) / sizeof(x[0])


// função para comparar as string por ordem alfabética
int myCompare(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main()
{
    char *xs[5];
    
    for (size_t i = 0; i < size(xs); i++)
    {
        xs[i] = (char *)malloc(15); //alocate space for a string of maximum 14 chars
        scanf("%s", xs[i]); // fazer o scan da string
    }

    puts("\nNão Ordenado\n");
    for (int n = 0; n < size(xs); n++)
        puts(xs[n]);

    qsort(xs, size(xs), sizeof(xs[0]), myCompare);

    puts("\nOrdenado");
    for (int n = 0; n < size(xs); n++)
        puts(xs[n]);
}