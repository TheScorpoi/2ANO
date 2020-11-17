#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p = {35, 1.65, "xpto"};

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    int nPessoas = 0;
    printf("Quantas pessoas são para guardar? \n");
    scanf("%d", &nPessoas);
    //scanf("%*c"); //lê e descarta um carater ou ent por um espaço antes do '%' descarta um white space

    for (int i = 0; i < nPessoas; i++)
    {
        printf("Nome?\n");
        scanf(" %63[^\n]", p.name); //scanf(" %63[^\n]"); o 63 pq no maximo pode ler 63 carateres pois name[64]
        printf("Idade?\n");
        scanf(" %d", &p.age);
        printf("Altura?\n");
        scanf(" %lf", &p.height);
        fwrite(&p, sizeof(Person), 1, fp);
    }

    // Write 10 itens on a file
    /*
    for (i = 0; i < 10; i++)
    {    
        p.age = p.age+1;
        p.height = p.height+0.03;
        fwrite(&p, sizeof(Person), 1, fp);
    }
    */

    fclose(fp);

    return EXIT_SUCCESS;
}
