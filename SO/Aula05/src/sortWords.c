#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size(x) sizeof(x) / sizeof(x[0])


// função para comparar as string por ordem alfabética
int myCompare(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

//! Falta a parte da ordem da ordenação ns que da BASH

int main(int argc, char const *argv[])
{
    char *arr[argc - 1];

    for (size_t i = 0; i < argc - 1; i++)
    {
        arr[i] = (char *)malloc(15);
        arr[i] = argv[i + 1];
    }

    puts("\nNão Ordenado\n");
    for (int n = 0; n < size(arr); n++)
    {
        puts(arr[n]);
    }

    qsort(arr, size(arr), sizeof(arr[0]), myCompare);

    puts("\nOrdenado");
    for (int n = 0; n < size(arr); n++)
    {
        puts(arr[n]);
    }

    return 0;
}
