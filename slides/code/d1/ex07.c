#include <stdio.h>

int main(void) {
    int followers = 12500;
    int likes = 830, comments = 95;
    float rate = (likes + comments) * 100.0 / followers;
    printf("Engagement = %.2f %%\n", rate);
    return 0;
}
