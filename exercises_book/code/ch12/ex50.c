#include <stdio.h>
#include <stdlib.h>

#define NBT 7

typedef struct Arc { int to; struct Arc *next; } Arc;

const char *names[NBT] = {"receive", "check", "pick", "invoice", "pack", "label", "ship"};

int topoSort(Arc *adjacency[], int order[]) {
    int inDegree[NBT] = {0}, queue[NBT], front = 0, rear = 0, task, done = 0;
    Arc *arc;
    for (task = 0; task < NBT; task++)
        for (arc = adjacency[task]; arc != NULL; arc = arc->next) inDegree[arc->to]++;
    for (task = 0; task < NBT; task++) if (inDegree[task] == 0) queue[rear++] = task;
    while (front < rear) {
        task = queue[front++];
        order[done++] = task;
        for (arc = adjacency[task]; arc != NULL; arc = arc->next)
            if (--inDegree[arc->to] == 0) queue[rear++] = arc->to;    // كل ما قبلها أنجز
    }
    return done;
}

void addArc(Arc *adjacency[], int from, int to) {
    Arc *arc = malloc(sizeof(Arc));
    arc->to = to; arc->next = adjacency[from]; adjacency[from] = arc;
}

void runCase(int deps[][2], int nbDeps) {
    Arc *adjacency[NBT] = {NULL}, *arc, *next;
    int order[NBT], done, idx;
    for (idx = 0; idx < nbDeps; idx++) addArc(adjacency, deps[idx][0], deps[idx][1]);
    done = topoSort(adjacency, order);
    for (idx = 0; idx < done; idx++) printf("%s%s", names[order[idx]], idx < done - 1 ? " -> " : "\n");
    if (done < NBT) printf("cycle detected: %d task(s) blocked\n", NBT - done);
    for (idx = 0; idx < NBT; idx++)
        for (arc = adjacency[idx]; arc != NULL; arc = next) { next = arc->next; free(arc); }
}

int main(void) {
    int deps[8][2] = {{0, 1}, {1, 2}, {0, 3}, {2, 4}, {3, 5}, {4, 5}, {5, 6}, {3, 6}};
    int badDeps[8][2] = {{0, 1}, {1, 2}, {0, 3}, {2, 4}, {3, 5}, {4, 5}, {5, 6}, {6, 4}};
    runCase(deps, 8);
    runCase(badDeps, 8);
    return 0;
}
