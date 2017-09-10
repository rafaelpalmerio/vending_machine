#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED


/************************
 mostraMsg
 Mostra mensagem na tela.
 entradas
   char* mensagem
 saidas
   nenhuma
*************************/
extern void mostraMsg(char* msg);

/************************
 mostraSaldo
 Mostra saldo na tela.
 entradas
   float saldo
 saidas
   nenhuma
*************************/
extern void mostraPreco(float preco);

/************************
 mostraPreco
 Mostra preco na tela.
 entradas
   float preco
 saidas
   nenhuma
*************************/
extern void mostraSaldo(float saldo);

/************************
 mostraEstoque
 Mostra estoque na tela.
 entradas
   float estoque
 saidas
   nenhuma
*************************/
extern void mostraEstoque(int estoque);
#endif // display_H_INCLUDED

