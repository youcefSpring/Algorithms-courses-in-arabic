#include <stdio.h>

int main(void) {
    double score, conf;
    scanf("%lf %lf", &score, &conf);
    if (conf < 0.6) {
        printf("Uncertain (confidence %.2f)\n", conf);
    } else if (score > 0.25) {
        printf("Positive review\n");
    } else if (score < -0.25) {
        printf("Negative review\n");      // يرسل إلى خدمة الزبائن
    } else {
        printf("Neutral review\n");
    }
    return 0;
}
