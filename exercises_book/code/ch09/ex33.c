#include <stdio.h>

typedef struct {
    char name[10];
    int recency, frequency;
    double monetary;
    int scoreR, scoreF, scoreM;
} Client;

int grade(double value, double good, double medium, int higherIsBetter) {
    if (higherIsBetter) return value >= good ? 3 : value >= medium ? 2 : 1;
    return value <= good ? 3 : value <= medium ? 2 : 1;
}

int main(void) {
    Client clients[6] = {{"Amina", 12, 15, 82000, 0, 0, 0}, {"Bilal", 200, 2, 6000, 0, 0, 0},
                         {"Karim", 45, 6, 21000, 0, 0, 0}, {"Lina", 20, 3, 9000, 0, 0, 0},
                         {"Omar", 120, 11, 64000, 0, 0, 0}, {"Sara", 75, 4, 16000, 0, 0, 0}};
    char segments[4][10] = {"Lost", "At risk", "Loyal", "Champion"};
    int idx, total;
    for (idx = 0; idx < 6; idx++) {
        clients[idx].scoreR = grade(clients[idx].recency, 30, 90, 0);    // الأقل أفضل
        clients[idx].scoreF = grade(clients[idx].frequency, 10, 4, 1);
        clients[idx].scoreM = grade(clients[idx].monetary, 50000, 15000, 1);
        total = clients[idx].scoreR + clients[idx].scoreF + clients[idx].scoreM;
        printf("%-6s R%d F%d M%d = %d -> %s\n", clients[idx].name, clients[idx].scoreR,
               clients[idx].scoreF, clients[idx].scoreM, total,
               segments[total >= 8 ? 3 : total >= 6 ? 2 : total >= 4 ? 1 : 0]);
    }
    return 0;
}
