#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Tomasz Soróbka 332034
zad 1 lista 9 */

void skopiuj(FILE *zfp,FILE *dofp, int liczbawierszy){
    int c, licznikwierszy = 0;
    while((c=getc(zfp)) != EOF && licznikwierszy != liczbawierszy) {
        putc(c,dofp);
        if (c == '\n') licznikwierszy++;
    }
    if (c == EOF) fprintf(dofp, "\n");
}

int ileWierszy(FILE *plik){
    char znak = getc(plik);
    int wiersze = 1;
    while (znak != EOF) {
        if (znak == '\n') wiersze++;
        znak = getc(plik);
    }
    return wiersze;
}

int main (int argc, char*argv[]) {
   FILE *wynikowy, *plik1;
   int n;
   char z[100], d[100];

   if (argc >= 3) {
        strcpy(z, argv[1]);
        sscanf(argv[2], "%d", &n);
    } else {
        printf("Brak argumentow \n"); return 1;
    }
    wynikowy = fopen(z, "w+");
    if (wynikowy == NULL) exit(1);

    for (int i = 3; i<argc; i++) {
        strcpy(d, argv[i]);
        plik1 = fopen(d, "r+");
        if (plik1 == NULL) printf("Brak pliku %s", argv[i]);
        else {
            fprintf(wynikowy, "\n%s(%d)\n", argv[i], ileWierszy(plik1));
            rewind(plik1);
            skopiuj(plik1, wynikowy, n);
        }
        fclose(plik1);
    }
   fclose(wynikowy);
   return(0);
}
