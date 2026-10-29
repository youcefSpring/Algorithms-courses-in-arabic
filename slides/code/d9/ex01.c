#include <stdio.h>

typedef struct { char name[20]; float temp; } Patient;

int main(void) {
    Patient p[4] = {{"Amina", 37.2}, {"Omar", 38.9},
                    {"Lina", 39.4}, {"Said", 36.8}};
    int i;
    for (i = 0; i < 4; i++)
        if (p[i].temp > 38)
            printf("Fever: %s (%.1f)\n", p[i].name, p[i].temp);
    return 0;
}
