#include "util.h"
#include <stdio.h>  	/* Standard Input/Output  z.B. scanf, printf	*/
#include <string.h>  	/* Standardfunktionen für String-Operationen	*/
#include <ctype.h>      /* Standardfunktionen für Zeichentypen          */
#include <stdlib.h>     /* Standardfunktionen für Speicherverwaltung    */

void statistics(char * argv[], int argc) {

    int histogram[BINS] = {};

    // durch argumente und Zeichen iterieren -> Häufigkeit erhöhen
    // prüfe ob zeichen alphanumerisch (isalnum())

    // histogramm ausgeben (Zeichenhäufigkeit > 0)

    for(int i = 1; i < argc; ++i) {
        for(int j = 0; j < strlen(argv[i]); j++) {
            if(isalnum(argv[i][j])) {
                histogram[argv[i][j]]++;
            }
        }
    }

    for(int i = 0; i < BINS; i++) {
        if(histogram[i] > 0) {
            printf("%c: %d, ", i, histogram[i]);
        }
    }
    printf("\n");
}


void reverse(char * argv[], int argc) {

    int nWords = argc - 1;

    // Speicher für deep-copy von argv allozieren (e.g. malloc)
    char* *copy = (char**)malloc(nWords * sizeof(char*));

    for (int i = 1; i < argc; ++i) {
        // Speicher für jede Zeichenkette argv[i] allozieren
        // ...und pointer in 'copy' ablegen.
        // Anschließend Zeichenkette argv[i] nach copy[i-1] kopieren.
        copy[i-1] = (char*)malloc(strlen(argv[i]) * sizeof(char));
        strcpy(copy[i-1], argv[i]);
    }

    // Wörter in der Kopie ausgeben
    for(int i = 0; i < nWords; i++) {
        printf("%s ", copy[i]);
    }
    printf("\n");

    // Reihenfolge der Wörter in Kopie umdrehen

    for(int i = 0; i < nWords/2; i++) {
        char* temp = copy[i];
        copy[i] = copy[nWords - i - 1];
        copy[nWords - i - 1] = temp;
    }

    // Wörter erneut ausgeben

    for(int i = 0; i < nWords; i++) {
        printf("%s ", copy[i]);
    }

    // Speicher der Kopie freigeben

    for(int i = 0; i < nWords; i++) {
        free(copy[i]);
    }
    free(copy);
}