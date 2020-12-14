#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int opt, min, max, nValue = 0, xValue = 0;
    while ((opt = getopt(argc, argv, "n:x:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            min = atoi(optarg);
            nValue = 1;
            break;
        case 'x':
            max = atoi(optarg);
            xValue = 1;
            break;
        default:
            printf("algo deu mal\n");
            break;
        }
    }
    for (size_t i = optind; i < argc; i++)
    {
        switch (nValue)
        {
        case 0:
            if (xValue == 1)
            {
                if (atoi(argv[i]) < max)
                {
                    printf("%d  ", atoi(argv[i]));
                }
            }
            break;
        case 1:
            if (xValue == 1)
            {
                if (atoi(argv[i]) < max && atoi(argv[i]) > min)
                {
                    printf("%d  ", atoi(argv[i]));
                }
            }
            if (xValue == 0)
            {
                if (atoi(argv[i]) > min)
                {
                    printf("%d  ", atoi(argv[i]));
                }
            }
            break;
        }
    }
    printf("\n");
    return 0;
}