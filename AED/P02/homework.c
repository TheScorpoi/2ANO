#include <stdio.h>
#include <stdlib.h>

int valueinarray(int val, int arr[]){

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == val) {
            return 1;
        }
        return 0;
    }
}

int main(int argc, char const *argv[])
{   
    int n[10];  //decidi meter o número num array, para poder fazer a validação se so ter um numero repetido
    
    for (int i = 0; i < sizeof(n); i++) {
        int n_rand = rand()*10;
        if (valueinarray(n_rand, n[i]) == 0) {
            n[i] = n_rand;
        }
    }
    
    return (0);
}

