#include <stdio.h>

#define MAXW 60

char vocab[MAXW][16];
int countF[MAXW], countR[MAXW], nbWords = 0;

double myLog(double value) {
    double result = 0, term, power, sum = 0;
    int rank;
    while (value > 1.5) { value /= 2.718281828459045; result += 1; }    // log(x) = 1 + log(x/e)
    while (value < 0.5) { value *= 2.718281828459045; result -= 1; }
    term = value - 1;
    power = term;
    for (rank = 1; rank < 40; rank++) { sum += (rank % 2 ? power : -power) / rank; power *= term; }
    return result + sum;
}

int wordIndex(const char *word, int add) {
    int idx, pos;
    for (idx = 0; idx < nbWords; idx++) {
        for (pos = 0; word[pos] != '\0' && word[pos] == vocab[idx][pos]; pos++) {}
        if (word[pos] == vocab[idx][pos]) return idx;
    }
    if (!add || nbWords == MAXW) return -1;
    for (pos = 0; (vocab[nbWords][pos] = word[pos]) != '\0'; pos++) {}
    countF[nbWords] = countR[nbWords] = 0;
    return nbWords++;
}

int main(void) {
    FILE *file = fopen("train.txt", "w");
    char label, word[16];
    const char *queries[3][5] = {{"best", "product", "ever", "buy", "now"},
                                 {"battery", "lasts", "two", "days", "ok"},
                                 {"amazing", "deal", "buy", "best", "fast"}};
    int docsF = 0, docsR = 0, wordsF = 0, wordsR = 0, idx, query, ch;
    double scoreF, scoreR;
    fprintf(file, "F best product ever buy now amazing\nF amazing deal best price buy\nF buy now best ever\n");
    fprintf(file, "R battery lasts one day\nR screen ok but slow delivery\nR good price fast delivery\n");
    fprintf(file, "R product works battery ok\n");
    fclose(file);
    file = fopen("train.txt", "r");
    while (fscanf(file, " %c", &label) == 1) {
        if (label == 'F') docsF++; else docsR++;
        while ((ch = fgetc(file)) != '\n' && ch != EOF) {
            if (ch == ' ') continue;
            ungetc(ch, file);
            fscanf(file, "%15s", word);
            idx = wordIndex(word, 1);
            if (label == 'F') { countF[idx]++; wordsF++; } else { countR[idx]++; wordsR++; }
        }
    }
    fclose(file);
    printf("Trained on %d fake / %d real reviews, vocabulary %d\n", docsF, docsR, nbWords);
    for (query = 0; query < 3; query++) {
        scoreF = myLog((double)docsF / (docsF + docsR));
        scoreR = myLog((double)docsR / (docsF + docsR));
        for (idx = 0; idx < 5; idx++) {
            int pos = wordIndex(queries[query][idx], 0);
            int inF = pos >= 0 ? countF[pos] : 0, inR = pos >= 0 ? countR[pos] : 0;
            scoreF += myLog((inF + 1.0) / (wordsF + nbWords));      // تنعيم لابلاس
            scoreR += myLog((inR + 1.0) / (wordsR + nbWords));
        }
        printf("\"%s %s %s %s %s\": F %.2f R %.2f -> %s\n", queries[query][0], queries[query][1],
               queries[query][2], queries[query][3], queries[query][4], scoreF, scoreR,
               scoreF > scoreR ? "FAKE" : "real");
    }
    return 0;
}
