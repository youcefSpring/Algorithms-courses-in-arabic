#include <stdio.h>

int main(void) {
    char light = 'O';
    switch (light) {
        case 'G': printf("Go\n");         break;
        case 'O': printf("Slow down\n");  break;
        case 'R': printf("Stop\n");       break;
        default:  printf("Sensor error\n");
    }
    return 0;
}
