#include <stdio.h>

int main(void) {
    char url[] = "https://shop.dz/search?q=laptop&brand=hp&maxprice=95000&sort=price";
    char key[20], value[30], target[] = "maxprice";
    int pos = 0, length, cmp;
    long maxPrice = -1;
    while (url[pos] != '?' && url[pos] != '\0') pos++;
    if (url[pos] == '?') pos++;
    while (url[pos] != '\0') {
        length = 0;
        while (url[pos] != '=' && url[pos] != '\0') key[length++] = url[pos++];
        key[length] = '\0';
        if (url[pos] == '=') pos++;
        length = 0;
        while (url[pos] != '&' && url[pos] != '\0') value[length++] = url[pos++];
        value[length] = '\0';
        if (url[pos] == '&') pos++;           // الزوج التالي
        printf("%-9s = %s\n", key, value);
        for (cmp = 0; key[cmp] == target[cmp] && key[cmp] != '\0'; cmp++) ;
        if (key[cmp] == target[cmp]) {        // المفتاح هو maxprice
            maxPrice = 0;
            for (cmp = 0; value[cmp] != '\0'; cmp++)
                maxPrice = maxPrice * 10 + (value[cmp] - '0');
        }
    }
    printf("Max price filter: %ld DA\n", maxPrice);
    return 0;
}
