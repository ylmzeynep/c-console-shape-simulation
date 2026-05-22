#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Oyun.h"

char* dosyadanAdGetir(const char* dosyaAdi) {
    static FILE* sehirFile = NULL;
    static FILE* ilceFile = NULL;
    static FILE* mahalleFile = NULL;

    FILE** file = NULL;

    if (strstr(dosyaAdi, "sehir") != NULL) {
        file = &sehirFile;
    }
    else if (strstr(dosyaAdi, "ilce") != NULL) {
        file = &ilceFile;
    }
    else if (strstr(dosyaAdi, "mahalle") != NULL) {
        file = &mahalleFile;
    }

    if (file == NULL) {
        char* yedek = (char*)malloc(20);
        strcpy(yedek, "IsimYok");
        return yedek;
    }

    if (*file == NULL) {
        *file = fopen(dosyaAdi, "r");

        if (*file == NULL) {
            char* yedek = (char*)malloc(20);
            strcpy(yedek, "IsimYok");
            return yedek;
        }
    }

    char satir[50];

    if (fgets(satir, sizeof(satir), *file) == NULL) {
        rewind(*file);
        fgets(satir, sizeof(satir), *file);
    }

    satir[strcspn(satir, "\n")] = '\0';

    char* ad = (char*)malloc(strlen(satir) + 1);
    strcpy(ad, satir);

    return ad;
}

Sehir* sayidanSehirOlustur(int sayi) {

    int ilce = sayi / 10;
    int mahalle = sayi % 10;

    if (mahalle == 0) {
        mahalle = ilce;
    }
    else if (mahalle % ilce != 0) {

        int bulundu = 0;

        for (int d = mahalle; d <= 9; d++) {
            if (d % ilce == 0) {
                mahalle = d;
                bulundu = 1;
                break;
            }
        }

        if (!bulundu) {
            for (int d = 1; d <= 9; d++) {
                if (d % ilce == 0) {
                    mahalle = d;
                    break;
                }
            }
        }
    }

    int nufus = ilce * 10 + mahalle;

    while (nufus % mahalle != 0) {
        nufus++;
    }

    int mahalleBasina = nufus / mahalle;
    int mahallePerIlce = mahalle / ilce;

    char* sehirAd = dosyadanAdGetir("data/sehirler.txt");
    Sehir* s = sehirOlustur(sehirAd);
    free(sehirAd);

    for (int i = 0; i < ilce; i++) {

        char* ilceAd = dosyadanAdGetir("data/ilceler.txt");
        Ilce* il = ilceOlustur(ilceAd);
        free(ilceAd);

        for (int j = 0; j < mahallePerIlce; j++) {

            char* mahalleAd = dosyadanAdGetir("data/mahalleler.txt");
            Mahalle* m = mahalleOlustur(mahalleAd);
            free(mahalleAd);

            for (int k = 0; k < mahalleBasina; k++) {
                Kisi* kisi = dosyadanKisiGetir();
                mahalleKisiEkle(m, kisi);
            }

            ilceMahalleEkle(il, m);
        }

        sehirIlceEkle(s, il);
    }

    return s;
}

Oyun* oyunOlustur() {
    Oyun* oyun = (Oyun*)malloc(sizeof(Oyun));

    oyun->sehirler = NULL;
    oyun->sehirSayisi = 0;

    return oyun;
}

void oyunSehirEkle(Oyun* oyun, Sehir* sehir) {
    oyun->sehirSayisi++;

    oyun->sehirler = (Sehir**)realloc(
        oyun->sehirler,
        sizeof(Sehir*) * oyun->sehirSayisi
    );

    oyun->sehirler[oyun->sehirSayisi - 1] = sehir;
}

void oyunSehirleriYazdir(Oyun* oyun) {
    for (int i = 0; i < oyun->sehirSayisi; i++) {
        printf("[%d]", oyun->sehirler[i]->super.nufus);

        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
        else if (i != oyun->sehirSayisi - 1) {
            printf("-");
        }
    }

    printf("\n");
}

void turCalistir(Oyun* oyun) {

    for (int i = 0; i < oyun->sehirSayisi; i++) {

        Sehir* s = oyun->sehirler[i];

        int nufus = s->super.nufus;
        int onlar = (nufus / 10) % 10;
        int birler = nufus % 10;
        int katsayi = onlar + birler;

        for (int j = 0; j < s->ilceSayisi; j++) {

            Ilce* il = s->ilceler[j];

            for (int k = 0; k < il->mahalleSayisi; k++) {

                Mahalle* m = il->mahalleler[k];

                for (int x = 0; x < m->kisiSayisi; x++) {
                    m->kisiler[x]->yas++;
                }

                if (katsayi == 0) {
                    Kisi* kisi = dosyadanKisiGetir();
                    mahalleKisiEkle(m, kisi);
                }
                else {
                    int eski = m->super.nufus;
                    int yeni = eski * katsayi;
                    int eklenecek = yeni - eski;

                    for (int x = 0; x < eklenecek; x++) {
                        Kisi* kisi = dosyadanKisiGetir();
                        mahalleKisiEkle(m, kisi);
                    }
                }
            }

            il->super.nufus = 0;
            for (int k = 0; k < il->mahalleSayisi; k++) {
                il->super.nufus += il->mahalleler[k]->super.nufus;
            }
        }

        s->super.nufus = 0;
        for (int j = 0; j < s->ilceSayisi; j++) {
            s->super.nufus += s->ilceler[j]->super.nufus;
        }
    }
}

void sehirBol(Oyun* oyun) {

    int eskiSayi = oyun->sehirSayisi;

    for (int i = 0; i < eskiSayi; i++) {

        Sehir* s = oyun->sehirler[i];

        if (s->super.nufus >= 1000) {

            char* yeniSehirAd = dosyadanAdGetir("data/sehirler.txt");
            Sehir* yeni = sehirOlustur(yeniSehirAd);
            free(yeniSehirAd);

            if (s->ilceSayisi > 1) {

                int yeniIlceSayisi = s->ilceSayisi / 2;

                for (int j = 0; j < yeniIlceSayisi; j++) {

                    Ilce* tasinacak = s->ilceler[s->ilceSayisi - 1];

                    yeni->ilceSayisi++;
                    yeni->ilceler = realloc(
                        yeni->ilceler,
                        sizeof(Ilce*) * yeni->ilceSayisi
                    );

                    yeni->ilceler[yeni->ilceSayisi - 1] = tasinacak;

                    s->ilceSayisi--;
                }
            }
            else {

                Ilce* eskiIlce = s->ilceler[0];

                char* yeniIlceAd = dosyadanAdGetir("data/ilceler.txt");
                Ilce* yeniIlce = ilceOlustur(yeniIlceAd);
                free(yeniIlceAd);

                if (eskiIlce->mahalleSayisi > 1) {

                    int yeniMahalleSayisi = eskiIlce->mahalleSayisi / 2;

                    for (int j = 0; j < yeniMahalleSayisi; j++) {

                        Mahalle* tasinacak = eskiIlce->mahalleler[eskiIlce->mahalleSayisi - 1];

                        yeniIlce->mahalleSayisi++;
                        yeniIlce->mahalleler = realloc(
                            yeniIlce->mahalleler,
                            sizeof(Mahalle*) * yeniIlce->mahalleSayisi
                        );

                        yeniIlce->mahalleler[yeniIlce->mahalleSayisi - 1] = tasinacak;

                        eskiIlce->mahalleSayisi--;
                    }
                }
                else {

                    Mahalle* eskiMahalle = eskiIlce->mahalleler[0];

                    char* yeniMahalleAd = dosyadanAdGetir("data/mahalleler.txt");
                    Mahalle* yeniMahalle = mahalleOlustur(yeniMahalleAd);
                    free(yeniMahalleAd);

                    int tasinacakKisi = (eskiMahalle->kisiSayisi + 1) / 2;

                    for (int k = 0; k < tasinacakKisi; k++) {

                        Kisi* tasinan = eskiMahalle->kisiler[eskiMahalle->kisiSayisi - 1];

                        eskiMahalle->kisiSayisi--;
                        eskiMahalle->super.nufus--;

                        mahalleKisiEkle(yeniMahalle, tasinan);
                    }

                    ilceMahalleEkle(yeniIlce, yeniMahalle);
                }

                eskiIlce->super.nufus = 0;
                for (int j = 0; j < eskiIlce->mahalleSayisi; j++) {
                    eskiIlce->super.nufus += eskiIlce->mahalleler[j]->super.nufus;
                }

                yeniIlce->super.nufus = 0;
                for (int j = 0; j < yeniIlce->mahalleSayisi; j++) {
                    yeniIlce->super.nufus += yeniIlce->mahalleler[j]->super.nufus;
                }

                sehirIlceEkle(yeni, yeniIlce);
            }

            s->super.nufus = 0;
            for (int j = 0; j < s->ilceSayisi; j++) {
                s->super.nufus += s->ilceler[j]->super.nufus;
            }

            yeni->super.nufus = 0;
            for (int j = 0; j < yeni->ilceSayisi; j++) {
                yeni->super.nufus += yeni->ilceler[j]->super.nufus;
            }

            oyunSehirEkle(oyun, yeni);
        }
    }
}

void secilenSehriYazdir(Oyun* oyun, int satir, int sutun) {

    int index = satir * 5 + sutun;

    if (index < 0 || index >= oyun->sehirSayisi) {
        printf("Gecersiz secim\n");
        return;
    }

    Sehir* s = oyun->sehirler[index];

    printf("\n");
    s->super.yazdir((Yerlesim*)s);
}

void oyunYokEt(Oyun* oyun) {
    for (int i = 0; i < oyun->sehirSayisi; i++) {
        sehirYokEt(oyun->sehirler[i]);
    }

    free(oyun->sehirler);
    free(oyun);
}