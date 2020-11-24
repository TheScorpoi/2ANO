#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid());
    sleep(3);
    printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid());

    return EXIT_SUCCESS;
}
