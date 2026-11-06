#include <stdio.h>

#define NB 8

typedef struct { char name[10]; int start, end, gain; } Promo;

int main(void) {
    Promo promos[NB] = {{"Flash", 8, 11, 50}, {"Phones", 9, 12, 70}, {"Audio", 11, 14, 40},
                        {"Laptops", 10, 16, 120}, {"Cables", 13, 15, 20}, {"Gaming", 14, 18, 65},
                        {"Night", 18, 22, 55}, {"Bundle", 16, 20, 110}};
    Promo key;
    int best[NB + 1], take[NB + 1], idx, back, lastEnd = 0, count = 0, compat, withIt;
    for (idx = 1; idx < NB; idx++) {                    // ترتيب حسب النهاية
        key = promos[idx];
        for (back = idx - 1; back >= 0 && promos[back].end > key.end; back--) promos[back + 1] = promos[back];
        promos[back + 1] = key;
    }
    printf("Greedy (max count):");
    for (idx = 0; idx < NB; idx++)
        if (promos[idx].start >= lastEnd) {
            printf(" %s", promos[idx].name);
            lastEnd = promos[idx].end;
            count++;
        }
    printf(" -> %d promos\n", count);
    best[0] = 0;
    for (idx = 1; idx <= NB; idx++) {
        for (compat = idx - 1; compat >= 1 && promos[compat - 1].end > promos[idx - 1].start; compat--) {}
        withIt = promos[idx - 1].gain + best[compat];   // compat = عدد العروض المتوافقة قبله
        take[idx] = withIt > best[idx - 1];
        best[idx] = take[idx] ? withIt : best[idx - 1];
    }
    printf("DP (max gain):");
    for (idx = NB; idx >= 1; ) {                        // إعادة البناء
        if (take[idx]) {
            printf(" %s", promos[idx - 1].name);
            for (compat = idx - 1; compat >= 1 && promos[compat - 1].end > promos[idx - 1].start; compat--) {}
            idx = compat;
        } else {
            idx--;
        }
    }
    printf(" -> gain %d\n", best[NB]);
    return 0;
}
