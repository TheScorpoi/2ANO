#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

void list(char *dr, int filter)
{
    DIR *d = opendir(dr);
    struct dirent *dent;
    if (d == NULL)
    {
        perror("Error opening directory");
    }

    dent = readdir(d);
    while (dent != NULL)
    {
        if (dent->d_name[0] != '.')
        {
            if (dent->d_type == filter)
            {
                printf("%s\n", dent->d_name);
            }
            else if (filter == 0)
            {
                printf("%s\n", dent->d_name);
            }
        }
        dent = readdir(d);
    }
}

int main(int argc, char *argv[argc])
{
    int opt, filter = 0;

    while ((opt = getopt(argc, argv, "f::d::e::")) != -1)
    {
        switch (opt)
        {
        case 'f':
            filter = 8;
            break;
        case 'd':
            filter = 4;
            break;
        case 'e':
            filter = 10;
            break;
        }
    }

    if (optind == argc)
    {
        printf("A listar conteúdo do diretório atual-------------------------------\n");
        list("./", filter);
    }
    else
    {
        for (; optind < argc; optind++)
        {
            printf("A listar conteúdo do diretório %s-------------------------------\n", argv[optind]);
            list(argv[optind], filter);
        }
    }
}