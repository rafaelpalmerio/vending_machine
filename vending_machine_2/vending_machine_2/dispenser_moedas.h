#ifndef DISPENSER_MOEDAS_H_INCLUDED
#define DISPENSER_MOEDAS_H_INCLUDED


/************************
 insereMoeda
 contabiliza uma moeda inserida e atualiza o saldo
 entradas
   float saldo
 saidas
   float saldo_novo
*************************/
extern float insereMoeda(float saldo);

/************************
 devolveTroco
 calcula quanto deve ser o troco e devolve
 entradas
   float saldo
   float preco
 saidas
   void
*************************/
extern void devolveTroco(float saldo, float preco);

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
extern int verificaSaldo(float saldo, float preco);

/************************
 insereTroco
 contabiliza uma moeda a mais para troco inserida e atualiza a disponibilidade
 entradas
   void
 saidas
   void
*************************/
extern void insereTroco();
#endif // DISPENSER_MOEDAS_H_INCLUDED

