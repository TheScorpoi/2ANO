#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char const *argv[])
{
    double value1, value2;

    if (argc != 4)
    {
        printf("Introduza um número de argumentos válidos");
        return EXIT_FAILURE;
    }


    value1 = atof(argv[1]);
    value2 = atof(argv[3]);
    char op = *argv[2];

    switch (op)
    {
    case '+':
        printf("Res: %2.2f\n", value1 + value2);
        break;
    case '-':
        printf("Res: %2.2f\n", value1 - value2);
        break;
    case 'x':
        printf("Res: %2.2f\n", value1 * value2);
        break;
    case '/':
        printf("Res: %2.2f\n", value1 / value2);
        break;
    case 'p':
        printf("Res: %2.2f\n",pow(value1,value2));
        break;
    default:
        printf("Introduz operações possíveis oh boi\n");
        break;
    }
}
