#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void resztaInit(int n, char reszta[n]) {
    for (int i = 0; i<n; i++)
        reszta[i] = 'E';
}

int main()
{
    int n, check = 1, at = 0, stop = 0, istack=0, ireszta = 0;// kodczerwony = 0;// isubmit = 0;
    char ciag[200], stack[10][20], ogolne[3][20], reszta[20];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i<n; i++) {
        scanf("%c", &ciag[i]);
        getchar();
        //printf("%c ", ciag[i]);
        ciag[i+1] ='E';
    }
    resztaInit(20, reszta);
    while (check) {
        if (ciag[at] == 'S') {
            at++;
            for (int i = 0; i<3; i++) {
                while (!stop) {
                    if (ciag[at] == 'S' ){
                        strcpy(stack[istack], "S");
                        istack++;
                    } else if (ciag[at] == 'K') {
                        strcpy(stack[istack], "K");
                        istack++;
                    } else if (ciag[at] == 'E') {

                        //kodczerwony = 1;
                        stop = 1;
                        exit(1);


                    } else {
                        if (istack == 1) stop = 1;
                        else {
                            strcat(stack[istack-2], stack[istack-1]);
                            strcat(stack[istack-2], "@");
                            istack--;
                        }

                    }
                    at++;
                }
                strcpy(ogolne[i], stack[0]);
                istack = 0;
                stop = 0;
            }

            while(ciag[at] != 'E') {
                reszta[ireszta] = ciag[at];
                at++;
                ireszta++;
            }

            strcpy(ciag, ogolne[0]);
            strcat(ciag, ogolne[2]);
            strcat(ciag, "@");
            strcat(ciag, ogolne[1]);
            strcat(ciag, ogolne[2]);
            strcat(ciag, "@@");
            strcat(ciag, reszta);
            strcat(ciag, "E");
            //dodac reszte

            int i = 0;
            while (ciag[i] != 'E') {
                printf("%c ", ciag[i]);
                i++;
            }
            resztaInit(20, reszta);
            printf("\n");
        } else if(ciag[at] == 'K') {
            at++;
            for (int i = 0; i<2; i++) {
                while (!stop) {
                    if (ciag[at] == 'S' ){
                        strcpy(stack[istack], "S");
                        istack++;
                    } else if (ciag[at] == 'K') {
                        strcpy(stack[istack], "K");
                        istack++;
                    } else if (ciag[at] == 'E') {

                        //kodczerwony = 1;
                        printf("xd");
                        stop = 1;
                        exit(1);


                    } else {
                        if (istack == 1) stop = 1;
                        else {
                            strcat(stack[istack-2], stack[istack-1]);
                            strcat(stack[istack-2], "@");
                            istack--;
                        }

                    }
                    at++;
                }
                strcpy(ogolne[i], stack[0]);
                istack = 0;
                stop = 0;
            }

            while(ciag[at] != 'E') {
                reszta[ireszta] = ciag[at];
                at++;
                ireszta++;
            }

            strcpy(ciag, ogolne[0]);
            strcat(ciag, reszta);
            strcat(ciag, "E");
            //dodac reszte

            int i = 0;
            while (ciag[i] != 'E') {
                printf("%c ", ciag[i]);
                i++;
            }
            resztaInit(20, reszta);
            printf("\n");




        }
        at = 0;
        istack = 0;
        check++;
        ireszta = 0;
        //if (check == 8) check = 0;

    }
    return 0;
}
