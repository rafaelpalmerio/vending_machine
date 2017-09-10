#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "dispenser_moedas.h"

#define TIPOS_MOEDAS 4

#define QNT_10 1
#define QNT_25 4
#define QNT_50 4
#define QNT_100 4

float moedas[2][TIPOS_MOEDAS]={{QNT_100,QNT_50,QNT_25,QNT_10},{1,0.5,0.25,0.1}};

/************************
 insereMoeda
 contabiliza uma moeda inserida e atualiza o saldo
 entradas
   float saldo
 saidas
   float saldo_novo
*************************/
float insereMoeda(float saldo)
{
    float saldo_novo;
    saldo_novo=saldo+0.1;
    moedas[0][3]=moedas[0][3]+1;
    return (saldo_novo);

}

/************************
 devolveTroco
 calcula quanto deve ser o troco e devolve
 entradas
   float saldo
   float preco
 saidas
   void
*************************/
void devolveTroco(float saldo, float preco)
{   float numero;
    float quantia=saldo-preco;
    printf("Quantia a ser devolvida: %.2f \n",quantia);
    if (quantia>0.01){
        numero = quantia/0.1;
        printf("Serão devolvidas %.0f moedas de 10 centavos", numero);
    }
    numero = saldo/0.1;
    moedas[0][3]=moedas[0][3]+numero;
    numero = 0;


}

/************************
 verificaSaldo
 verifica se o saldo e suficiente para comprar o produto selecionado
 entradas
   float saldo
   float preco
 saidas
    1 - suficiente
    0 - insuficiente
*************************/
int verificaSaldo(float saldo, float preco)
{
    if (saldo>=preco)
    {
        return (1);
    }
    else
    {
        return(0);
    }
}

/************************
 insereTroco
 contabiliza uma moeda a mais para troco inserida e atualiza a disponibilidade
 entradas
   void
 saidas
   int qnt_moedas
*************************/
void insereTroco()
{   moedas[0][3]=moedas[0][3]+1;
    int n=moedas[0][3];
    printf("Total de moedas de R$0.10: %d.\n",n);
}
