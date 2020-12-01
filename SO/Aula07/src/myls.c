#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
    int opt;

    DIR *dp;
    struct dirent *dent;

    dp = opendir(argv[1]);
    //validacao
    if (dp == NULL)
    {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    while ((opt = getopt(argc, argv, "dfe:")) != -1)
    {

        dent = readdir(dp);
        while (dent != NULL)
        {
            if (dent->d_name[0] != '.') /* do not list hidden dirs/files */
            {
                switch (opt)
                {
                case 'd':
                    if (dent->d_type == DT_DIR)
                    {
                        printf("%s/%s\n", argv[1], dent->d_name);
                    }

                    break;
                case 'f':
                    if (dent->d_type == DT_REG)
                    {
                        printf("%s/%s\n", argv[1], dent->d_name);
                    }
                    break;
                /*case 'e':
                    //! basicamente é so para mostrar os ficheiros que acabam em .ext
                    break;
                    */
                default: /* '?' */
                    fprintf(stderr, "Usage: %s \n",
                            argv[0]);
                    exit(EXIT_FAILURE);
                }
            }
            dent = readdir(dp);
        }

        if (optind >= argc + 1)
        {
            fprintf(stderr, "Expected argument after options\n");
            return EXIT_FAILURE;
        }
    }
    return 0;
}