/*******************************************************************
// Programm    : Primzahlen
// Verfasser   : Schmidt
// Datum       : Urprogramm: 13.11.2012
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
// 				 06.12.2023 (Jurgovsky)
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>
#include "prime.h"


void sieve(int markers[], int N) {
    for(int i = 2; i < N; i++) {
        markers[i] = PRIME;
    }
    for (int i = 2; i < floor(sqrt(N)); i++) {
        for(int j = i * 2; j < N; j += i) {
            if (j % i == 0) {
                markers[j] = NOT_PRIME;
            }
        }
    }
}


void show(const int markers[], int N) {
    printf("Primzahlen von 1 bis %d:\n", N - 1);
    for (int i = 1; i < N; i++) {
        if (markers[i] == PRIME) {
            printf("%d, ", i);
        }
    }
}
