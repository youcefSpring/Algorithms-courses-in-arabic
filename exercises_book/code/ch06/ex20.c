#include <stdio.h>

int main(void) {
    char text[] = "This seller is a scam, total scam! scampi is fine.";
    char banned[] = "scam";
    int start, match, pos, before, after;
    for (start = 0; text[start] != '\0'; start++) {
        match = 0;
        while (banned[match] != '\0' && text[start + match] == banned[match])
            match++;
        if (banned[match] != '\0')
            continue;                         // لا تطابق
        before = (start > 0) ? text[start - 1] : ' ';
        after = text[start + match];
        // حدود كلمة: ما قبلها وما بعدها ليسا حرفين
        if (!((before >= 'a' && before <= 'z') || (before >= 'A' && before <= 'Z')) &&
            !((after >= 'a' && after <= 'z') || (after >= 'A' && after <= 'Z')))
            for (pos = start; pos < start + match; pos++)
                text[pos] = '*';
    }
    printf("%s\n", text);
    return 0;
}
