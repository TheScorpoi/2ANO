/**
 *  \file fifo.h (interface file)
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

#ifndef FIFO_H_
#define FIFO_H_

/**
 *  \brief Insertion of a value into the FIFO.
 *
 *  \param val value to be stored
 *
 *  \return status of operation (0 - success; -1 - error)
 */

extern int fifoIn (unsigned int val);

/**
 *  \brief Retrieval of a value from the FIFO.
 *
 *  \param p_val pointer to the location where the retrieved value is to be stored
 *
 *  \return status of operation (0 - success; -1 - error)
 */

extern int fifoOut (unsigned int *p_val);

#endif /* FIFO_H_ */
