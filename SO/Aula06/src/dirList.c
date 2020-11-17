#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/

void listDir(char dirname[])
{
    DIR *dp;
    struct dirent *dent;

    dp = opendir(dirname);
    if (dp == NULL)
    {
        perror("Error opening directory");
        return;
    }

    dent = readdir(dp);
    while (dent != NULL)
    {
        if (dent->d_name[0] != '.') /* do not list hidden dirs/files */
        {
            if (dent->d_type == DT_DIR)
            {
                printf("d %s/%s\n", dirname, dent->d_name);

                //? Funciona mas não funciona... alguns dá outros dá 'Error opening directory'
                char str1[150];
                char str2[150];
                char sentence[150];
                int counter = 0;
                strcpy(str1, dirname);
                //printf("FRASE: %s\n", str1);
                strcpy(str2, dent->d_name);

                int i;
                for (i = 0; i < strlen(str1); i++)
                {
                    sentence[counter] = str1[i];
                    counter++;
                }

                sentence[counter++] = '/';
                for (i = 0; i < strlen(str2); i++)
                {
                    sentence[counter] = str2[i];
                    counter++;
                }
                listDir(sentence);
            }
            //! se for so um else e depois o print, dá na mesma
            else if (dent->d_type == DT_REG)
            {
                printf("  %s/%s\n", dirname, dent->d_name);
            }
                }
        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s base_directory\n", argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);

    return EXIT_SUCCESS;
}
