#include <stdio.h>

long memo[40];

long catalan(int nodes) {
    long total = 0;
    int left;
    if (nodes <= 1) return 1;
    if (memo[nodes] != 0) return memo[nodes];
    for (left = 0; left < nodes; left++)
        total += catalan(left) * catalan(nodes - 1 - left);   // يسار × يمين
    memo[nodes] = total;
    return total;
}

int main(void) {
    int nodes;
    for (nodes = 0; nodes <= 15; nodes++) {
        printf("C(%2d) = %-9ld", nodes, catalan(nodes));
        if (nodes % 4 == 3) printf("\n");
    }
    return 0;
}
