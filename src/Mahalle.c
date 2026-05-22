#include <stdio.h>
#include <stdlib.h>
#include "../include/Mahalle.h"

Mahalle* mahalleOlustur(char* ad) {
    Mahalle* m = (Mahalle*)malloc(sizeof(Mahalle));

    yerlesimKur(&m->super, ad, 0);

    m->kisiSayisi = 0;
    m->kisiler = NULL;

    m->super.yazdir = (void (*)(struct YERLESIM*))mahalleYazdir;
    
    return m;
}

void mahalleKisiEkle(Mahalle* m, Kisi* k) {
    m->kisiSayisi++;

    m->kisiler = (Kisi**)realloc(m->kisiler, sizeof(Kisi*) * m->kisiSayisi);
    m->kisiler[m->kisiSayisi - 1] = k;

    m->super.nufus++;
}

void mahalleYazdir(Mahalle* m) {
    printf("Mahalle: %s - Nufus: %d\n", m->super.ad, m->super.nufus);
    printf("Kisiler:\n");

    for (int i = 0; i < m->kisiSayisi; i++) {
        kisiYazdir(m->kisiler[i]);
    }
}

void mahalleYokEt(Mahalle* m) {
    for (int i = 0; i < m->kisiSayisi; i++) {
        kisiYokEt(m->kisiler[i]);
    }

    free(m->kisiler);
    free(m);
}