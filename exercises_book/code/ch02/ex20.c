#include <stdio.h>

int main(void) {
    double p1, r1, p2, r2;
    scanf("%lf %lf %lf %lf", &p1, &r1, &p2, &r2);
    // ليس أسوأ في أي معيار، وأفضل في معيار واحد على الأقل
    if (p1 <= p2 && r1 >= r2 && (p1 < p2 || r1 > r2))
        printf("Product 1 dominates product 2\n");
    else if (p2 <= p1 && r2 >= r1 && (p2 < p1 || r2 > r1))
        printf("Product 2 dominates product 1\n");
    else
        printf("No dominance (trade-off)\n");
    return 0;
}
