int i;
for (i = 1; i <= 10; i++) {
    if (i == 3) continue;   /* skip 3 */
    if (i == 6) break;      /* stop at 6 */
    printf("%d ", i);
}
