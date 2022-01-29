#include <stdio.h>
#include <stdlib.h>
#include "kolejka.h"

/* Tomasz Soróbka
zad 1 lista 6
332034 */
int main()
{
    int rozmiar;
    scanf("%d", &rozmiar);
    KolWsk kol;

    //testy, wszystkie funckje nalepiej widac ze sa poprawne dla malych rozmiarow, ale oczywiscie dziala dla wiekszych rowniez
    kol = inicjalizacja(rozmiar);
    dodajLiczbe(kol, 1);
    dodajLiczbe(kol, 2);
    dodajLiczbe(kol, 3);
    wypiszKolejke(kol);
    dodajLiczbe(kol, 4);
    wypiszKolejke(kol);
    pobierzLiczbe(kol);
    pobierzLiczbe(kol);
    pobierzLiczbe(kol);
    printf("\nLiczba elementow: %d", ileElem(kol));
    dodajLiczbe(kol, 1);
    dodajLiczbe(kol, 2.5);
    printf("\nLiczba elementow: %d", ileElem(kol));
    wypiszKolejke(kol);
    oproznianieKolejki(kol);
    wypiszKolejke(kol);
    printf("\nLiczba elementow: %d", ileElem(kol));
    if(!czyPusta(kol)) printf("Kolejka nie jest pusta.");
    else printf("\nKolejka jest pusta.");
    return 0;
}
