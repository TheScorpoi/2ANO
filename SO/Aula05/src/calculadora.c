#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{   
    //o numero de args tem de ser 4 pq ao correr ./calculadora, isto 
    //também conta como um argumento

    double value1, value2;

    //validação do nº de args
    if (argc != 4)
    {
        printf("Número de argumentos ERRADO (%d)\n", argc);
    }

    //colocar os args em variáves
    // atof converte uma string para um double (tipo ParseDouble em java)
    //value1 = atof(argv[1]);
    //value2 = atof(argv[3]);
    char op = *argv[2];

    
    char *pc;
    value1 = strtod(argv[1], &pc);
    value2 = strtod(argv[3], &pc);
    
    switch (op)
    {
    case '+':
        printf("%4.1f \n",value1 + value2);
        break;
    case '-':
        printf("%4.1f \n",value1 - value2);
        break;
    case 'x':
        printf("%4.1f \n",value1 * value2);
        break;
    case '/':
        printf("%4.1f \n",value1 / value2);
        break;
    case 'p':
        printf("%4.1f \n",pow(value1,value2));
        break;
    default:
        printf("Argumentos inválidos...\n");
    }

    return 0;
}
