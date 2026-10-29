char a[20], b[] = "Algo";
a = b;              /* error: use strcpy(a, b)    */
if (a == b) { }     /* wrong: use strcmp(a, b)    */
