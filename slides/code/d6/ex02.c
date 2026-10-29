#include <stdio.h>

int main(void) {
    char post[] = "Exam done! #algo #C #ENS";
    int i, tags = 0;
    for (i = 0; post[i] != '\0'; i++)
        if (post[i] == '#')
            tags++;
    printf("Hashtags = %d\n", tags);
    return 0;
}
