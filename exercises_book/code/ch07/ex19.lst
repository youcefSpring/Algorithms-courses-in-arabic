#include <stdio.h>

void printDuration(int seconds) {
    printf("%02d:%02d:%02d\n", seconds / 3600, (seconds % 3600) / 60, seconds % 60);
}

int toSeconds(int hours, int minutes, int secs) {
    return hours * 3600 + minutes * 60 + secs;
}

int main(void) {
    int sessions[4] = {754, 3725, 192, toSeconds(1, 5, 30)};
    int idx, total = 0;
    for (idx = 0; idx < 4; idx++) {
        printf("Session %d: ", idx + 1);
        printDuration(sessions[idx]);
        total += sessions[idx];
    }
    printf("Average:   ");
    printDuration(total / 4);
    return 0;
}
