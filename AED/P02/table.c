//
// Tomás Oliveira e Silva, AED, September 2020
//
// program to print a table of the squares and square roots of some integers
//
// on GNU/Linux, run the command
//   man 3 printf
// to see the manual page of the printf function
//

#include <math.h>
#include <stdio.h>

void do_it(int N)
{
  int i;

  printf(" n n*n      sqrt(n)\n");
  printf("-- --- -----------------\n");
  for(i = 1;i <= N;i++)
    printf("%2d %3d %17.15f\n",i,i * i,sqrt((double)i));

  FILE *fp = fopen("table.txt", "w");
  fprintf(fp,"%2s %2s\n","Sin(n)", "Cos(n)");

  for (i = 0; i < 90; i++)
  {
    fprintf(fp, "%2.1f %7.1f\n",sin(i * (M_PI/180.0)), cos(i * (M_PI/180.0)));
  }
  fclose(fp);
  
}

int main(void)
{
  do_it(10);
  return 0;
}
