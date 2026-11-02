#include <stdio.h>

int main(void) {
    double cx, cy, radius, x1, x2, y1, y2, custX, custY, d2;
    int inC, inR;
    scanf("%lf %lf %lf", &cx, &cy, &radius);           // الدائرة
    scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2); // المستطيل
    scanf("%lf %lf", &custX, &custY);                     // الزبون
    d2 = (custX - cx) * (custX - cx) + (custY - cy) * (custY - cy);
    inC = (d2 <= radius * radius);              // مقارنة المربعات بدل الجذر
    inR = (custX >= x1 && custX <= x2 && custY >= y1 && custY <= y2);
    printf("Squared distance = %.1f (limit %.1f)\n", d2, radius * radius);
    if (inC && inR)
        printf("Inside both zones\n");
    else if (inC)
        printf("Inside the circle only\n");
    else if (inR)
        printf("Inside the industrial rectangle only\n");
    else
        printf("Out of delivery zone\n");
    return 0;
}
