#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

#define NUM_PROD 3
extern const char const * matriz_p[15];

/************************
 consultaNome
 Retorna o nome do produto na posicao especificada
 entradas
   int posicao
 saidas
   char* nome_produto
*************************/
extern char* consultaNome(int posicao);

/************************
 consultaPreco
 Retorna o preco do produto na posicao especificada
 entradas
   int posicao
 saidas
   float preco
*************************/
extern float consultaPreco(int posicao);

extern int consultaEstoque(int posicao);

#endif // ESTOQUE_H_INCLUDED
