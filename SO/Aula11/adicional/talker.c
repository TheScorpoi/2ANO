#include "../base/comm.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
    /* Creating communication channel */
    servOpenComm();

    /* the service */
    MESSAGE msg;
    while(1) {
        /* getting first message from queue, blocking if necessary */ 
        printf("\n[client \'%d\'] Message to be sent: ", getpid());
        fgets(msg.data, MSG_MAX, stdin);
        msg.size = strlen(msg.data)+1;

        /* sending converted message */
        servSend(&msg);
    }
    return 0;
}
