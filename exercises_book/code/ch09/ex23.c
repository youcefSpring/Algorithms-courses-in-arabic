#include <stdio.h>

typedef struct {
    char name[12];
    double sales, target, bonus;
} Seller;

double commission(Seller seller) {
    double amount;
    if (seller.sales <= seller.target) return seller.sales * 0.03;
    amount = seller.target * 0.03 + (seller.sales - seller.target) * 0.05;
    if (seller.sales > seller.target * 1.2) amount += 10000;    // مكافأة
    return amount;
}

int main(void) {
    Seller team[5] = {{"Rania", 820000, 700000, 0}, {"Hakim", 640000, 700000, 0},
                      {"Selma", 910000, 750000, 0}, {"Omar", 505000, 500000, 0},
                      {"Imane", 300000, 450000, 0}};
    Seller tmp;
    int idx, pass;
    for (idx = 0; idx < 5; idx++) team[idx].bonus = commission(team[idx]);
    for (pass = 0; pass < 4; pass++)
        for (idx = 0; idx < 4 - pass; idx++)
            if (team[idx].bonus < team[idx + 1].bonus) {
                tmp = team[idx]; team[idx] = team[idx + 1]; team[idx + 1] = tmp;
            }
    for (idx = 0; idx < 5; idx++)
        printf("%d. %-6s sales %7.0f / %7.0f -> %8.2f DA\n", idx + 1, team[idx].name,
               team[idx].sales, team[idx].target, team[idx].bonus);
    return 0;
}
