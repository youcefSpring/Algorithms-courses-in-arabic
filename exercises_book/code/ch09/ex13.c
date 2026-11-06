#include <stdio.h>

#define NB 6

typedef struct {
    char name[16];
    char city[16];
    double spent;
} Customer;

int compareNames(char first[], char second[]) {
    int pos = 0;
    while (first[pos] != '\0' && first[pos] == second[pos]) pos++;
    return first[pos] - second[pos];
}

int before(Customer first, Customer second) {
    int byName = compareNames(first.name, second.name);
    if (byName != 0) return byName < 0;
    return compareNames(first.city, second.city) < 0;    // نفس الاسم: المدينة
}

int main(void) {
    Customer clients[NB] = {{"Yacine", "Oran", 15000}, {"Amina", "Setif", 8200},
                            {"Karim", "Annaba", 23000}, {"Amina", "Blida", 4100},
                            {"Lina", "Algiers", 9900}, {"Bilal", "Oran", 12000}};
    Customer key;
    int idx, back;
    for (idx = 1; idx < NB; idx++) {
        key = clients[idx];
        back = idx - 1;
        while (back >= 0 && before(key, clients[back])) {
            clients[back + 1] = clients[back];
            back--;
        }
        clients[back + 1] = key;
    }
    for (idx = 0; idx < NB; idx++)
        printf("%-7s %-8s %8.0f\n", clients[idx].name, clients[idx].city, clients[idx].spent);
    return 0;
}
