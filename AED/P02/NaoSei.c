#include<stdio.h>

int main()
{
    // fazer arrays e printa-los
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d--", array[i]);
    }
    

    //fazer inputs aos user com int's
    char  str[100];
    printf("Enter a number: ");
    gets(str);
    puts(str);
    return 0;

    
}
