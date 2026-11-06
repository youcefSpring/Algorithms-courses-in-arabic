#include <stdio.h>

typedef struct { char category[12]; double amount; } Sale;
typedef struct { char category[12]; double sum; int count; } CategoryTotal;

int sameText(char first[], char second[]) {
    int pos = 0;
    while (first[pos] != '\0' && first[pos] == second[pos]) pos++;
    return first[pos] == second[pos];
}

int main(void) {
    Sale sales[10] = {{"Phones", 38000}, {"Audio", 5400}, {"Phones", 27500}, {"Laptops", 95000},
                      {"Audio", 12500}, {"Cables", 450}, {"Laptops", 72000}, {"Phones", 41000},
                      {"Cables", 900}, {"Audio", 3100}};
    CategoryTotal totals[10];
    int sale, cat, pos, nbCats = 0, letter;
    double grand = 0;
    for (sale = 0; sale < 10; sale++) {
        pos = -1;
        for (cat = 0; cat < nbCats; cat++)
            if (sameText(totals[cat].category, sales[sale].category)) pos = cat;
        if (pos < 0) {                                   // فئة جديدة
            pos = nbCats++;
            for (letter = 0; letter < 12; letter++) totals[pos].category[letter] = sales[sale].category[letter];
            totals[pos].sum = 0;
            totals[pos].count = 0;
        }
        totals[pos].sum += sales[sale].amount;
        totals[pos].count++;
        grand += sales[sale].amount;
    }
    for (cat = 0; cat < nbCats; cat++)
        printf("%-8s %d sales, total %9.0f, mean %8.0f, share %5.1f%%\n", totals[cat].category,
               totals[cat].count, totals[cat].sum, totals[cat].sum / totals[cat].count,
               totals[cat].sum / grand * 100);
    return 0;
}
