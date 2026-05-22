#include <string.h>
#include "../include/Yerlesim.h"

void yerlesimKur(Yerlesim* y, char* ad, int nufus) {
    strcpy(y->ad, ad);
    y->nufus = nufus;
    y->yazdir = 0;
    y->yokEt = 0;
}