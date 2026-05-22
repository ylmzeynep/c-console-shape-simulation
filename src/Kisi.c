#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Kisi.h"

Kisi* kisiOlustur(int id, char* ad, char* soyad, int yas) {
    Kisi* k = (Kisi*)malloc(sizeof(Kisi));

    k->id = id;
    strcpy(k->ad, ad);
    strcpy(k->soyad, soyad);
    k->yas = yas;

    return k;
}

Kisi* dosyadanKisiGetir() {
    static FILE* file = NULL;

    if (file == NULL) {
        file = fopen("data/kisiler.txt", "r");

        if (file == NULL) {
            printf("kisiler.txt dosyasi acilamadi!\n");
            return kisiOlustur(0, "Dosya", "Yok", 0);
        }
    }

    int id, yas;
    char ad[50], soyad[50];

    if (fscanf(file, "%d;%49[^;];%49[^;];%d\n", &id, ad, soyad, &yas) != 4) {
        rewind(file);
        fscanf(file, "%d;%49[^;];%49[^;];%d\n", &id, ad, soyad, &yas);
    }

    return kisiOlustur(id, ad, soyad, yas);
}

void kisiYazdir(Kisi* k) {
    printf("%d - %s %s - %d\n", k->id, k->ad, k->soyad, k->yas);
}

void kisiYokEt(Kisi* k) {
    free(k);
}