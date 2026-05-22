#ifndef KISI_H
#define KISI_H

typedef struct {
    int id;
    char ad[50];
    char soyad[50];
    int yas;
} Kisi;

Kisi* kisiOlustur(int id, char* ad, char* soyad, int yas);
Kisi* dosyadanKisiGetir();

void kisiYazdir(Kisi* k);
void kisiYokEt(Kisi* k);

#endif