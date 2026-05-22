#ifndef SEHIR_H
#define SEHIR_H

#include "Yerlesim.h"
#include "Ilce.h"

typedef struct {
    Yerlesim super;

    Ilce** ilceler;
    int ilceSayisi;
} Sehir;

Sehir* sehirOlustur(char* ad);
void sehirIlceEkle(Sehir* s, Ilce* i);
void sehirYazdir(Sehir* s);
void sehirYokEt(Sehir* s);

#endif