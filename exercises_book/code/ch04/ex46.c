#include <stdio.h>

#define NB 15
#define NB_GROUPS 3

int main(void) {
    double spend[NB] = {12, 15, 90, 14, 52, 48, 95, 11, 55, 100, 47, 13, 88, 50, 92};
    double centers[NB_GROUPS] = {11, 50, 100};    // أصغر، وسط، أكبر
    double sum[NB_GROUPS], gap, bestGap;
    int group[NB], members[NB_GROUPS];
    int index, cluster, closest, changed, iteration = 0;
    for (index = 0; index < NB; index++)
        group[index] = -1;                // لا مجموعة بعد
    do {
        changed = 0;
        for (index = 0; index < NB; index++) {      // مرحلة الإسناد
            closest = 0;
            bestGap = -1;
            for (cluster = 0; cluster < NB_GROUPS; cluster++) {
                gap = spend[index] - centers[cluster];
                if (gap < 0) gap = -gap;
                if (bestGap < 0 || gap < bestGap) { bestGap = gap; closest = cluster; }
            }
            if (closest != group[index]) { group[index] = closest; changed++; }
        }
        for (cluster = 0; cluster < NB_GROUPS; cluster++) { sum[cluster] = 0; members[cluster] = 0; }
        for (index = 0; index < NB; index++) {      // مرحلة إعادة الحساب
            sum[group[index]] += spend[index];
            members[group[index]]++;
        }
        for (cluster = 0; cluster < NB_GROUPS; cluster++)
            if (members[cluster] > 0)
                centers[cluster] = sum[cluster] / members[cluster];
        iteration++;
    } while (changed > 0);
    printf("Converged in %d iterations\n", iteration);
    for (cluster = 0; cluster < NB_GROUPS; cluster++) {
        printf("Group %d (center %.2f):", cluster, centers[cluster]);
        for (index = 0; index < NB; index++)
            if (group[index] == cluster)
                printf(" %.0f", spend[index]);
        printf("\n");
    }
    return 0;
}
