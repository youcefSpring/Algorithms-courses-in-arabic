#include <stdio.h>
#include <string.h>

struct Student {
    char name[30];
    int age;
    float avg;
};

int main(void) {
    struct Student s;
    strcpy(s.name, "Amina");
    s.age = 19;
    s.avg = 14.5;
    printf("%s, %d, %.2f\n", s.name, s.age, s.avg);
    return 0;
}
