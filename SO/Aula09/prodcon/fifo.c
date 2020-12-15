/**
 *  \file fifo.c (implementation file)
 *
 *  \brief Problem name: Producers-Consumers.
 *
 *  Synchronization based on monitors.
 *  Both threads and the monitor are implemented using the pthread library which enables the creation of a
 *  monitor of the Lampson / Redell type.
 *
 *  Monitor FIFO.
 *
 *  The following operations are defined:
 *     \li insertion of a value
 *     \li retrieval of a value.
 */

#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <errno.h>

/** \brief internal storage size of <em>FIFO memory</em> */
#define  M         2

/**
 *  \brief Definition of <em>FIFO memory</em> data type.
 */
typedef struct
        { /** \brief storage region for spectators/betters identification */
          unsigned int mem[M];
          /** \brief insertion pointer */
          unsigned int ii;
          /** \brief retrieval pointer */
          unsigned int ri;
          /** \brief flag signaling that FIFO is full */
          bool full;
        } FIFO;

/** \brief internal storage region of FIFO type */
static FIFO f;

/** \brief locking flag which warrants mutual exclusion inside the monitor */
static pthread_mutex_t accessCR = PTHREAD_MUTEX_INITIALIZER;

/** \brief FIFO is full synchronization point */
static pthread_cond_t fifoFULL = PTHREAD_COND_INITIALIZER;

/** \brief FIFO is empty synchronization point */
static pthread_cond_t fifoEMPTY = PTHREAD_COND_INITIALIZER;

/** \brief signalling flag which warrants internal data is initialized exactly once */
static pthread_once_t init = PTHREAD_ONCE_INIT;

/**
 *  \brief FIFO initialization (Internal monitor operation).
 *
 *         FIFO will be empty after it.
 *
 *  \param p_f pointer to the location where the FIFO is stored
 */

static void fifoInit (void)
{
    f.ii = f.ri = 0;
    f.full = false;
}

/**
 *  \brief Insertion of a value into the FIFO.
 *
 *  \param val value to be stored
 *
 *  \return status of operation (0 - success; -1 - error)
 */

int fifoIn (unsigned int val)
{
    int stat;                                                                                  /* status of operation */

    if ((stat = pthread_mutex_lock (&accessCR)) != 0) {                                              /* enter monitor */
        errno = stat;                                                                         /* save error condition */
        return stat;
    }
    pthread_once (&init, fifoInit);                                                   /* internal data initialization */

    while (f.full) {                                                                         /* check if FIFO is full */
        if ((stat = pthread_cond_wait (&fifoFULL, &accessCR)) != 0) {  /* wait for available space to store the value */
            errno = stat;                                                                     /* save error condition */
            return stat;
        }
    }

    f.mem[f.ii] = val;                                                                             /* store the value */
    f.ii = (f.ii + 1) % M;
    f.full = (f.ii == f.ri);

    if ((stat = pthread_cond_signal (&fifoEMPTY)) != 0) {           /* signal some consumer that a value is available */
        errno = stat;                                                                         /* save error condition */
        return stat;
    }

    if ((stat = pthread_mutex_unlock (&accessCR)) != 0) {                                             /* exit monitor */
        errno = stat;                                                                         /* save error condition */
        return stat;
    }

    return 0;
}

/**
 *  \brief Retrieval of a value from the FIFO.
 *
 *  \param p_val pointer to the location where the retrieved value is to be stored
 *
 *  \return status of operation (0 - success; -1 - error)
 */

int fifoOut (unsigned int *p_val)
{
    int stat;                                                                                  /* status of operation */

    if ((stat = pthread_mutex_lock (&accessCR)) != 0) {                                              /* enter monitor */
        errno = stat;                                                                         /* save error condition */
        return stat;
    }
    pthread_once (&init, fifoInit);                                                   /* internal data initialization */

    while (!(f.full) && (f.ii == f.ri)) {                                                   /* check if FIFO is empty */
        if ((stat = pthread_cond_wait (&fifoEMPTY, &accessCR)) != 0) {            /* wait for a value to be available */
            errno = stat;                                                                     /* save error condition */
            return stat;
        }
    }

    *p_val = f.mem[f.ri];                                                                         /* retrieve a value */
    f.ri = (f.ri + 1) % M;
    f.full = false;

    if ((stat = pthread_cond_signal (&fifoFULL)) != 0) {              /* signal some producer that space is available */
        errno = stat;                                                                         /* save error condition */
        return stat;
    }

    if ((stat = pthread_mutex_unlock (&accessCR)) != 0) {                                             /* exit monitor */
        errno = stat;                                                                         /* save error condition */
        return stat;
    }

    return 0;
}
