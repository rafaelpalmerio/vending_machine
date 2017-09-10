#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "dispenser_produtos.h"

/*******************************
 liberaProduto
 Aciona o motor para entregar o produto escolhido pelo argumento da funcao.
 entradas
   int posicao
 saidas
   nenhuma
********************************/
 void liberaProduto(int posicao)
 {
     printf("Acionando motor da posicao %d para liberar produto ... \n", posicao);
 }

 /*******************************
 desacionaMotor
 Desaciona o motor para entregar o produto escolhido pelo argumento da funcao.
 entradas
   int posicao
 saidas
   nenhuma
********************************/
void desacionaMotor(int posicao)
{
    printf("Desacionando motor da posicao %d ... \n", posicao);

}
