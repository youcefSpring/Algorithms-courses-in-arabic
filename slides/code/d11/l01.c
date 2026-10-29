FILE *f = fopen("data.txt", "r");
if (f == NULL) {
    printf("Cannot open file\n");
    return 1;
}
/* ... use the file ... */
fclose(f);
