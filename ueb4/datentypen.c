/* Einbinden von nötigen Header-Dateien                               */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */

char kleinstesZeichen(char c1, char c2, char c3, char c4);

char groesstesZeichen(char c1, char c2, char c3, char c4);

int ueb4() {
    char c1, c2, c3, c4;

    printf("Bitte geben Sie vier einzelne Zeichen ein: ");
    scanf("%c %c %c %c", &c1, &c2, &c3, &c4);
    printf("Eingegeben wurden: %c %c %c %c\n", c1, c2, c3, c4);
    printf("ASCII Codes: %d %d %d %d\n", c1, c2, c3, c4);
    float mittel = (c1 + c2 + c3 + c4) / 4.0f;
    printf("ASCII Codes (Mittel, int): %d\n", (int) mittel);
    printf("ASCII Codes (Mittel, hex): %x\n", (int) mittel);
    printf("ASCII Codes (Mittel, float): %f\n", mittel);
    printf("ASCII Codes (Mittel, char): %c\n", (char) mittel);
    char klein = kleinstesZeichen(c1, c2, c3, c4);
    char gross = groesstesZeichen(c1, c2, c3, c4);
    printf("Kleinstes Zeichen: %c\n", klein);
    printf("Groesstes Zeichen: %c\n", gross);
    printf("Abstand Max/Min: %d\n", gross - klein);

    return 0;
}

char kleinstesZeichen(char c1, char c2, char c3, char c4) {
    char min = c1;
    if (c2 < min) {
        min = c2;
    }
    if (c3 < min) {
        min = c3;
    }
    if (c4 < min) {
        min = c4;
    }
    return min;
}

char groesstesZeichen(char c1, char c2, char c3, char c4) {
    char max = c1;
    if (c2 > max) {
        max = c2;
    }
    if (c3 > max) {
        max = c3;
    }
    if (c4 > max) {
        max = c4;
    }
    return max;
}