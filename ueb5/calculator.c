/**
 * ************************************************************
 * Eigenwilliger Taschenrechner
 * ************************************************************
 * Datum: 3.11.2023
 * Autor: Jurgovsky
 * Thema: Einfache Funktionen
 *
 * Aufgabe: Vervollständigen Sie die Funktion 'calculator' um
 *  folgende Größen zu berechnen:
 *      (a + b)^2
 *      (a - b)^2
 *      a^2 - b^2
 *
 *  Aus mysteriösen Gründen gelten folgende Einschränkungen:
 *  - !!!In der Funktion 'calculator'!!! dürfen KEINE arithmetischen
 *    Operatoren verwendet werden: + - / *.
 *  - Die Verwendung von Schleifen ist strengstens untersagt.
 *  - Die Verwendung der math-library scheidet völlig aus.
 *
 *  Ihr Vorgänger hatte bereits mit der Implementierung begonnen.
 *  Er machte sich jedoch vor Fertigstellung aus dem Staub.
 *  Lagern Sie die Funktionsdeklaration von 'csum' in die
 *  Headerdatei helper.h aus und implementieren Sie sie in helper.c.
 *
 *  Sollten Sie zusätzliche Funktionen definieren wollen, lagern
 *  Sie auch diese in helper.h und helper.c aus.
 *
 *  Zusatzaufgabe: Erweitern Sie Implementierung so, dass die
 *  oben genannten Größen mit beliebigem (positiven) Exponenten
 *  berechnet werden können. Sie können dazu die Konstante
 *  'EXP' verwenden.
 */
#include <stdio.h>
#include "helper.h"


void strich(int n, char c);
int calculator();

int calculator() {

    double a = 0.0;
    double b = 0.0;
    int exp = 0;

    double result_apbs = 0.0;    // Variable für Ergebnis aus (a+b)^2
    double result_ambs = 0.0;    // Variable für Ergebnis aus (a-b)^2
    double result_asmbs = 0.0;   // Variable für Ergebnis aus (a^2 - b^2)

    int scanf_ret = 0;
    int scanf_ret_exp = 0;

    printf("Bitte zwei Zahlen eingeben: \n");
    scanf_ret = scanf("%lf %lf", &a, &b);

    if (scanf_ret != 2) {
        return -1;
    }

    printf("Bitte Exponenten eingeben: \n");
    scanf_ret_exp = scanf("%d", &exp);

    if (scanf_ret_exp != 1) {
        return -1;
    }

    // TODO
    // (a + b)^2 = ?
    result_apbs = cpow2(exp, csum(a, b), 1.0);


    // TODO
    // (a - b)^2 = ?
    result_ambs = cpow2(exp, csum(a, negate(b)), 1.0);

    // TODO
    // (a^2 - b^2) = ?
    result_asmbs = csum(cpow2(exp, a, 1.0), negate(cpow2(exp, b, 1.0)));

    strich(65, '-');
    printf("Eigenwilliger Taschenrechner\n");
    strich(65, '-');
    printf("(%.2f + %.2f)^2 =     %10.2f\n", a, b, result_apbs);
    printf("(%.2f - %.2f)^2 =     %10.2f\n", a, b, result_ambs);
    printf("(%.2f ^2 - %.2f ^2) = %10.2f\n", a, b, result_asmbs);
    strich(65, '-');

    return 0;
}


void strich(int n, char c) {
    for(int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
}

