/**
 * Name      : comm-shm.c
 * Function  : Implementation of comm functions using shared memory and semaphores.
 * Author    : Artur Pereira <artur@ua.pt>
 */

#ifndef _SVID_SOURCE
#define _SVID_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>

#include "comm.h"
#include "sharedMemory.h"
#include "semaphore.h"

#define THEKEY 1111UL

enum {R = 1, S, A};

static int semid = -1;         /* semaphore id */
static int shmid = -1;         /* shared memory id */
static MESSAGE *buf = NULL;    /* message buffer */

/* up operation on a semaphore */
static void up(int semidx)
{
    if (semUp (semid, semidx) == -1) { 
        perror ("Fail doing an up to a semaphore");
        exit (EXIT_FAILURE);
    }
}

/* down operation on a semaphore */
static void down (int semidx)
{
    if (semDown (semid, semidx) == -1) { 
        perror ("Fail doing a down to a semaphore");
        exit (EXIT_FAILURE);
    }
}


/** Server side functions */

/* Open communication - server side */
void servOpenComm(void)
{
   bool first = false;

    /* create semaphore agregate */
    if ((semid = semCreate (THEKEY, 3)) == -1) { 
        if (errno == EEXIST) { 
            if ((semid = semConnect (THEKEY)) == -1) { 
                perror("Fail connecting to semaphore agregate");
                exit(EXIT_FAILURE);
            }
        }
        else { 
            perror("Fail creating semaphore agregate");
            exit(EXIT_FAILURE);
        }
    }
      else first = true;

    /* create shared memory */
    if ((shmid = shmemCreate (THEKEY, sizeof (MESSAGE))) == -1) { 
        if (errno == EEXIST) { 
            if ((shmid = shmemConnect (THEKEY)) == -1) { 
                perror("Fail connecting to shared memory");
                exit(EXIT_FAILURE);
            }
        }
        else { 
            perror("Fail creating shared memory");
            exit(EXIT_FAILURE);
        }
    }

    /* map shared memory into process memory space */
    if (shmemAttach (shmid, (void **) &buf) == -1) { 
        perror("Fail attaching to shared memory");
        exit(EXIT_FAILURE);
    }
    if (first) { 
        /* sinalização de início de operações */
        if (semSignal (semid) == -1) { 
            perror("Fail signaling start of operations");
            exit(EXIT_FAILURE);
        }

        /* allow for a service request */
        up(R);
    }
}

/* Close communication - server side */
void servCloseComm(void)
{
   /* detach shared memory from process memory space and destroy shared memory and semaphore agregate */
   if (shmemDettach (buf) == -1)
      { perror("Fail detaching from shared memory");
        exit(EXIT_FAILURE);
      }
   if (shmemDestroy (shmid) == -1)
      { perror ("Fail destroying shared memory");
        exit(EXIT_FAILURE);
      }
   if (semDestroy (semid) == -1)
      { perror ("Fail destroying semaphore agregate");
        exit(EXIT_FAILURE);
      }
}

/* Receive message - server side */
void servReceive(MESSAGE *msg)
{
   /* lock until a request is in buffer */
   down(S);

   /* get message */
   *msg = *buf;
}

/* Send message - server side */
void servSend(MESSAGE *msg)
{
   /* put message */
   *buf = *msg;

   /* the answer is ready */
   up(A);
}


/** Client side functions */

/* Open communication - client side */
void cliOpenComm(void)
{
   /* connect to semaphore agregate */
   if ((semid = semConnect (THEKEY)) == -1)
      { perror("Fail connecting semaphore agregate");
        exit(EXIT_FAILURE);
      }

   /* connect to shared memory */
   if ((shmid = shmemConnect (THEKEY)) == -1)
      { perror("Fail connecting to shared memory");
        exit(EXIT_FAILURE);
      }

   /* map shared memory into process memory space */
   if (shmemAttach (shmid, (void **) &buf) == -1)
      { perror("Fail attaching to shared memory");
        exit(EXIT_FAILURE);
      }
}

/* Close communication - client side */
void cliCloseComm(void)
{
   /* detach shared memory from process memory space */
   if (shmemDettach (buf) == -1)
      { perror("Fail detaching from shared memory");
        exit(EXIT_FAILURE);
      }
}

/* Send message - client side */
void cliSend(MESSAGE *msg)
{
   /* lock until a service request is possible */
   down(R);

   /* put message */
   *buf = *msg;

   /* notify server */
   up(S);
}

/* Receive message - client side */
void cliReceive(MESSAGE *msg)
{
   /* lock until the answer is ready */
   down(A);

   /* get message */
   *msg = *buf;

   /* open access for a new request */
   up(R);
}
