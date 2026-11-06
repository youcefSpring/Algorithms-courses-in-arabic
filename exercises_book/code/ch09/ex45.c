#include <stdio.h>

#define NBN 7
#define NBR 11
#define INF 1000000

typedef struct { int from, to, length; } Road;

int main(void) {
    Road roads[NBR] = {{0, 1, 7}, {0, 2, 9}, {0, 5, 14}, {1, 2, 10}, {1, 3, 15}, {2, 3, 11},
                       {2, 5, 2}, {3, 4, 6}, {4, 5, 9}, {4, 6, 5}, {3, 6, 12}};
    int dist[NBN], previous[NBN], done[NBN], path[NBN];
    int node, step, current, road, other, len, idx;
    for (node = 0; node < NBN; node++) { dist[node] = INF; done[node] = 0; previous[node] = -1; }
    dist[0] = 0;
    for (step = 0; step < NBN; step++) {
        current = -1;
        for (node = 0; node < NBN; node++)               // أقرب عقدة غير منتهية
            if (!done[node] && (current < 0 || dist[node] < dist[current])) current = node;
        done[current] = 1;
        for (road = 0; road < NBR; road++) {
            if (roads[road].from == current) other = roads[road].to;
            else if (roads[road].to == current) other = roads[road].from;
            else continue;
            if (dist[current] + roads[road].length < dist[other]) {   // إرخاء
                dist[other] = dist[current] + roads[road].length;
                previous[other] = current;
            }
        }
    }
    for (node = 1; node < NBN; node++) {
        len = 0;
        for (other = node; other != -1; other = previous[other]) path[len++] = other;
        printf("to %d: %2d km via", node, dist[node]);
        for (idx = len - 1; idx >= 0; idx--) printf(" %d", path[idx]);
        printf("\n");
    }
    return 0;
}
