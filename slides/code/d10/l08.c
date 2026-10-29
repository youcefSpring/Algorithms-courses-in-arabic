int *p;           /* not initialized */
*p = 5;           /* error: unknown address */
int *q = NULL;
*q = 5;           /* error: NULL pointer */
