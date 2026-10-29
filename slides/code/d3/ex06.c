#include <stdio.h>

int main(void) {
    int secret = 4271, pin, attempts = 0;
    for (pin = 0; pin <= 9999; pin++) {
        attempts++;
        if (pin == secret)
            break;
    }
    printf("PIN %04d found\n", pin);
    printf("Attempts = %d\n", attempts);
    return 0;
}
