#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;

    if (argc != 2)
    {
        printf("Número errado de argumentos (%d)\n", argc);
        return EXIT_FAILURE;
    }

    for(i = 0 ; i < argc ; i++)
    {
        printf("Argument %02d: \"%s\"\n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}
