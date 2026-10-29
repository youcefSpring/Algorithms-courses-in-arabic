#include <stdio.h>
#define LIMIT 80   /* km/h */

int main(void) {
    int speed = 104;
    int excess = speed - LIMIT;
    if (excess <= 0)
        printf("OK\n");
    else if (excess <= 20)
        printf("Fine: 2000 DA\n");
    else
        printf("Fine: 5000 DA\n");
    return 0;
}
