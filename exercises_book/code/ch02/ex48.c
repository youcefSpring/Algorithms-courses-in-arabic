#include <stdio.h>

int main(void) {
    double visits, basket, d1, d2, d3, d4, best;
    int cls, who;
    scanf("%lf %lf", &visits, &basket);
    // مربع المسافة إلى كل زبون معروف (بيانات التدريب)
    d1 = (visits - 2) * (visits - 2) + (basket - 1.5) * (basket - 1.5);
    d2 = (visits - 4) * (visits - 4) + (basket - 2) * (basket - 2);
    d3 = (visits - 9) * (visits - 9) + (basket - 7.5) * (basket - 7.5);
    d4 = (visits - 11) * (visits - 11) + (basket - 6) * (basket - 6);
    printf("d2: %.2f %.2f %.2f %.2f\n", d1, d2, d3, d4);
    best = d1; cls = 0; who = 1;          // نبدأ بالجار الأول
    if (d2 < best) { best = d2; cls = 0; who = 2; }
    if (d3 < best) { best = d3; cls = 1; who = 3; }
    if (d4 < best) { best = d4; cls = 1; who = 4; }
    printf("Nearest neighbour: customer %d\n", who);
    if (cls == 0) printf("Predicted class: thrifty\n");
    else          printf("Predicted class: big spender\n");
    return 0;
}
