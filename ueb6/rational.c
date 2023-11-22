#include "rational.h"

struct bruch_s add(struct bruch_s bruch1, struct bruch_s bruch2) {
    struct bruch_s result;

    result.zaehler = bruch1.zaehler * bruch2.nenner + bruch2.zaehler * bruch1.nenner;
    result.nenner = bruch1.nenner * bruch2.nenner;

    return kuerzen(result);
}

struct bruch_s sub(struct bruch_s bruch1, struct bruch_s bruch2) {
    struct bruch_s result;

    result.zaehler = bruch1.zaehler * bruch2.nenner - bruch2.zaehler * bruch1.nenner;
    result.nenner = bruch1.nenner * bruch2.nenner;

    return kuerzen(result);
}

struct bruch_s mul(struct bruch_s bruch1, struct bruch_s bruch2) {
    struct bruch_s result;

    result.zaehler = bruch1.zaehler * bruch2.zaehler;
    result.nenner = bruch1.nenner * bruch2.nenner;

    return kuerzen(result);
}

struct bruch_s div(struct bruch_s bruch1, struct bruch_s bruch2) {
    struct bruch_s result;
    struct bruch_s tmp;

    tmp.zaehler = bruch2.nenner;
    tmp.nenner = bruch2.zaehler;

    result = mul(bruch1, tmp);

    return kuerzen(result);
}

struct bruch_s kuerzen(struct bruch_s bruch) {
    struct bruch_s result;

    int teiler;

    if(bruch.zaehler >= bruch.nenner) {
        teiler = ggT(bruch.zaehler, bruch.nenner);
    } else {
        teiler = ggT(bruch.nenner, bruch.zaehler);
    }

    result.zaehler = bruch.zaehler / teiler;
    result.nenner = bruch.nenner / teiler;

    return result;
}

/**
 * Berechnet ggT von a und b nach euklidischem Algorithmus
 * Wichtig: beim Start muss gelten: a >= b
 */
int ggT(int a, int b)
{
    int ret;

    if(b == 0) {
        ret = a;
    } else {
        ret = ggT(b, a % b);
    }

    return ret;
}

