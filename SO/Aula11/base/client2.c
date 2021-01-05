/**
 * \brief the client
 * \author Artur Pereira <artur@ua.pt>
 */

#include "comm.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    MESSAGE msg;

    /* opening the communication channel */
    cliOpenComm();

    /* use the service */
    while(1) {
        /* asking user for a message */
        printf("\n[client \'%d\'] Message to be sent: ", getpid());
        fgets(msg.data, MSG_MAX, stdin);
        msg.size = strlen(msg.data)+1;

        /* sending messagee */
        cliSend(&msg);

        /* asking for authorization to get response  */
        printf("\e[33mPress ENTER to get response\e[0m ");
        scanf("%*[^\n]");
        scanf("%*c");

        /* getting response */
        cliReceive(&msg);

        /* printing received message */
        printf("Message received: %s", msg.data);
    }
    return 0;
}
