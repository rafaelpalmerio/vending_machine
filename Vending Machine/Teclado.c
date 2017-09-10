#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int i = 0;
int j = 0;
int k = 0;
char recarga[20];
char codigo[4];
int moedas = 0;
char *m;
int teclado(){
            moedas = 0;
            fgets(recarga, 20, stdin);
            while(recarga[i+1]!=0){
                i++;
            }
            if(i==3){
                moedas+=1;
            }
            while(i>0){
                k = recarga[j] - '0';
                moedas += k*pow(10,(i-1));
                i--;
                j++;
            }
            i = 0;
            j = 0;
            return moedas;
        }

void teclado2(){
    fgets(codigo, 100, stdin);

}
