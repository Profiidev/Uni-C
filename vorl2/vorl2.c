#include "vorl2.h"
#include <stdio.h>

#define CITY_NAME_LENGTH 100
#define COUNTRY_NAME_LENGTH 100

struct GeoPos_s {
    float x;
    float y;
};

struct City_s {
    char cityName[CITY_NAME_LENGTH];
    struct GeoPos_s geoPos;
    int zip;
    long inhabitants;
    char country[COUNTRY_NAME_LENGTH];
};

void printGeoPos(struct GeoPos_s geoPos) {
    printf("x: %f, y: %f\n", geoPos.x, geoPos.y);
};

void printCity(struct City_s city) {
    printf("City: %s\n", city.cityName);
    printf("GeoPos: ");
    printGeoPos(city.geoPos);
    printf("Zip: %d\n", city.zip);
    printf("Inhabitants: %ld\n", city.inhabitants);
    printf("Country: %s\n", city.country);
};

int vorl2() {
    struct City_s city = {
        "Berlin",
        {52.520008, 13.404954},
        10178,
        3520031,
        "Germany"
    };
    printCity(city);
    return 0;
}