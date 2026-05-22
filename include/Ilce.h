#ifndef ILCE_H
#define ILCE_H

#include "Yerlesim.h"
#include "Mahalle.h"

typedef struct {
    Yerlesim super;

    Mahalle** mahalleler;
    int mahalleSayisi;
} Ilce;

Ilce* ilceOlustur(char* ad);
void ilceMahalleEkle(Ilce* i, Mahalle* m);
void ilceYazdir(Ilce* i);
void ilceYokEt(Ilce* i);

#endif