#ifndef YERLESIM_H
#define YERLESIM_H

typedef struct YERLESIM {
    char ad[50];
    int nufus;

    void (*yazdir)(struct YERLESIM*);
    void (*yokEt)(struct YERLESIM*);
} Yerlesim;

void yerlesimKur(Yerlesim* y, char* ad, int nufus);

#endif