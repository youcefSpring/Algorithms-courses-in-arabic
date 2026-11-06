#include <stdio.h>

#define TIMEOUT 1800
#define MAXU 10

typedef struct { int id; long start, last; int pages, sessions, totalPages; long totalTime; } UserState;

UserState users[MAXU];
int nbUsers = 0;
FILE *out;

void closeSession(UserState *user) {
    fprintf(out, "user %d: %ld -> %ld (%ld s, %d pages)\n", user->id, user->start, user->last,
            user->last - user->start, user->pages);
    user->sessions++;
    user->totalPages += user->pages;
    user->totalTime += user->last - user->start;
}

int main(void) {
    FILE *file = fopen("clicks.log", "w");
    long data[14][2] = {{0, 7}, {60, 7}, {200, 9}, {400, 7}, {500, 9}, {2100, 9}, {2600, 7},
                        {2700, 7}, {2900, 9}, {5000, 7}, {5100, 9}, {5200, 7}, {7300, 9}, {7400, 9}};
    char page[20];
    long time;
    int idx, userId, ch;
    for (idx = 0; idx < 14; idx++) fprintf(file, "%ld %ld /p%d\n", data[idx][0], data[idx][1], idx);
    fclose(file);
    file = fopen("clicks.log", "r");
    out = fopen("sessions.txt", "w");
    while (fscanf(file, "%ld %d %19s", &time, &userId, page) == 3) {
        for (idx = 0; idx < nbUsers && users[idx].id != userId; idx++) {}
        if (idx == nbUsers) {                                  // مستخدم جديد
            users[idx].id = userId;
            users[idx].sessions = users[idx].totalPages = 0;
            users[idx].totalTime = 0;
            users[idx].start = time;
            users[idx].pages = 0;
            nbUsers++;
        } else if (time - users[idx].last > TIMEOUT) {        // انقطاع طويل: جلسة جديدة
            closeSession(&users[idx]);
            users[idx].start = time;
            users[idx].pages = 0;
        }
        users[idx].last = time;
        users[idx].pages++;
    }
    for (idx = 0; idx < nbUsers; idx++) closeSession(&users[idx]);
    fclose(file);
    fclose(out);
    out = fopen("sessions.txt", "r");
    while ((ch = fgetc(out)) != EOF) putchar(ch);
    fclose(out);
    for (idx = 0; idx < nbUsers; idx++)
        printf("user %d: %d sessions, avg %.1f s, avg %.1f pages\n", users[idx].id, users[idx].sessions,
               (double)users[idx].totalTime / users[idx].sessions,
               (double)users[idx].totalPages / users[idx].sessions);
    return 0;
}
