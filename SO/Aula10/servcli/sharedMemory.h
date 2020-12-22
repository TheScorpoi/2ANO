/**
 *  \file sharedMemory.h (interface file)
 *
 *  \brief Shared memory management.
 *
 *   Operations defined on shared memory:
 *      \li creation of a new block
 *      \li connection to a previously created block
 *      \li destruction of a previously created block
 *      \li mapping of the block previously created on the process address space
 *      \li unmapping of the block off the process address space.
 *
 *  \author António Rui Borges 
 */

#ifndef SHAREDMEMORY_H_
#define SHAREDMEMORY_H_

/**
 *  \brief Creation of a new block.
 *
 *  The function fails if there is already a block of shared memory with a creation key equal to <tt>key</tt>.
 *
 *  \param key creation key
 *  \param size block size (in bytes)
 *
 *  \return block identifier, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

extern int shmemCreate (int key, unsigned int size);

/**
 *  \brief Connection to a previously created block.
 *
 *  The function fails if there is no block with a creation key equal to <tt>key</tt>.
 *
 *  \param key creation key
 *
 *  \return block identifier, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

extern int shmemConnect (int key);

/**
 *  \brief Destruction of a previously created block.
 *
 *  The function fails if there is no block with an identifier equal to <tt>shmid</tt>.
 *
 *  \param shmid block identifier
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

extern int shmemDestroy (int shmid);

/**
 *  \brief Mapping of the block previously created on the process address space.
 *
 *  The function fails if there is no block with an identifier equal to <tt>shmid</tt>.
 *
 *  \param shmid block identifier
 *  \param pAttAdd pointer to the location where the local address of the attached block is stored
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

extern int shmemAttach (int shmid, void **pAttAdd);

/**
 *  \brief Unmapping of the block off the process address space.
 *
 *  The function fails if the pointer does not locate a region of the address space
 *  where a mapping took previously place.
 *
 *  \param attAdd local address of the attached block
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

extern int shmemDettach (void *attAdd);

#endif /* SHAREDMEMORY_H_ */
