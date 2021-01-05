/*
 * \brief message queue module (implementation)
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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define  MASK   0600  ///< creation permissions

/* 
 * \brief creation of a message queue
 * \param key the creation key
 * \return the queue id on success; -1 on error, being errno set with the cause
 */
int msg_create (int key)
{
    return (msgget ((key_t) key, MASK | IPC_CREAT | IPC_EXCL));
}

/* 
 * \brief connection to a previous created message queue
 * \param key the creation key
 * \return the queue id on success; -1 on error, being errno set with the cause
 */
int msg_connect (int key)
{
    return (msgget ((key_t) key, MASK));
}

/*
 * \brief destruction of message queue
 * \param msgid queue id
 * \return 0 on success; -1 on error, being errno set with the cause
 */
int msg_destroy (int msgid)
{
    return (msgctl (msgid, IPC_RMID, 0));
}

/*
 * \brief non blocking sending of a message
 * \param msgid queue id
 * \param msg pointer to the message to be sent
 * \param size size of message in bytes
 * \return 0 on success; -1 on error, being errno set with the cause
 */
int msg_send_nb (int msgid, void *msg, int size)
{
    return (msgsnd (msgid, (struct msgbuf *) msg, size, 0));
}

/*
 * \brief non blocking reception of a message
 * \param msgid queue id
 * \param msg pointer to the message buffer
 * \param size size of message buffer in bytes
 * \param dest destination id
 * \param status pointer to success on repeption status
 * \return 0 on success; -1 on error, being errno set with the cause
 */
int msg_receive_nb (int msgid, void *msg, int size, long dest, bool *msgrec)
{
    int stat;

    stat = msgrcv (msgid, (struct msgbuf *) msg, size, dest, IPC_NOWAIT);
    *msgrec = (stat >= 0);
    if ((stat >= 0) || ((stat == -1) && (errno == ENOMSG))) return (0);
    else return (stat);
}

/*
 * \brief blocking reception of a message
 * \param msgid queue id
 * \param msg pointer to the message buffer
 * \param size size of message buffer in bytes
 * \param dest destination id
 * \return 0 on success; -1 on error, being errno set with the cause
 */
int msg_receive (int msgid, void *msg, int size, long dest)
{
    return (msgrcv (msgid, (struct msgbuf *) msg, size, dest, 0));
}
