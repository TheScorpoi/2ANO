//
// Tomás Oliveira e Silva, AED, September 2020
//
// list all command line arguments
//

#include <stdio.h>

int main(int argc,char *argv[argc])
{
  for(int i = 0;i < argc;i++)
    printf("argv[%2d] = \"%s\"\n",i,argv[i]);
  return 0;
}
