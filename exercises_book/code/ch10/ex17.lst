#include <stdio.h>

#define NB 5

typedef struct { char name[16]; double price, rating; char details[200]; } Product;

void sortView(Product *view[], int byPrice) {
    Product *tmp;
    int pass, idx, swapIt;
    for (pass = 0; pass < NB - 1; pass++)
        for (idx = 0; idx < NB - 1 - pass; idx++) {
            swapIt = byPrice ? view[idx]->price > view[idx + 1]->price
                             : view[idx]->rating < view[idx + 1]->rating;
            if (swapIt) { tmp = view[idx]; view[idx] = view[idx + 1]; view[idx + 1] = tmp; }
        }
}

void show(char label[], Product *view[]) {
    int idx;
    printf("%s", label);
    for (idx = 0; idx < NB; idx++) printf(" %s;", view[idx]->name);
    printf("\n");
}

int main(void) {
    Product items[NB] = {{"Monitor", 32000, 4.4, ""}, {"Mouse", 1500, 4.7, ""},
                         {"Laptop", 89000, 4.2, ""}, {"Keyboard", 3200, 4.5, ""},
                         {"Webcam", 4100, 3.9, ""}};
    Product *view[NB];
    int idx;
    for (idx = 0; idx < NB; idx++) view[idx] = &items[idx];
    sortView(view, 1);
    show("By price: ", view);
    sortView(view, 0);
    show("By rating:", view);
    printf("Original first item still: %s\n", items[0].name);
    printf("Swapped %d bytes per move instead of %d\n", (int)sizeof(Product *), (int)sizeof(Product));
    return 0;
}
