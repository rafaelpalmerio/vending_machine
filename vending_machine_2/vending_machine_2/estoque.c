#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "estoque.h"

#define NUM_PROD 4
const char const * matriz_nome[15]={"Celular", "Salgado", "Chocolate", "Brinquedo"};
const float matriz_preco[NUM_PROD]={1.3,0.4,0.5,1.0};
volatile int matriz_estoque[NUM_PROD] = {10, 10, 10, 10};

/************************
 consultaNome
 Retorna o nome do produto na posicao especificada
 entradas
   int posicao
 saidas
   char* nome_produto
*************************/
char* consultaNome(int posicao)
{
    char* nome_produto;
    nome_produto=matriz_nome[posicao-1];
    //printf(nome_produto);
    return nome_produto;
}

/************************
 consultaPreco
 Retorna o preco do produto na posicao especificada
 entradas
   int posicao
 saidas
   float preco
*************************/
float consultaPreco(int posicao)
{
    float preco=matriz_preco[posicao-1];
    return preco;}

/************************
 consultaEstoque
 Retorna o estoque do produto na posicao especificada
 entradas
   int posicao
 saidas
   int estoque
*************************/

int consultaEstoque(int posicao){
    int estoque = matriz_estoque[posicao-1];
    return estoque;
}
char tecla[10];
void reestoque(){
    printf("Foi escolhido o reestoque.\n\n");
    int m = 0;
    while(m<=3){
        printf("Digite quantas unidades do produto %d deseja adicionar (entre 1 e 4): ",m+1);
        printf("\n\n");
        scanf("%s", tecla);
        switch(tecla[0]){
        case '1':
            matriz_estoque[m] =matriz_estoque[m]+1;
            break;
        case '2':
            matriz_estoque[m] +=2;
            break;
        case '3':
            matriz_estoque[m] +=3;
            break;
        case '4':
            matriz_estoque[m] +=4;
            break;
        default:
            matriz_estoque[m] +=0;
            break;
        }
        m++;
    }
    m = 0;
    while(m<=3){
        printf("Há %d unidades do produto %d \n\n",  matriz_estoque[m], m+1);
        m++;
    }
    printf("Pressione 'c' para continuar. \n\n\n\n");
}
void AtualizaEstoque(int prod_sel){
    matriz_estoque[prod_sel-1] -=1;
}
