#include <stdio.h>

#define NB 12

typedef struct { char source; int pages, seconds, bought; } Session;
typedef struct { int sessions, bounces, seconds, sales; } SourceStats;

int main(void) {
    Session log[NB] = {{'S', 5, 340, 1}, {'A', 1, 12, 0}, {'D', 8, 610, 1}, {'A', 1, 9, 0},
                       {'S', 3, 150, 0}, {'A', 2, 45, 0}, {'D', 1, 20, 0}, {'S', 7, 420, 1},
                       {'A', 1, 15, 0}, {'S', 1, 30, 0}, {'D', 4, 260, 1}, {'A', 6, 380, 1}};
    char codes[4] = "SAD";
    char labels[3][8] = {"Search", "Ads", "Direct"};
    SourceStats stats[3] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int idx, src;
    for (idx = 0; idx < NB; idx++) {
        for (src = 0; codes[src] != log[idx].source; src++) {}   // فهرس المصدر
        stats[src].sessions++;
        stats[src].seconds += log[idx].seconds;
        if (log[idx].pages == 1) stats[src].bounces++;
        if (log[idx].bought) stats[src].sales++;
    }
    for (src = 0; src < 3; src++)
        printf("%-6s %d sessions, bounce %5.1f%%, avg %5.1fs, conversion %5.1f%%\n", labels[src],
               stats[src].sessions, 100.0 * stats[src].bounces / stats[src].sessions,
               (double)stats[src].seconds / stats[src].sessions,
               100.0 * stats[src].sales / stats[src].sessions);
    return 0;
}
