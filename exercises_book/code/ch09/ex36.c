#include <stdio.h>

#define NB 8

typedef struct { int day; char kind; double amount; int accepted; } Transaction;

int main(void) {
    Transaction log[NB] = {{1, 'D', 10000, 0}, {3, 'P', 4500, 0}, {4, 'P', 7000, 0},
                           {6, 'R', 1200, 0}, {9, 'P', 6200, 0}, {12, 'D', 5000, 0},
                           {15, 'P', 3300, 0}, {20, 'P', 1800, 0}};
    double balance = 0, lowest = 0;
    int idx;
    for (idx = 0; idx < NB; idx++) {
        if (log[idx].kind == 'P' && log[idx].amount > balance) {
            log[idx].accepted = 0;                       // رصيد غير كافٍ
        } else {
            balance += log[idx].kind == 'P' ? -log[idx].amount : log[idx].amount;
            log[idx].accepted = 1;
            if (balance < lowest || idx == 0) lowest = balance;
        }
        printf("Day %2d %c %7.2f %-8s balance %8.2f\n", log[idx].day, log[idx].kind,
               log[idx].amount, log[idx].accepted ? "ok" : "REFUSED", balance);
    }
    printf("Lowest balance: %.2f DA\n", lowest);
    return 0;
}
