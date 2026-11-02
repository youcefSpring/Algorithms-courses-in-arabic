#include <stdio.h>

#define NB_CAT 6

int main(void) {
    double first[NB_CAT]  = {5, 0, 2, 8, 1, 0};   // مشتريات الزبون الأول
    double second[NB_CAT] = {4, 1, 3, 6, 0, 0};   // الزبون الثاني
    double dot = 0, sq1 = 0, sq2 = 0, product, root;
    int cat, step;
    for (cat = 0; cat < NB_CAT; cat++) {
        dot += first[cat] * second[cat];      // الجداء السلمي
        sq1 += first[cat] * first[cat];
        sq2 += second[cat] * second[cat];
    }
    product = sq1 * sq2;
    root = product;                           // جذر product بطريقة نيوتن
    for (step = 0; step < 40; step++)
        root = (root + product / root) / 2;
    printf("Dot = %.0f, norms product = %.4f\n", dot, root);
    printf("Cosine similarity = %.4f\n", dot / root);
    return 0;
}
