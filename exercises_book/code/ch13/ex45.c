#include <stdio.h>

#define NBD 16
#define INF 1000000000

int prices[NBD] = {320, 335, 310, 345, 300, 290, 315, 280, 295, 305, 330, 285, 300, 310, 325, 340};
int tree[4 * NBD], visits;

int minOf(int first, int second) { return first < second ? first : second; }

void build(int node, int low, int high) {
    int middle = (low + high) / 2;
    if (low == high) { tree[node] = prices[low]; return; }          // ورقة = يوم
    build(2 * node, low, middle);
    build(2 * node + 1, middle + 1, high);
    tree[node] = minOf(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int low, int high, int from, int to) {
    int middle = (low + high) / 2;
    visits++;
    if (to < low || high < from) return INF;                        // خارج المجال
    if (from <= low && high <= to) return tree[node];               // داخل المجال كليًا
    return minOf(query(2 * node, low, middle, from, to), query(2 * node + 1, middle + 1, high, from, to));
}

void update(int node, int low, int high, int day, int value) {
    int middle = (low + high) / 2;
    if (low == high) { tree[node] = value; return; }
    if (day <= middle) update(2 * node, low, middle, day, value);
    else update(2 * node + 1, middle + 1, high, day, value);
    tree[node] = minOf(tree[2 * node], tree[2 * node + 1]);         // نحدث الأسلاف
}

void ask(int from, int to) {
    int result;
    visits = 0;
    result = query(1, 0, NBD - 1, from, to);
    printf("min price days %2d-%2d: %d (visited %d nodes)\n", from + 1, to + 1, result, visits);
}

int main(void) {
    build(1, 0, NBD - 1);
    ask(0, 15);
    ask(0, 4);
    ask(8, 13);
    update(1, 0, NBD - 1, 10, 260);
    printf("flash sale: day 11 -> 260\n");
    ask(8, 13);
    ask(2, 9);
    return 0;
}
