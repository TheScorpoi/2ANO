#include <stdio.h>
#include <stdlib.h>

#define size(x) sizeof(x) / sizeof(x[0])

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp = NULL)
    {
        perror("Error - File not Found");
        return EXIT_FAILURE;
    }

    //TODO: TOU COM SONO, PERGUNTAR AMANHA AO DANI SE FEZ
    

    return 0;
}
