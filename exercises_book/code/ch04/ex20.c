#include <stdio.h>

#define NB_REVIEWS 15

int main(void) {
    int ratings[NB_REVIEWS] = {4, 5, 3, 4, 4, 2, 5, 4, 1, 3, 4, 5, 5, 4, 3};
    int cnt[6] = {0};             // كل الخانات تبدأ من 0
    int index, value, mode = 1;
    for (index = 0; index < NB_REVIEWS; index++)
        cnt[ratings[index]]++;              // التقييم نفسه هو الفهرس
    for (value = 2; value <= 5; value++)
        if (cnt[value] > cnt[mode])
            mode = value;
    for (value = 1; value <= 5; value++)
        printf("%d stars: %d\n", value, cnt[value]);
    printf("Mode = %d (%d times)\n", mode, cnt[mode]);
    return 0;
}
