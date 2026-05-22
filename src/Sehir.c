#include <stdio.h>
#include <stdlib.h>
#include "../include/Sehir.h"

Sehir* sehirOlustur(char* ad) {
    Sehir* s = (Sehir*)malloc(sizeof(Sehir));

    yerlesimKur(&s->super, ad, 0);

    s->ilceSayisi = 0;
    s->ilceler = NULL;

    s->super.yazdir = (void (*)(struct YERLESIM*))sehirYazdir;

    return s;
}

void sehirIlceEkle(Sehir* s, Ilce* i) {
    s->ilceSayisi++;

    s->ilceler = (Ilce**)realloc(s->ilceler, sizeof(Ilce*) * s->ilceSayisi);
    s->ilceler[s->ilceSayisi - 1] = i;

    s->super.nufus += i->super.nufus;
}

void sehirYazdir(Sehir* s) {
    printf("Sehir: %s - Nufus: %d\n", s->super.ad, s->super.nufus);

    for (int j = 0; j < s->ilceSayisi; j++) {
        s->ilceler[j]->super.yazdir((Yerlesim*)s->ilceler[j]);
    }
}

void sehirYokEt(Sehir* s) {
    for (int j = 0; j < s->ilceSayisi; j++) {
        ilceYokEt(s->ilceler[j]);
    }

    free(s->ilceler);
    free(s);
}