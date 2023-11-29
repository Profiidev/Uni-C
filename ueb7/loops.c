#include <stdio.h>
#include "loops.h"
#include <math.h>

/* Array für die Werte der Tabellenzeilen */
struct Row_s rows[MAX_LIMIT];


int ueb7(void) {

    int limit;

    line(77, '-');
    printf("Exp: Berechnung von einfachen Funktionen\n");
    line(77, '-');

    limit = readLimit(MAX_LIMIT);
    printf("%d\n", limit);

    calculateTable(limit);
    printTable(limit);

    // TODO: call function 'printTable' with limit as argument

    return 0;
}


/* Gibt n mal das Zeichen c aus */
void line(int n, char c) {
    int i;

    for (i = 1; i <= n; i++) {
        printf("%c", c);
    }

    printf("\n");
}

int readLimit(int cMax) {

    int limit = -1;

    do {
        printf("Bitte positive obere Grenze eingeben (ganzzahlig <= %d):", cMax);
        scanf("%d", &limit);

        if(! ((1 <= limit) && (limit <= cMax)) ) {
            printf("Bitte limit in [1, %d] eingeben\n", cMax);
        }
    } while(! ((1 <= limit) && (limit <= cMax)) );

    // die eingelesene Grenze zurückgeben.
    return limit;
}


void calculateTable(int limit) {
    int i;

    for(i = 1; i <= limit; i++) {
        calculateRow(i);
    }
}

int numDigits(unsigned long x) {
    return (int) log10(x) + 1;
}

void calculateRow(int i) {

    int rowIdx = i-1;

    struct Row_s row = rows[rowIdx];
    row.i = i;
    row.oneOverI = 1.0f / (double) i;
    row.sum = rowIdx == 0 ? row.oneOverI : rows[rowIdx-1].sum + row.oneOverI;
    row.iFactorial = i == 1 ? 1 : rows[rowIdx-1].iFactorial * i;
    row.oneOverIFactorial = 1.0f / (double) row.iFactorial;
    row.e = rowIdx == 0 ? 2 : rows[rowIdx-1].e + row.oneOverIFactorial;
    row.iFactorialNumDigits = numDigits(row.iFactorial);
    // TODO

    rows[i-1] = row;
}

void printTable(int limit) {
    int i;

    line(100, '-');
    //printf("i\t1/i\t\tsum\t\ti!\t\t1/i!\t\te\n");
    printf("i\t1/i\tsum\t\ti!\t\t1/i!\t\te\t\ti!-digits\n");
    line(100, '-');

    for(i = 1; i <= limit; i++) {
        struct Row_s row = rows[i-1];
        printf("%d\t%.4f\t%.7f\t%ld\t%.14f\t%.12f\t%d\n", row.i, row.oneOverI, row.sum, row.iFactorial, row.oneOverIFactorial, row.e, row.iFactorialNumDigits);
        //printf("%d\t%.4f\t%.7f\t%ld\t%.14f\t%.12f\t%d\n", row.i, row.oneOverI, row.sum, row.iFactorial, row.oneOverIFactorial, row.e, row.iFactorialNumDigits);
    }
}

