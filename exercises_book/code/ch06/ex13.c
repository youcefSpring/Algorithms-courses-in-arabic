#include <stdio.h>

int main(void) {
    char name[] = "sAMSUNG gALAXY s24 ULTRA";
    int pos, start = 1;
    for (pos = 0; name[pos] != '\0'; pos++) {
        if (name[pos] == ' ') {
            start = 1;                    // الكلمة التالية تبدأ بعد الفراغ
        } else if (start) {
            if (name[pos] >= 'a' && name[pos] <= 'z')
                name[pos] -= 'a' - 'A';   // أول حرف: كبير
            start = 0;
        } else if (name[pos] >= 'A' && name[pos] <= 'Z') {
            name[pos] += 'a' - 'A';       // بقية الحروف: صغيرة
        }
    }
    printf("%s\n", name);
    return 0;
}
