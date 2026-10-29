#include <stdio.h>

void logEvent(char msg[]) {
    FILE *f = fopen("log.txt", "a");
    if (f == NULL) return;
    fprintf(f, "%s\n", msg);
    fclose(f);
}

int main(void) {
    logEvent("Program started");
    logEvent("User logged in");
    logEvent("Program stopped");
    return 0;
}
