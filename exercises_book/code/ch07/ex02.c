#include <stdio.h>

double minPrice(double first, double second) {
    if (first < second)
        return first;
    return second;
}

double maxPrice(double first, double second) {
    return first > second ? first : second;     // نفس الفكرة بالعامل الشرطي
}

int main(void) {
    double first, second;
    scanf("%lf %lf", &first, &second);
    printf("Best offer: %.2f DA\n", minPrice(first, second));
    printf("You save:   %.2f DA\n", maxPrice(first, second) - minPrice(first, second));
    return 0;
}
