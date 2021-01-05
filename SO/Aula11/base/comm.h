/** \brief Client-server communication channel
  * \author    : Artur Pereira <artur@ua.pt>
  */
#ifndef _SO_IPC_COMM_H_
#define _SO_IPC_COMM_H_

#define MSG_MAX  512    /* maximum size allowed for a message */

/*
 * message definition
 */
typedef struct message
{
    unsigned int size;   /* actual message size */
    char data[MSG_MAX];  /* message data */
} MESSAGE;


/** \brief Open communication - server side 
  */
int servOpenComm(void);

/** \brief Close communication - server side 
  */
void servCloseComm(void);

/** \brief Send message - server side 
  */
void servSend(MESSAGE *m);

/** \brief Receive message - server side 
  */
void servReceive(MESSAGE *m);


/** \brief Open communication - client side 
  */
void cliOpenComm(void);

/** \brief Close communication - client side 
  */
void cliCloseComm(void);

/** \brief Send message - client side 
  */
void cliSend(MESSAGE *m);

/** \brief Receive message - client side 
  */
void cliReceive(MESSAGE *m);

#endif
