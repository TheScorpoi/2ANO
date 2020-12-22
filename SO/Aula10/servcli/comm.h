/**
 * Name      : comm.h
 * Function  : Prototype of comm functions for a client-server app.
 * Author    : Artur Pereira <artur@ua.pt>
 */

#ifndef _COMM_H_
#define _COMM_H_

#define MSG_MAX  256    /* tamanho máximo da mensagem */

/**
 * message definition
 */

typedef struct message
{
    unsigned int size;  /* message size */
    char data[MSG_MAX]; /* message data */
} MESSAGE;

/* Open communication - server side */
void servOpenComm(void);

/* Close communication - server side */
void servCloseComm(void);

/* Send message - server side */
void servSend(MESSAGE *m);

/* Receive message - server side */
void servReceive(MESSAGE *m);

/* Open communication - client side */
void cliOpenComm(void);

/* Close communication - client side */
void cliCloseComm(void);

/* Send message - client side */
void cliSend(MESSAGE *m);

/* Receive message - client side */
void cliReceive(MESSAGE *m);

#endif
