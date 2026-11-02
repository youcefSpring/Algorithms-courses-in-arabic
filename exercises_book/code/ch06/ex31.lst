#include <stdio.h>

int main(void) {
    char text[20];
    int pos, length = 0, valid = 1, year = 0, month = 0, day = 0;
    scanf("%19s", text);
    while (text[length] != '\0') length++;
    if (length != 10 || text[4] != '-' || text[7] != '-')
        valid = 0;
    for (pos = 0; pos < length && valid; pos++)
        if (pos != 4 && pos != 7 && (text[pos] < '0' || text[pos] > '9'))
            valid = 0;
    if (!valid) {
        printf("Bad format\n");
        return 0;
    }
    for (pos = 0; pos < 4; pos++)  year = year * 10 + (text[pos] - '0');
    for (pos = 5; pos < 7; pos++)  month = month * 10 + (text[pos] - '0');
    for (pos = 8; pos < 10; pos++) day = day * 10 + (text[pos] - '0');
    if (month >= 1 && month <= 12 && day >= 1 && day <= 31)
        printf("%02d/%02d/%d\n", day, month, year);
    else
        printf("Bad values\n");
    return 0;
}
