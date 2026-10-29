#include <stdio.h>

typedef struct { char model[15]; int battery; } Phone;

void useApp(Phone *p, int cost) {
    p->battery -= cost;
    if (p->battery < 0) p->battery = 0;
}

int main(void) {
    Phone ph = {"Galaxy", 80};
    useApp(&ph, 25);     /* video call */
    useApp(&ph, 40);     /* game */
    printf("%s: %d %%\n", ph.model, ph.battery);
    return 0;
}
