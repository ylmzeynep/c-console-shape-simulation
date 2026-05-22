#ifndef OYUN_H
#define OYUN_H

#include "Sehir.h"

typedef struct {
    Sehir** sehirler;
    int sehirSayisi;
} Oyun;

Sehir* sayidanSehirOlustur(int sayi);

Oyun* oyunOlustur();
void oyunSehirEkle(Oyun* oyun, Sehir* sehir);
void oyunSehirleriYazdir(Oyun* oyun);
void oyunYokEt(Oyun* oyun);
void turCalistir(Oyun* oyun);
void sehirBol(Oyun* oyun);
void secilenSehriYazdir(Oyun* oyun, int satir, int sutun);

#endif