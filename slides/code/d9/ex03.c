#include <stdio.h>

typedef struct { char city[15]; float tmin, tmax; } Station;

int main(void) {
    Station s[3] = {{"Algiers", 18, 29},
                    {"Tamanrasset", 21, 41},
                    {"Setif", 9, 27}};
    int i;
    for (i = 0; i < 3; i++)
        printf("%-12s %4.1f\n", s[i].city,
               s[i].tmax - s[i].tmin);
    return 0;
}
