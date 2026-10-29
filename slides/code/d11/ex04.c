#include <stdio.h>

void addTrip(char from[], char to[], int km) {
    FILE *f = fopen("trips.txt", "a");
    if (f == NULL) return;
    fprintf(f, "%s -> %s : %d km\n", from, to, km);
    fclose(f);
}

int main(void) {
    addTrip("Boumerdes", "Algiers", 45);
    addTrip("Algiers", "Blida", 50);
    addTrip("Blida", "Medea", 40);
    return 0;
}
