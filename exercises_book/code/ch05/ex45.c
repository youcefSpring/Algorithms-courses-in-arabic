#include <stdio.h>

#define NB 6
#define INF 1000000

int main(void) {
    int road[NB][NB] = {{0, 7, 9, 0, 0, 14},
                        {7, 0, 10, 15, 0, 0},
                        {9, 10, 0, 11, 0, 2},
                        {0, 15, 11, 0, 6, 0},
                        {0, 0, 0, 6, 0, 9},
                        {14, 0, 2, 0, 9, 0}};
    int best[NB], done[NB], previous[NB], path[NB];
    int node, next, round, target, length = 0;
    for (node = 0; node < NB; node++) {
        best[node] = INF; done[node] = 0; previous[node] = -1;
    }
    best[0] = 0;                                  // المستودع
    for (round = 0; round < NB; round++) {
        node = -1;                                // أقرب عقدة غير معالجة
        for (next = 0; next < NB; next++)
            if (!done[next] && (node < 0 || best[next] < best[node]))
                node = next;
        done[node] = 1;                           // مسافتها نهائية الآن
        for (next = 0; next < NB; next++)
            if (road[node][next] && best[node] + road[node][next] < best[next]) {
                best[next] = best[node] + road[node][next];
                previous[next] = node;
            }
    }
    scanf("%d", &target);
    for (node = target; node != -1; node = previous[node])
        path[length++] = node;                    // المسار معكوسًا
    printf("Distance to %d = %d min\nPath:", target, best[target]);
    while (length > 0)
        printf(" %d", path[--length]);
    printf("\n");
    return 0;
}
