/**
 *  \file prodcon.c (implementation file)
 *
 *  \brief Problem name: Producers-Consumers.
 *
 *  Synchronization based on monitors.
 *  Both threads and the monitor are implemented using the pthread library which enables the creation of a
 *  monitor of the Lampson / Redell type.
 *
 *  Generator thread of the intervening entities.
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <libgen.h>
#include  <unistd.h>
#include  <sys/wait.h>
#include  <sys/types.h>
#include  <pthread.h>
#include  <math.h>

#include  "fifo.h"

#define USAGE "Synopsis: %s [options]\n"\
    "\t----------+--------------------------------------------\n"\
    "\t  Option  |          Description                       \n"\
    "\t----------+--------------------------------------------\n"\
    "\t -i num   | number of iterations (<= 100)              \n"\
    "\t -t num   | number of 'threads' (<= 300)               \n"\
    "\t -h       | this help                                  \n"\
    "\t----------+--------------------------------------------\n"

/* communication data structure with producer and consumer threads */
typedef struct
        { 
            int id;                                                                         /* thread identification */
            int niter;                                                                       /* number of iterations */
        } THREAD_PAR;

/*   allusion to internal function */
static void *producer (void *arg);
static void *consumer (void *arg);

/* producer and consumer thread return status pointer array */
static int (*statusPO_p)[],
           (*statusCO_p)[];

/*   main thread: it starts the simulation and generates the producer and consumer threads
 */
int main (int argc, char *argv[])
{
    int niter = 10;                                                                 /* number of iterations by default */
    int nthr = 4;                                                /* number of producer and consumer threads by default */

    /* command line processing */
    const char *optstr = "i:t:h";                                                                   /* allowed options */
    int option;                                                                                       /* parsed option */

    do {
        switch ((option = getopt (argc, argv, optstr))) {
          case 'i': niter = atoi (optarg);
                    if (niter > 100) {
                        fprintf (stderr, "Too many iterations!\n");
                        fprintf (stderr, USAGE, basename (argv[0]));
                        return EXIT_FAILURE;
                    }
                    break;
          case 't': nthr = atoi (optarg);
                    if (nthr > 300) {
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

    /* launching the 'pthreads' */
    pthread_t thr[2*nthr];                                      /* identification of the producer and consumer threads */
    THREAD_PAR thrp[2*nthr];                                                                /* parameter communication */
    int i;                                                                                        /* counting variable */
    int statusPO[nthr],                                                                /* producer return status array */
        statusCO[nthr];                                                                      /* consumer return status */
    int *status_p;                                                               /* pointer to thread execution status */

    printf ("Launching %d consumer threads, each performing %d iterations\n", nthr, niter);
    statusCO_p = &statusCO;
    for (i = 0; i < nthr; i++) {
        thrp[nthr+i].id = i;
        thrp[nthr+i].niter = niter;
        if (pthread_create (thr+nthr+i, NULL, consumer, &thrp[nthr+i]) != 0) {
            fprintf (stderr, "consumer %d\n", i);
             perror ("error on launching the consumer thread");
             return EXIT_FAILURE;
         }
    }
    printf ("Launching %d producer threads, each performing %d iterations\n", nthr, niter);
    statusPO_p = &statusPO;
    for (i = 0; i < nthr; i++) {
        thrp[i].id = i;
        thrp[i].niter = niter;
        if (pthread_create (thr+i, NULL, producer, &thrp[i]) != 0) {
            fprintf (stderr, "producer %d\n", i);
            perror ("error on launching the producer thread");
            return EXIT_FAILURE;
        }
    }

    /* wait for threads to conclude */
    for (i = 0; i < nthr; i++) {
        if (pthread_join (thr[i], (void **) &status_p) != 0) {
            fprintf (stderr, "producer %d\n", i);
            perror ("error on waiting for a thread to conclude");
            return EXIT_FAILURE;
        }
        printf ("Producer thread %d has terminated: its status was %d\n", i, *status_p);
    }
    for (i = 0; i < nthr; i++) {
        if (pthread_join (thr[nthr+i], (void **) &status_p) != 0) {
            fprintf (stderr, "consumer %d\n", i);
            perror ("error on waiting for a thread to conclude");
            return EXIT_FAILURE;
        }
        printf ("Consumer thread %d has terminated: its status was %d\n", i, *status_p);
    }

    return EXIT_SUCCESS;
}

/*
 * producer thread
 */

void *producer (void *val_p)
{
    int id = ((THREAD_PAR *) val_p)->id;                                                     /* thread identification */
    int niter = ((THREAD_PAR *) val_p)->niter;                                                /* number of iterations */
    int i;                                                                                       /* counting variable */

    srandom ((unsigned int) pthread_self ());
    for (i = 0; i < niter; i++) {
        usleep ((unsigned int) floor (1 + 10000.0 * random () / RAND_MAX));
        if (((*statusPO_p)[id] = fifoIn (10000*id+i+1)) != 0) {
            fprintf (stderr, "producer %d\n", id);
            perror ("error on inserting a value into the FIFO");
            pthread_exit (&(*statusPO_p)[id]);
        }
    }
 
    (*statusPO_p)[id] = EXIT_SUCCESS;
    pthread_exit (&(*statusPO_p)[id]);
}

/*
 * consumer thread
 */

void *consumer (void *val_p)
{
    int id = ((THREAD_PAR *) val_p)->id;                                                     /* thread identification */
    int niter = ((THREAD_PAR *) val_p)->niter;                                                /* number of iterations */
    unsigned int value;                                                                            /* retrieved value */
    int i;                                                                                       /* counting variable */

    srandom ((unsigned int) pthread_self ());
    for (i = 0; i < niter; i++) {
        usleep ((unsigned int) floor (1 + 10000.0 * random () / RAND_MAX));
        if (((*statusCO_p)[id] = fifoOut (&value)) != 0) {
            fprintf (stderr, "consumer %d\n", id);
            perror ("error on retrieving a value from the FIFO");
            pthread_exit (&(*statusCO_p)[id]);
        }
        printf ("The value %u was produced by thread P%u and consumed by thread C%u!\n",
                value%10000, value/10000, (unsigned int) id);
    }
 
    (*statusCO_p)[id] = EXIT_SUCCESS;
    pthread_exit (&(*statusCO_p)[id]);
}
