/**
 * A simple module/monitor (interface file).
 *
 * (c) 2004 Artur Pereira <artur@ua.pt>
 *
 * A very simple module/monitor, with an internal data structure and 3 manipulation functions.
 * The internal data structure is just a single integer variable.
 * The 3 manipulation functions are meant to:
 * - set the variable value;
 * - get the variable value;
 * - increment by one the variable value.
 */

#ifndef INCMOD_H_
#define INCMOD_H_

/* set the variable value */
void vSet (int new_value);

/* get the variable value */
int vGet (void);

/* increment the variable value */
void vInc (void);

#endif /* INCMOD_H_ */
