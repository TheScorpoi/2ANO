#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p;
    Person people[100];
    int nPessoas = 0;

    /* Validate number of arguments */
    if (argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    while (fread(&p, sizeof(Person), 1, fp) == 1)
    {
        //adiciona ao array as pessoas que estao no ficheiro binario
        people[nPessoas] = p;
        nPessoas++;
    }

    /* outra maniera tb de ler para o array
    while(fread(&people[nPessoas], sizeof(Person), 1, fp) == 1)
    {
        nPessoas++;
    }
    */

    // outra maneira mais simples para ler e guardar no array, está 0 a nPessoas pois o fread retorna o numero de fezes
    //nPessoas = fread(people, sizeof(Person), 100, fp);

    fp = fopen(argv[1], "w");

    // Write 10 itens fixos, pq é estupido cada vez q dou run nisto pedir as cenas
    // este char names[] era para no print ter nomes diferente, questão de cortesia
    //char names[1000] = {"Manuel Silva", "António Santos", "João Costa", "Alberto Figueira", "Joaquim Sobreiro", "Alfredo Espinafre", "Ricardo Salsa", "Pedro Sobral", "Filipe Freixo", "Dani Figayredo"};
    for (int i = 0; i < 10; i++)
    {
        p.age = p.age + 1;
        p.height = p.height + 0.05;
        //strcpy(p.name, names[i]);

        fwrite(&p, sizeof(Person), 1, fp);

        people[nPessoas] = p;
        nPessoas++;
    }

    for (int i = 0; i < nPessoas; i++)
    {
        printPersonInfo(&people[i]);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
