#include <stdio.h>
#include <stdlib.h>
#include "../include/Ilce.h"

Ilce* ilceOlustur(char* ad) {
    Ilce* i = (Ilce*)malloc(sizeof(Ilce));

    yerlesimKur(&i->super, ad, 0);

    i->mahalleSayisi = 0;
    i->mahalleler = NULL;

    i->super.yazdir = (void (*)(struct YERLESIM*))ilceYazdir;

    return i;
}

void ilceMahalleEkle(Ilce* i, Mahalle* m) {
    i->mahalleSayisi++;

    i->mahalleler = (Mahalle**)realloc(i->mahalleler, sizeof(Mahalle*) * i->mahalleSayisi);
    i->mahalleler[i->mahalleSayisi - 1] = m;

    i->super.nufus += m->super.nufus;
}

void ilceYazdir(Ilce* i) {
    printf("Ilce: %s - Nufus: %d\n", i->super.ad, i->super.nufus);

    for (int j = 0; j < i->mahalleSayisi; j++) {
        i->mahalleler[j]->super.yazdir((Yerlesim*)i->mahalleler[j]);
    }
}

void ilceYokEt(Ilce* i) {
    for (int j = 0; j < i->mahalleSayisi; j++) {
        mahalleYokEt(i->mahalleler[j]);
    }

    free(i->mahalleler);
    free(i);
}