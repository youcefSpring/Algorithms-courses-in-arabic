FILE *f = fopen("missing.txt", "r");
fscanf(f, "%d", &x);     /* crash if f == NULL */
/* fclose(f) forgotten: data may be lost */
