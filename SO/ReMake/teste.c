#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
    int opt;
    //char *extension;

    DIR *dp;
    struct dirent *dent;

    while ((opt = getopt(argc, argv, "dfe:")) != -1)
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
                /*case 'e':
                    extension = optarg;
                    break;*/
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