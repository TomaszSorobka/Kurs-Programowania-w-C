#ifndef KOLEJKA_H_INCLUDED
#define KOLEJKA_H_INCLUDED

typedef struct kolejka *KolWsk;
KolWsk inicjalizacja(int rozmiar);
void wypiszKolejke(KolWsk kol);
void dodajLiczbe(KolWsk kol, double n);
int ileElem(KolWsk kol);
int czyPusta(KolWsk kol);
double pobierzLiczbe(KolWsk kol);
void oproznianieKolejki(KolWsk kol);
#endif // KOLEJKA_H_INCLUDED
