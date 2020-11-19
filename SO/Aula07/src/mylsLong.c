#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <getopt.h>

int main(int argc, char const *argv[])
{
    int opt;
    int option_index = 0;
    char *extension;

    DIR *dp;
    struct dirent *dent;

    struct option long_options[] =
        {
            {"file", no_argument, 0, 'f'},
            {"dir", no_argument, 0, 'd'},
            {"ext", required_argument, 0, 'e'}

        };

    while ((opt = getopt_long(argc, argv, "fde:", long_options, &option_index)) != -1)
    {
        dp = opendir(argv[1]);
        if (dp == NULL)
        {
            perror("Error opening directory");
            return EXIT_FAILURE;
        }

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
                case 'e':
                    extension = optarg;
                    break;
                default: // '?' 
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