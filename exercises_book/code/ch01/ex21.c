#include <stdio.h>

int main(void) {
    int code, units, tens, hundreds, reversed;
    scanf("%d", &code);
    units = code % 10;               // رقم الآحاد
    tens = (code / 10) % 10;        // نحذف الآحاد ثم نأخذ الرقم الأخير
    hundreds = code / 100;              // رقم المئات
    reversed = units * 100 + tens * 10 + hundreds; // نعيد التركيب بالترتيب المعاكس
    printf("Code %d -> %d\n", code, reversed);
    return 0;
}
