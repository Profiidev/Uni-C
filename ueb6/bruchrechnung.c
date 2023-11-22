/*******************************************************************/
// Programm    : Bruchrechnung
// Verfasser   : Schmidt
// Datum       : Urprogramm: 24.10.2012
// Eingabe     : 2 rationale Zahlen
// Verarbeitung: Produkt, Quotient, Summe und Differenz der
// 				 rationalen Zahlen
// Ausgabe	   : Ergebnisse der Operationen
// Änderungen  : 24.10.2012
//				 19.11.2023 (Jurgovsky)
// *******************************************************************/

/* Einbinden von nötigen Header-Dateien                             */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include "rational.h" /* Funktionsprototypen und Datentypen */


int bruchrechnung(void) {
    struct bruch_s b1;
    struct bruch_s b2;

    printf("Bitte Zaehler und Nenner Bruch 1 eingeben: \n");
    scanf("%d %d", &b1.zaehler, &b1.nenner);
    printf("Bitte Zaehler und Nenner Bruch 2 eingeben: \n");
    scanf("%d %d", &b2.zaehler, &b2.nenner);

    struct bruch_s result_add = add(b1, b2);
    struct bruch_s result_sub = sub(b1, b2);
    struct bruch_s result_mul = mul(b1, b2);
    struct bruch_s result_div = div(b1, b2);

    printf("%d / %d + %d / %d = %d / %d\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, result_add.zaehler, result_add.nenner);
    printf("%d / %d - %d / %d = %d / %d\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, result_sub.zaehler, result_sub.nenner);
    printf("%d / %d * %d / %d = %d / %d\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, result_mul.zaehler, result_mul.nenner);
    printf("%d / %d / %d / %d = %d / %d\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, result_div.zaehler, result_div.nenner);

    return 0;
}



