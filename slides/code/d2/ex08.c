#include <stdio.h>

int main(void) {
    int battery = 15, charging = 0;
    if (charging)
        printf("Charging...\n");
    else if (battery <= 5)
        printf("Shutting down\n");
    else if (battery <= 20)
        printf("Power saving mode\n");
    else
        printf("Normal mode\n");
    return 0;
}
