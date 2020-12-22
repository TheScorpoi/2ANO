/**
 *  \file semaphore.h (interface file)
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

#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

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

extern int semCreate (int key, unsigned int snum);

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

extern int semConnect (int key);

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

extern int semDestroy (int semgid);

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

extern int semSignal (int semgid);

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

extern int semDown (int semgid, unsigned int sindex);

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

extern int semUp (int semgid, unsigned int sindex);

#endif /* SEMAPHORE_H_ */
