#ifndef DISPENSER_PRODUTOS_H_INCLUDED
#define DISPENSER_PRODUTOS_H_INCLUDED

/*******************************
 liberaProduto
 Aciona o motor para entregar o produto escolhido pelo argumento da funcao.
 entradas
   int posicao
 saidas
   nenhuma
********************************/
extern void liberaProduto(int posicao);

/*******************************
 desacionaMotor
 Desaciona o motor para entregar o produto escolhido pelo argumento da funcao.
 entradas
   int posicao
 saidas
   nenhuma
********************************/
extern void desacionaMotor(int posicao);



#endif // DISPENSER_PRODUTOS_H_INCLUDED
