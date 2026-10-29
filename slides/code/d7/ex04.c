#include <stdio.h>

int travelMinutes(float km, float speed) {
    return (int) (km / speed * 60);
}

void showTime(int minutes) {
    printf("%dh %02dmin\n", minutes / 60, minutes % 60);
}

int main(void) {
    showTime(travelMinutes(420, 90));  /* Alger-Oran */
    showTime(travelMinutes(35, 60));
    return 0;
}
