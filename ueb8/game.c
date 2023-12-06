#include <stdio.h>  	/* Standard Input/Output  z.B. scanf, printf */
#include <stdbool.h> 	/* 'bool' als Datentyp und Macros für 'true' und 'false' */
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "game.h"

/*
 * Konstanten
 */
const char DISP_UNKNOWN              = '?';
const char DISP_KNOWN_IMPOSSIBLE     = '.';
const char DISP_KNOWN_ORACLE         = 'X';
const char DISP_KNOWN_GUESSED        = '!';
const char DISP_KNOWN_GUESSED_ORACLE = '$';

int ueb8() {
    line(100, '-');
    printf("Guessing Game\n");
    line(100, '-');

    guessingGame(ORACLE_VALUE_MIN, ORACLE_VALUE_MAX);

    return 0;
}


void guessingGame(const int oracleValueMin, const int oracleValueMax) {

    const int oracleValueRange = oracleValueMax - oracleValueMin;
    const int displaySize = oracleValueRange + 1;

    char display[displaySize + 1]; // reserve space for Null-terminator symbol
    initializeDisplay(display, displaySize);

    unsigned char retry = 'j';

    // TODO: Zufallsgenerator initialisieren
    srand((unsigned int)time(0));

    do {
        // TODO: Erzeuge eine Zufallszahl im Intervall [oracleValueMin, oracleValueMax] anstatt der 42.
        int oracleValue = rand() % oracleValueRange + oracleValueMin;

        printf("Ich habe mir eine Zahl zwischen %d und %d ausgedacht. Welche ist es?\n",
               oracleValueMin,
               oracleValueMax
        );

        initializeDisplay(display, displaySize);
        showDisplay(display);

        // TODO: Funktion 'guess' implementieren
        guess(oracleValue, display, oracleValueMin, oracleValueMax);

        printf("Möchtest du erneut spielen? (j/n)\n");
        while(getchar() != '\n');
        scanf("%c", &retry);
        retry = tolower(retry);

    } while(retry == 'j');
}


void guess(int oracleValue, char * display, int oracleValueMin, int oracleValueMax) {

    int remaining_guesses = N_GUESSES;
    int guessedValue = 0;
    bool fWon = false;

    // TODO: Diese Funktion soll den Nutzer wiederholt nach einer Zahl fragen und das Spiel,
    //  wie im Übungsblatt gezeigt, durchführen. Die Funktion kehrt zurück sobald der Nutzer die Zahl erraten oder
    //  seine Versuche aufgebraucht hat.
    while (remaining_guesses > 0 && !fWon) {
        if (guessedValue == oracleValue) {
            fWon = true;
        } else {
            remaining_guesses--;
            scanf("%d", &guessedValue);
            if(guessedValue > oracleValue) {
                printf("Die Zahl ist zu groß!\n");
            } else if (guessedValue < oracleValue) {
                printf("Die Zahl ist zu klein!\n");
            }
            updateDisplay(display, guessedValue, oracleValue, remaining_guesses, oracleValueMin, oracleValueMax);
            showDisplay(display);
        }
    }
    if (fWon) {
        printf("Du hast gewonnen!\n");
    } else {
        printf("Du hast deine %d Versuche aufgebraucht. Die Zahl war %d.\n", N_GUESSES, oracleValue);
    }
}


void initializeDisplay(char * display, const int sizeOfDisplay) {
    for(int i = 0; i < sizeOfDisplay; i++) {
        display[i] = DISP_UNKNOWN;
    }
    display[sizeOfDisplay] = '\0';
}

void updateDisplay(char * display, int guess, int oracle, int remainingGuesses, int oracleValueMin, int oracleValueMax) {

    // Größe des arrays 'display' ist n; Index von 0 bis n-1
    unsigned long n = strlen(display);

    // guess in [oracleValueMin, oracleValueMax] ?
    if (guess < oracleValueMin || guess > oracleValueMax) {
        return;
    }

    // TODO: Setze die Zeichen im Display entsprechend der aktuellen Spielsituation.
    //  'updateDisplay' soll nach jedem Rateversuch aus der Funktion guess heraus aufgerufen werden.

    // Based on the guess and oracle, set numbers with state UNKNOWN to state KNOWN_IMPOSSIBLE
    display[guess - oracleValueMin] = DISP_KNOWN_GUESSED;
    for (int i = 0; i < n; i++) {
        if (display[i] == DISP_UNKNOWN) {
            if (i < guess - oracleValueMin && guess < oracle) {
                display[i] = DISP_KNOWN_IMPOSSIBLE;
            } else if (i > guess - oracleValueMin && guess > oracle) {
                display[i] = DISP_KNOWN_IMPOSSIBLE;
            }
        }
    }

    // If this was the user's last guess, reveal the oracle's number
    if (remainingGuesses == 0) {
        display[oracle - oracleValueMin] = DISP_KNOWN_ORACLE;
    }

    // In any case, if the guess was correct: Reveal oracle's number
    if (guess == oracle) {
        display[guess - oracleValueMin] = DISP_KNOWN_GUESSED_ORACLE;
    }
}

void showDisplay(char * display) {
    printf("| %s |\n", display);
}


void line(int n, char c)
{
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
}

