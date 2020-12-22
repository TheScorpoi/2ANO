/**
 * Nome    : server.c
 * Função  : servidor conversor de string para maisculas
 * Autores : Artur Pereira e José Luís Oliveira
 * Email   : {artur, jlo}@ua.pt
 */

#include "comm.h"

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    MESSAGE msg;
    int i;
    int cnt = 0;

    /* abre o canal de comunicação */
    servOpenComm();

    /* atendimento */
    while (1) { 
        /* le primeira mensagem da fila */
        servReceive(&msg);
 
        /* converte mensagem para maisculas */
        for (i = 0; i < msg.size; i++)
            msg.data[i] = toupper(msg.data[i]);
 
        /* envia de volta a mensagem processada */
        printf("String %d ", ++cnt); fflush(stdout);
        servSend(&msg);
        printf("processado.\n");
    }
 
    /* fecha o canal de comunicacao */
    servCloseComm();

    return 0;
}

