#include <stdio.h>

float co2(float km, char mode) {
    switch (mode) {
        case 'c': return km * 0.12;   /* car */
        case 'b': return km * 0.07;   /* bus */
        case 't': return km * 0.03;   /* train */
        default:  return 0;           /* bike */
    }
}

int main(void) {
    printf("Car:   %.1f kg\n", co2(100, 'c'));
    printf("Bus:   %.1f kg\n", co2(100, 'b'));
    printf("Train: %.1f kg\n", co2(100, 't'));
    return 0;
}
