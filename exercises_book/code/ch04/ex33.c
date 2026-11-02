#include <stdio.h>

#define NB 8

int main(void) {
    int ids[NB]   = {11, 12, 13, 14, 15, 16, 17, 18};
    int stock[NB] = { 4,  0,  9,  0,  2,  7,  0,  1};
    int outIds[NB], write = 0, nbOut = 0, index;
    for (index = 0; index < NB; index++) {
        if (stock[index] > 0) {
            ids[write] = ids[index];      // write <= index دائمًا: لا نمسح شيئًا
            stock[write] = stock[index];
            write++;
        } else {
            outIds[nbOut++] = ids[index]; // نحفظ النافدة جانبًا
        }
    }
    for (index = 0; index < nbOut; index++) {
        ids[write + index] = outIds[index];
        stock[write + index] = 0;
    }
    for (index = 0; index < NB; index++)
        printf("#%d(%d) ", ids[index], stock[index]);
    printf("\n");
    return 0;
}
