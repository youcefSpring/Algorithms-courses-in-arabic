#include <stdio.h>

typedef struct { int major, minor, patch; } Version;

Version parseVersion(char text[]) {
    int parts[3] = {0, 0, 0}, field = 0, pos;
    Version result;
    for (pos = 0; text[pos] != '\0' && field < 3; pos++) {
        if (text[pos] == '.') field++;                       // الحقل التالي
        else parts[field] = parts[field] * 10 + (text[pos] - '0');
    }
    result.major = parts[0];
    result.minor = parts[1];
    result.patch = parts[2];
    return result;
}

int compareVersions(Version first, Version second) {
    if (first.major != second.major) return first.major - second.major;
    if (first.minor != second.minor) return first.minor - second.minor;
    return first.patch - second.patch;
}

int main(void) {
    Version latest = {2, 10, 3}, device;
    char text[20];
    int nb, idx;
    scanf("%d", &nb);
    for (idx = 0; idx < nb; idx++) {
        scanf("%19s", text);
        device = parseVersion(text);
        if (compareVersions(device, latest) < 0)
            printf("%-8s -> update to 2.10.3%s\n", text, device.major < latest.major ? " (MAJOR)" : "");
        else
            printf("%-8s -> up to date\n", text);
    }
    return 0;
}
