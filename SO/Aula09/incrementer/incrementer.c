/**
 * Incrementing a common integer variable with / without synchronization.
 * Thread implementation using primitives from the pthread library.
 *
 * Incrementing threads - inc = 0, 1, ... , N-1
 *
 * (c) 2004 Artur Pereira <artur@ua.pt>
 *
 *
 * Sintax: incrementer [options]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <pthread.h>

#include "incMod.h"

/* thread return status */
int status;

#define USAGE "Synopsis: %s [options]\n"\
    "\t----------+--------------------------------------------\n"\
    "\t  Option  |          Description                       \n"\
    "\t----------+--------------------------------------------\n"\
    "\t -i num   | number of increments                       \n"\
    "\t -t num   | number of 'threads' (<= 600)               \n"\
    "\t -h       | this help                                  \n"\
    "\t----------+--------------------------------------------\n"

/*   allusion to internal function */
static void *incrementer (void *arg);

/*   main thread: it starts the simulation and generates the incrementing threads
 */
int main (int argc, char *argv[])
{
    int niter = 1000;                                                                /* number of iterations by default */
    int nthr = 1;                                                                       /* number of threads by default */

    /* command line processing */
    const char *optstr = "i:t:h";                                                                    /* allowed options */
    int option;                                                                                        /* parsed option */

    do {
        switch ((option = getopt (argc, argv, optstr)))
        { 
          case 'i': niter = atoi (optarg);
                    break;
          case 't': nthr = atoi (optarg);
                    if (nthr > 600) {
                        fprintf (stderr, "Too many threads!\n");
                        fprintf (stderr, USAGE, basename (argv[0]));
                        return EXIT_FAILURE;
                    }
                    break;
          case 'h': printf (USAGE, basename(argv[0]));
                    return EXIT_SUCCESS;
          case -1:  break;
          default:  fprintf (stderr, "Non valid option!\n");
                    fprintf (stderr, USAGE, basename (argv[0]));
                    return EXIT_FAILURE;
        }
    } while (option >= 0);

    /* setting initial value of the common integer variable */
    vSet(0);

    /* launching the 'pthreads' */
    pthread_t thr[nthr];                                                             /* ids of the incrementing threads */
    int i;                                                                                         /* counting variable */
    int *status_p;                                                                /* pointer to thread execution status */

    printf ("Launching %d threads, each performing %d increments\n", nthr, niter);
    for (i = 0; i < nthr; i++) {
        if (pthread_create (thr+i, NULL, incrementer, &niter) != 0) {
            fprintf (stderr, "thread %d\n", i);
            perror ("error on launching the thread");
            return EXIT_FAILURE;
        }
    }

    /* wait for threads to conclude */
    for (i = 0; i < nthr; i++) { 
        if (pthread_join (thr[i], (void **) &status_p) != 0) {
            fprintf (stderr, "thread %d\n", i);
            perror ("error on waiting for a thread to conclude");
            return EXIT_FAILURE;
        }
        printf ("Thread %d has terminated: ", i);
        printf ("its status was %d\n", *status_p);
    }

    /* print variable value and quit */
    printf ("Final value = %d\n", vGet());

    return EXIT_SUCCESS;
}


/*
 * thread routine
 */
void *incrementer (void *arg)
{
    int i, n;

    n = *((int *) arg);
    for (i = 0; i < n; i++) {
        vInc ();
    }

    status = EXIT_SUCCESS;
    pthread_exit (&status);
}
