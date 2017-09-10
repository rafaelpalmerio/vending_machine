#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "display.h"

/************************
 mostraMsg
 Mostra mensagem na tela.
 entradas
   char* msg
 saidas
   nenhuma
*************************/
void mostraMsg(char* msg)
{
    printf("Mensagem para display: %s\n", msg);
}
/************************
 mostraSaldo
 Mostra saldo na tela.
 entradas
   float saldo
 saidas
   nenhuma
*************************/
void mostraSaldo(float saldo)
{
    printf("Saldo atual: R$%.2f\n", saldo);
}

/************************
 mostraPreco
 Mostra preco na tela.
 entradas
   float preco
 saidas
   nenhuma
*************************/
void mostraPreco(float preco)
{
    printf("Preco: R$%.2f\n", preco);
}

void mostraEstoque(int estoque){
    printf("Estoque: %2d\n", estoque);
}
