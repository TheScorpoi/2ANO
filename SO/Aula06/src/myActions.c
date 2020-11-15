#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man system
 man date
*/

//! NO command.log, os segundos sao sempre os mesmo...

int main(int argc, char *argv[])
{
    char text[128];
    FILE *fp = fopen("command.log", "a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    do
    {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        /* system(const char *command) executes a command specified in command
            by calling /bin/sh -c command, and returns after the command has been
            completed.
        */
        if (strcmp(text, "end"))
        {
            printf("\n * Command to be executed: %s\n", text);
            printf("---------------------------------\n");
            system(text);
            printf("---------------------------------\n");
            fprintf(fp, "Data: %d-%02d-%02d %02d:%02d:%02d || Comando: %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, text);
        }
    } while (strcmp(text, "end"));

    printf("---------------The End---------------\n");
    fclose(fp);
    return EXIT_SUCCESS;
}
