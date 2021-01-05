#include "../base/comm.h"

#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void)
{
    /* Creating communication channel */
    servOpenComm();

    /* the service */
    MESSAGE msg;
    while(1) {
        /* getting response */
        cliReceive(&msg);

        /* printing received message */
        printf("Message received: %s", msg.data);

    }
    return 0;
}
