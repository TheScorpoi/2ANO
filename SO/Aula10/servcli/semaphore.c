/**
 *  \file semaphore.c (implementation file)
 *
 *  \brief Semaphore management.
 *
 *  Operations defined on semaphores:
 *     \li creation of a set of semaphores
 *     \li connection to a previously created set of semaphores
 *     \li destruction of a previously created set of semaphores
 *     \li signalling start of operations
 *     \li <em>down</em> of a semaphore within the set
 *     \li <em>up</em> of a semaphore within the set.
 *
 *  \author António Rui Borges
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

/** \brief access permission: user r-w */
#define  MASK           0600

/**
 *  \brief Creation of a set of semaphores.
 *
 *  All semaphores in the set will be in set to <em>red state</em> upon creation.
 *  The function fails if there is already a semaphore set with a creation key equal to <tt>key</tt>.
 *
 *  \param key creation key
 *  \param snum number of semaphores in the set (>= 1)
 *
 *  \return set identifier, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int semCreate (int key, unsigned int snum)
{
    return semget ((key_t) key, snum+1, MASK | IPC_CREAT | IPC_EXCL);
}

/**
 *  \brief Connection to a previously created set of semaphores.
 *
 *  The function fails if there is no semaphore set with a creation key equal to <tt>key</tt>.
 *
 *  \param key creation key
 *
 *  \return set identifier, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int semConnect (int key)
{
    int semgid;                                                                            /* semaphore set identifier */
    struct sembuf init[2] = {{ 0, -1, 0 }, {0, 1, 0}};                                     /* initialization operation */

    if ((semgid = semget ((key_t) key, 1, MASK)) == -1)
        return -1;
    else if (semop (semgid, init, 2) == -1)
             return -1;
         else return semgid;
}

/**
 *  \brief Destruction of a previously created set of semaphores.
 *
 *  The function fails if there is no semaphore set with an identifier equal to <tt>semgid</tt>.
 *
 *  \param semgid set identifier
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int semDestroy (int semgid)
{
    return semctl (semgid, 0, IPC_RMID, NULL);
}

/**
 *  \brief Signalling start of operations upon initialization of shared data structures.
 *
 *  The function fails if there is no semaphore set with an identifier equal to <tt>semgid</tt>.
 *
 *  \param semgid set identifier
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int semSignal (int semgid)
{
    struct sembuf up = { 0, 1, 0 };                                                         /* all around up operation */

    return semop (semgid, &up, 1);
}

/**
 *  \brief <em>Down</em> of a semaphore within the set.
 *
 *  The function fails if there is no semaphore set with an identifier equal to <tt>semgid</tt>.
 *
 *  \param semgid set identifier
 *  \param sindex semaphore location in the set (1 .. snum)
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int semDown (int semgid, unsigned int sindex)
{
    struct sembuf down = { 0, -1, 0 };                                                      /* specific down operation */

    down.sem_num = (unsigned short) sindex;
    return semop (semgid, &down, 1);
}

/**
 *  \brief <em>Up</em> of a semaphore within the set.
 *
 *  The function fails if there is no semaphore set with an identifier equal to <tt>semgid</tt>.
 *
 *  \param semgid set identifier
 *  \param sindex semaphore location in the set (1 .. snum)
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int semUp (int semgid, unsigned int sindex)
{
    struct sembuf up = { 0, 1, 0 };                                                           /* specific up operation */

    up.sem_num = (unsigned short) sindex;

    return semop (semgid, &up, 1);
}
