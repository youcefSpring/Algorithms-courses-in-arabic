#include <stdio.h>
#include <ctype.h>

int main(void) {
    char name[] = "amina benali";
    int i;
    for (i = 0; name[i] != '\0'; i++)
        name[i] = toupper(name[i]);
    printf("Patient: %s\n", name);
    return 0;
}
