#include <stdio.h>

int main(void) {
    float distance = 10.0;   /* km */
    int minutes = 52;
    float speed = distance / (minutes / 60.0);
    printf("Speed = %.2f km/h\n", speed);
    printf("Pace = %.2f min/km\n", minutes / distance);
    return 0;
}
