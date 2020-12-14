#include <stdio.h>
#include <stdlib.h>

#define size(x) sizeof(x) / sizeof(x[0])

int main(int argc, char const *argv[])
{
    int numbers[34];

    FILE *fp;
   fp = fopen(argv[1], "r");

    int i = 0;
    while (fscanf(fp, "%d", numbers + i) == 1) // same as &numbers[i]
    {
        i++;
    }

    for (size_t i = 0; i < size(numbers); i++)
    {
        printf("%d\n", *(numbers + i)); //same numbers[i]
    }

    return 0;
}
