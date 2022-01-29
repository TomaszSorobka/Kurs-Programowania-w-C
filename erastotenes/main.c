#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// specyfikacja: WEJSCIE:n - liczba naturalna
// WYJSCIE: liczby pierwsze z przedzialu [2,n]
//zl: pamieciowa O(n)
//zl: obliczeniowa sqrt(n)*n

int erastotenesSiev(int n) {
    int a[1000] = {[0 ... 999] = 1};
    if (n<2) return -1;
    for (int i = 2; i<sqrt(n); i++) {
        if (a[i]) {
            for (int j = i*i; j<n; j+=i)
                a[j] = 0;
        }
    }
    for (int i = 2; i<n+1; i++) {
        if (a[i]) printf("%d ", i);
    }
    return 1;
}


int main()
{
    int n = 123;
    erastotenesSiev(n);
    return 0;
}
