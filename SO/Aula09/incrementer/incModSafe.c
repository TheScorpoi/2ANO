/**
 * A simple monitor (implementation file).
 *
 * (c) 2004 Artur Pereira <artur@ua.pt>
 *
 * A very simple monitor, with an internal data structure and 3 manipulation functions.
 * The internal data structure is just a single integer variable.
 * The 3 manipulation functions are meant to:
 * - set the variable value;
 * - get the variable value;
 * - increment by one the variable value.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <math.h>

/* time delay length */
#define  BIG         5000
#define  SMALL          0

/* generate time delay */
void delay (int nite) {
    int i;
    double b = 0.0;
    double c = 0.0;
    double PI = 3.141516;

    for (i = 0; i < nite; i++) { 
        b = cos (c + PI/4);
        c = sqrt (fabs (b));
    }
}

/* thread return status */

extern int status;

/* internal data structure */
static int value = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* set the variable value */
void vSet (int new_value)
{
    /* lock mutex */
    if ((status = pthread_mutex_lock (&mutex)) != 0) {        /* enter monitor */ 
        errno = status;                                 /* save error in errno */
        perror ("error on entering the monitor");
        status = EXIT_FAILURE;
        pthread_exit (&status);
    }

    value = new_value;

    /* unlock mutex */
    if ((status = pthread_mutex_unlock (&mutex)) != 0) {       /* exit monitor */
        errno = status;                                 /* save error in errno */
        perror ("error on exiting monitor");
        status = EXIT_FAILURE;
        pthread_exit (&status);
    }
}

/* get the variable value */
int vGet (void)
{
    /* lock mutex */
    if ((status = pthread_mutex_lock (&mutex)) != 0) {        /* enter monitor */
        errno = status;                                 /* save error in errno */
        perror ("error on entering the monitor");
        status = EXIT_FAILURE;
        pthread_exit (&status);
    }

    int val;

    val = value;

    /* unlock mutex */
    if ((status = pthread_mutex_unlock (&mutex)) != 0) {       /* exit monitor */
        errno = status;                                 /* save error in errno */
        perror ("error on exiting monitor");
        status = EXIT_FAILURE;
        pthread_exit (&status);
    }

    return val;
}

/* increment the variable value */
void vInc (void)
{
    int val;

    /* lock mutex */
    if ((status = pthread_mutex_lock (&mutex)) != 0) {        /* enter monitor */
        errno = status;                                 /* save error in errno */
        perror ("error on entering the monitor");
        status = EXIT_FAILURE;
        pthread_exit (&status);
    }

    /* load locally the stored value */
    val = value;

    /* generate time delay 1 */
    delay (BIG);

    /* increment the local value and store it back */
    value = val + 1;

    /* unlock mutex */
    if ((status = pthread_mutex_unlock (&mutex)) != 0) {       /* exit monitor */
        errno = status;                                 /* save error in errno */
        perror ("error on exiting monitor");
        status = EXIT_FAILURE;
        pthread_exit (&status);
    }

    /* generate time delay 2 */
    delay (BIG);

}
