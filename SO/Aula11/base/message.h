/**
 * \brief message queue module
 * 
 * \details This module defines a set of operations to
 *   manage message queues.
 *   The following operations are defined:
 *   \li creation of a message queue
 *   \li connection to a previous created message queue
 *   \li destruction of message queue
 *   \li non blocking sending of a message
 *   \li blocking reception of a message
 *   \li non blocking reception of a message
 */

#include <stdbool.h>

/** 
 * \brief creation of a message queue
 * \param key the creation key
 * \return the queue id on success; -1 on error,, being errno set with the cause
 */
extern int msg_create (int key);


/** 
 * \brief connection to a previous created message queue
 * \param key the creation key
 * \return the queue id on success; -1 on error, being errno set with the cause
 */
extern int msg_connect (int key);


/**
 * \brief destruction of message queue
 * \param msgid queue id
 * \return 0 on success; -1 on error, being errno set with the cause
 */
extern int msg_destroy (int msgid);


/**
 * \brief non blocking sending of a message
 * \param msgid queue id
 * \param msg pointer to the message to be sent
 * \param size size of message in bytes
 * \return 0 on success; -1 on error, being errno set with the cause
 */
extern int msg_send_nb (int msgid, void * msg, int size);


/**
 * \brief non blocking reception of a message
 * \param msgid queue id
 * \param msg pointer to the message buffer
 * \param size size of message buffer in bytes
 * \param rec receiver id
 * \param status pointer to success on reception status
 * \return 0 on success; -1 on error, being errno set with the cause
 */
extern int msg_receive_nb (int msgid, void* msg, int size, long rec, 
                bool* status);


/**
 * \brief blocking reception of a message
 * \param msgid queue id
 * \param msg pointer to the message buffer
 * \param size size of message buffer in bytes
 * \param rec receiver id
 * \return 0 on success; -1 on error, being errno set with the cause
 */
extern int msg_receive (int msgid, void* msg, int size, long rec);
