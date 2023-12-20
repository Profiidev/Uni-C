//*******************************************************************
// Programm    : stats
// Verfasser   : Hüttl/ Feindor / Schmidt / Jurgovsky
// Übungsbeispiel für:
//               Kommandozeilen Argumente und
//               dynamische Speicherverwaltung
// Verarbeitung: Kommandozeilen-Argumente werden ausgewertet
//               umkopiert und in der Reihenfolge vertauscht.
// Datum       : 1.11.2002
// Änderungen  : 4.12.2012
//				13.12.2023
//*******************************************************************


#include <stdlib.h>		/* Standardfunktionen für Speicherverwaltung	*/
#include "util.h"
#include <stdio.h>

int ueb10(int argc, char * argv[])
{
    printf("Number of arguments: %d\n", argc);
    for(int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");

    // Aufgabe 1
    statistics(argv, argc);

    // Aufgabe 2
    reverse(argv, argc);

    return EXIT_SUCCESS;
}