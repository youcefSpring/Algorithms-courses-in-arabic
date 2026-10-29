#include <stdio.h>
#define N 6

int main(void) {
    int likes[N] = {320, 1500, 870, 2100, 95, 1010};
    int i, viral = 0;
    for (i = 0; i < N; i++)
        if (likes[i] >= 1000) {
            printf("Post %d: %d\n", i + 1, likes[i]);
            viral++;
        }
    printf("Viral posts = %d\n", viral);
    return 0;
}
