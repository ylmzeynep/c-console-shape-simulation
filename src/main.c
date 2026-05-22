#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Oyun.h"
#include <locale.h>

int main() {

    setlocale(LC_ALL, "");

    Oyun* oyun = oyunOlustur();

    int tur;
    char satir[500];

    printf("Tur sayisini giriniz:\n");
    scanf("%d", &tur);
    getchar();

    printf("Sehir verilerini giriniz:\n");
    fgets(satir, sizeof(satir), stdin);

    char* parca = strtok(satir, " \n\r");

    while (parca != NULL) {
        int sayi = atoi(parca);

        Sehir* sehir = sayidanSehirOlustur(sayi);
        oyunSehirEkle(oyun, sehir);

        parca = strtok(NULL, " \n\r");
    }

    printf("\nBaslangic:\n");
    oyunSehirleriYazdir(oyun);

    for (int t = 0; t < tur; t++) {
        turCalistir(oyun);

        sehirBol(oyun);   // 🔥 TAM BURAYA

        system("cls");

        printf("\n%d. Tur:\n", t + 1);
        oyunSehirleriYazdir(oyun);
    }

    int secSatir, secSutun;

    printf("\nSatir giriniz: ");
    scanf("%d", &secSatir);

    printf("Sutun giriniz: ");
    scanf("%d", &secSutun);

    secilenSehriYazdir(oyun, secSatir, secSutun);

    printf("\nCikmak icin Enter'a basiniz...");
    getchar();
    getchar();

    oyunYokEt(oyun);

    return 0;
}