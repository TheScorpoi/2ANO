/**
 * A simple module (implementation file).
 *
 * (c) 2004 Artur Pereira <artur@ua.pt>
 *
 * A very simple module, with an internal data structure and 3 manipulation functions.
 * The internal data structure is just a single integer variable.
 * The 3 manipulation functions are meant to:
 * - set the variable value;
 * - get the variable value;
 * - increment by one the variable value.
 */

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

/* internal data structure */
static int value = 0;

/* set the variable value */
void vSet (int new_value)
{
    value = new_value;
}

/* get the variable value */
int vGet (void)
{
    return value;
}

/* increment the variable value */
void vInc (void)
{
    int val;

    /* load locally the stored value */
    val = value;

    /* generate time delay 1 */
    delay (BIG);

    /* increment the local value and store it back */
    value = val + 1;

    /* generate time delay 2 */
    delay (SMALL);
}
