#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N[5] = {100};
    int triangularNumbers[30];
    int sum = 0;
    int counter[30];

    //! MEUS FILHOS... JÁ NAO ESTOU É A ENTEDER NADA DISTO, VOU DEIXAR PODE SER QUE MAIS TARDE ALGO SE ILUMINE MILAGROSAMENTE NESTA PEQUENA MENTE DE ENGENHEIRO

    for (int i = 0; i < 1; i++) { //* Este for vai correr pelo número de elementos que o N tiver

        for (int k = 0; k < N[i]; k++) {
            
            float formula = k * (k + 1)/2;

            if (formula < N[i])
            {
                int j = 0;
                triangularNumbers[j] = formula;
                //printf("%d\n", triangularNumbers[j]);
            }

            //* estes dois for's são para somar as possibilidades todas de somas com os triangular numbers
            for (int i = 0; i < sizeof(triangularNumbers) / sizeof (triangularNumbers[0]) ; i++)
            {
                for (int j = 0; j < sizeof(triangularNumbers) / sizeof (triangularNumbers[0]) ; j++)
                {
                    sum = triangularNumbers[i] + triangularNumbers[j];
                    
                    //* neste for vamos ver se a soma é igual a algum trinagular numero, se sim o counter incrementa
                    for (int k = 0; k < sizeof(triangularNumbers) / sizeof (triangularNumbers[0]) ;  k++)
                    {
                        if (triangularNumbers[k] == sum )
                        {
                            for (int p = 0; p < sizeof(counter)/ sizeof(*counter); p++)
                            {
                                //* se o counter não tiver a sum, adiciona
                                if (counter[p] == sum)
                                {
                                    break;
                                } else
                                {
                                    counter[k] = sum;
                                }   
                            } 
                        }
                    }  
                }
            }
        }
    }

    //! ISTO ESTÁ TUDO FODIDO, pelo menos compila ahaha
    printf("%ld\n", sizeof(counter)/ sizeof(*counter));    


    return 0;
}