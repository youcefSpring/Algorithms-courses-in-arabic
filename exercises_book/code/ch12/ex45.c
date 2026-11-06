#include <stdio.h>
#include <stdlib.h>

#define NBN 9

typedef struct Edge { int to; struct Edge *next; } Edge;

Edge *adjacency[NBN];

void addEdge(int from, int to) {
    Edge *edge = malloc(sizeof(Edge));
    edge->to = to; edge->next = adjacency[from]; adjacency[from] = edge;
    edge = malloc(sizeof(Edge));
    edge->to = from; edge->next = adjacency[to]; adjacency[to] = edge;   // الاتجاهان
}

void bfs(int source, int dist[]) {
    int queue[NBN], front = 0, rear = 0, current;
    Edge *edge;
    dist[source] = 0;
    queue[rear++] = source;
    while (front < rear) {
        current = queue[front++];
        for (edge = adjacency[current]; edge != NULL; edge = edge->next)
            if (dist[edge->to] == -1) {
                dist[edge->to] = dist[current] + 1;   // مستوى إضافي
                queue[rear++] = edge->to;
            }
    }
}

int main(void) {
    int edges[9][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {6, 7}, {1, 2}, {5, 2}};
    int dist[NBN], node, components = 0;
    Edge *edge, *next;
    for (node = 0; node < 9; node++) addEdge(edges[node][0], edges[node][1]);
    for (node = 0; node < NBN; node++) dist[node] = -1;
    bfs(0, dist);
    printf("Degrees of separation from customer 0:\n");
    for (node = 1; node < NBN; node++)
        if (dist[node] >= 0) printf("  customer %d: %d\n", node, dist[node]);
        else printf("  customer %d: unreachable\n", node);
    for (node = 0; node < NBN; node++) dist[node] = -1;
    for (node = 0; node < NBN; node++)
        if (dist[node] == -1) { bfs(node, dist); components++; }
    printf("Connected groups: %d\n", components);
    for (node = 0; node < NBN; node++)
        for (edge = adjacency[node]; edge != NULL; edge = next) { next = edge->next; free(edge); }
    return 0;
}
