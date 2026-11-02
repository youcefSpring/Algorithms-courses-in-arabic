#include <stdio.h>

int main(void) {
    int phone, cover, charger;
    scanf("%d %d %d", &phone, &cover, &charger);
    // ! تعني النفي: !cover صحيح إذا كان cover يساوي 0
    if (phone && !cover)
        printf("Recommend: phone cover\n");
    else if (cover && charger)
        printf("Recommend: earphones\n");
    else
        printf("No recommendation\n");
    return 0;
}
