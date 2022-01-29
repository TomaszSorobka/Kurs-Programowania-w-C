#include <stdio.h>
#include <stdlib.h>
#include "kolejka.h"

typedef struct kolejka {
    double *tab;
    int rozmiar;
    int ile_elem;
    double *poczatek, *koniec;
} Kolejka;

KolWsk inicjalizacja(int rozmiar) {
    KolWsk kol = malloc(sizeof(Kolejka));
    kol->tab = (double*)calloc(rozmiar, sizeof(double));
    if(kol->tab == NULL) {
        printf("Blad pamieci.");
        exit(0);
    }
    kol->rozmiar = rozmiar;
    kol->ile_elem = 0;
    kol->poczatek = kol->tab;
    kol->koniec = kol->tab;
    return kol;
}

void dodajLiczbe(KolWsk kol, double n) {
    int ikon = kol->koniec - kol->tab;
    int ipocz = kol->poczatek - kol->tab;
    if (kol->ile_elem == kol->rozmiar) {
        double nowaTab[kol->rozmiar];
        int pozycja = ipocz;
        for (int i = 0; i<kol->ile_elem; i++) {
            if (pozycja==kol->rozmiar) pozycja = 0;
            nowaTab[i] = kol->tab[pozycja];
            pozycja++;
        }
        kol->tab = (double*)realloc(kol->tab, 2*(kol->rozmiar)*sizeof(double));
        if(kol->tab == NULL) {
            printf("Blad pamieci.");
            exit(0);
        } else printf("\nPowiekszono pamiec 2-krotnie.");
        kol->rozmiar *=2;
        int i = 0;
        for (i = 0; i<kol->ile_elem; i++) {
            kol->tab[i] = nowaTab[i];
        }
        kol->poczatek = kol->tab;
        kol->koniec = kol->tab+i;
        ikon = kol->koniec - kol->tab;
        ipocz = kol->poczatek - kol->tab;
    }

    kol->tab[ikon] = n;
    kol->ile_elem++;
    kol->koniec++;
    if(ikon > kol->rozmiar-2) kol->koniec = kol->tab;
    printf("\n+Dodano liczbe %.1f", n);
    return;
}

int ileElem(KolWsk kol) {
    return kol->ile_elem;
}

int czyPusta(KolWsk kol) {
    if (!kol->ile_elem) return 1;
    return 0;
}

double pobierzLiczbe(KolWsk kol) {
    int ipocz = kol->poczatek - kol->tab;
    double liczba = kol->tab[ipocz];
    kol->poczatek++;
    kol->ile_elem--;
    if(ipocz > kol->rozmiar-2) kol->poczatek = kol->tab;
    printf("\n -Pobrana liczba: %.1f", liczba);
    return liczba;
}

void oproznianieKolejki(KolWsk kol) {
    kol->ile_elem = 0;
    kol->poczatek = kol->tab;
    kol->koniec = kol->tab;
    printf("\n\nKolejke oprozniono.\n");
    return;
}

void wypiszKolejke(KolWsk kol) {
    int ipocz = kol->poczatek - kol->tab;
   // int ikon = kol->koniec - kol->tab;
    int pozycja = ipocz;
    printf("\nObecny stan kolejki: ");
    if (czyPusta(kol)) printf("brak elementow w kolejce.");
    for (int i = 0; i<kol->ile_elem; i++) {
        if (pozycja==kol->rozmiar) pozycja = 0;
        printf("%.1f ", kol->tab[pozycja]);
        pozycja++;
    }
    return;
}
