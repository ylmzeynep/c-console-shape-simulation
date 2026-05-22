#ifndef MAHALLE_H
#define MAHALLE_H

#include "Yerlesim.h"
#include "Kisi.h"

typedef struct {
    Yerlesim super;

    Kisi** kisiler;
    int kisiSayisi;
} Mahalle;

Mahalle* mahalleOlustur(char* ad);
void mahalleKisiEkle(Mahalle* m, Kisi* k);
void mahalleYazdir(Mahalle* m);
void mahalleYokEt(Mahalle* m);

#endif