#include <stdio.h>

#define NBL 4
#define LEN 60

int main(void) {
    FILE *file = fopen("access.log", "w");
    char ring[NBL][LEN];
    int hour, next = 0, count = 0, idx, start, shown;
    for (hour = 0; hour < 24; hour++)
        fprintf(file, "%02d:00 visits=%d orders=%d\n", hour, 100 + hour * 13 % 70, hour * 7 % 11);
    fclose(file);
    file = fopen("access.log", "r");
    while (fgets(ring[next], LEN, file) != NULL) {
        next = (next + 1) % NBL;                  // نكتب فوق الأقدم
        count++;
    }
    fclose(file);
    start = count < NBL ? 0 : next;
    shown = count < NBL ? count : NBL;
    printf("Last %d of %d lines:\n", shown, count);
    for (idx = 0; idx < shown; idx++) printf("%s", ring[(start + idx) % NBL]);
    return 0;
}
