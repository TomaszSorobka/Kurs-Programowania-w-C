#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//swap referencyjny
/* Tomasz Soróbka
332034
zadanie 1 lista 5
*/

void initialize(int n, int perm[n]) {
    int N = n;
    for (int i = 0; i<n; i++) {
        perm[i] = N;
        N--;
    }
    return;
}

void makeRoom(int n, int perm[n]) {
    for (int i = n; i>0; i--) {
        perm[i] = perm[i-1];
    }
    perm[0] = n;
    return;
}

bool nextPerm (int n, int perm[n]) {
    int pozycja = 0, zmiana, N=n;
    bool isThere = false;
    for (int i = 0; i<n; i++) {
        if (perm[i] == n) {
            pozycja = i;
            break;
        }
    }
    if (pozycja == n-1) {
        nextPerm(n-1, perm);
        makeRoom(n, perm);
    } else {
        zmiana = perm[pozycja+1];
        perm[pozycja+1] = n;
        perm[pozycja] = zmiana;
    }

    for(int i = 0; i<n; i++) {
        if (!(perm[i] == N)) {
            isThere = true;
            break;
        }
        N--;
    }
    return isThere;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *perm = (int*) malloc(n * sizeof(int));
    initialize(n, perm);
    do {
        for (int i = 0; i<n; i++) printf("%d", perm[i]);
        printf("\n");
    } while (nextPerm(n, perm));
    return 0;
}
