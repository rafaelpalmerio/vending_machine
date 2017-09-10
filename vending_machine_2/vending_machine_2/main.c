#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Vending Machine - Rafael Pereira Piza Palmerio - 8582936
*/

#include "definicoes_sistema.h"
#include "dispenser_moedas.h"
#include "dispenser_produtos.h"
#include "display.h"
#include "estoque.h"
#include "teclado.h"

/***********************************************************************
 Estaticos
 ***********************************************************************/
  int codigoEvento;
  int codigoAcao;
  float saldo=0;
  int qnt_moeda=0;
  char string_aux[30];
  char* pointer_aux;
  int prod_sel=0;
  int saldo_suf=0;
  int acao_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
  int proximo_estado_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
  bool estado4 = false;

/************************************************************************
 executarAcao
 Executa uma acao
 Parametros de entrada:
    (int) codigo da acao a ser executada
 Retorno: (int) codigo do evento interno ou NENHUM_EVENTO
*************************************************************************/
int executarAcao(int codigoAcao)
{
    int retval;

    retval = NENHUM_EVENTO;
    if (codigoAcao == NENHUMA_ACAO)
        return retval;

    switch(codigoAcao)
    {
    case A00:
        printf("#######################Seja Bem-Vindo!!##########################\n");
        printf("#Posicao         Produto               Preco           Unidades #\n");
        printf("#    1           Telefone celular      R$1,30          %d       #\n", consultaEstoque(1));
        printf("#    2           Salgado               R$0,40          %d       #\n", consultaEstoque(2));
        printf("#    3           Chocolate             R$0,50          %d       #\n", consultaEstoque(3));
        printf("#    4           Brinquedo             R$1,00          %d       #\n", consultaEstoque(4));
        printf("#################################################################\n");
        printf("Adicione moedas de 10 centavos (R$0,10) com a tecla '+' .\n");
        printf("Escolha um produto com as teclas de 1 a 4.\n");
        printf("Confirme a selecao e a liberacao do produto com a tecla 's'.\n");
        printf("Cancele com a tecla 'x'.\n");
        printf("Recarregue uma moeda de troco na maquina com a tecla 't'.\n");
        printf("Recarregue o estoque de produtos com a tecla 'r'. \n\n\n");
        break;
    case A01:
        saldo=insereMoeda(saldo);
        mostraSaldo(saldo);

        break;
    case A02:
        mostraMsg("Compra cancelada.");
        devolveTroco(saldo,0);
        saldo=0;
        break;
        //cancelar a compra
    case A03:
        pointer_aux=consultaNome(prod_sel);
        mostraMsg("\n\nProduto selecionado:");
        //printf(pointer_aux);
        mostraMsg(pointer_aux);
        mostraPreco(consultaPreco(prod_sel));
        mostraEstoque(consultaEstoque(prod_sel));
        break;
    case A04:
        mostraMsg("\n\nProduto selecionado !");

        if (verificaSaldo(saldo,consultaPreco(prod_sel))==1)
        {
            saldo_suf=1;
        }
        else
        {
            saldo_suf=2;
        }
        break;
    case A05:
        mostraMsg("\n\nSaldo suficiente !");
        liberaProduto(prod_sel);
        saldo_suf=0;
        break;
    case A06:
        mostraMsg("\n\nSaldo insuficiente !");
        saldo_suf=0;
        break;
    case A07:
        desacionaMotor(prod_sel);
        mostraSaldo(saldo);
        mostraPreco(consultaPreco(prod_sel));
        mostraMsg("\n\nDevolvendo troco ...");
        devolveTroco(saldo,consultaPreco(prod_sel));
        AtualizaEstoque(prod_sel);
        saldo=0;
        printf("#######################Seja Bem-Vindo!!##########################\n");
        printf("#Posicao         Produto               Preco           Unidades #\n");
        printf("#    1           Telefone celular      R$1,30          %d       #\n", consultaEstoque(1));
        printf("#    2           Salgado               R$0,40          %d       #\n", consultaEstoque(2));
        printf("#    3           Chocolate             R$0,50          %d       #\n", consultaEstoque(3));
        printf("#    4           Brinquedo             R$1,00          %d       #\n", consultaEstoque(4));
        printf("#################################################################\n");
        printf("Adicione moedas de 10 centavos (R$0,10) com a tecla '+' .\n");
        printf("Escolha um produto com as teclas de 1 a 4.\n");
        printf("Confirme a selecao e a liberacao do produto com a tecla 's'.\n");
        printf("Cancele com a tecla 'x'.\n");
        printf("Recarregue uma moeda de troco na maquina com a tecla 't'.\n");
        printf("Recarregue o estoque de produtos com a tecla 'r'. \n\n\n");
        break;
    case A08:
        insereTroco();
        break;
    case A09:
        reestoque();
        codigoEvento = TERMINAR_M;
        break;
    case A10:
        printf("Produto Indisponível. Selecione outro produto apertando seu codigo.\n\n");
        break;
    }// switch

    return retval;
} // executarAcao

/************************************************************************
 iniciaMaquina de Estados
 Carrega a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
void iniciaMaquinaEstados()
{
  int i;
  int j;

  for (i=0; i < NUM_ESTADOS; i++) {
    for (j=0; j < NUM_EVENTOS; j++) {
       acao_matrizTransicaoEstados[i][j] = NENHUMA_ACAO;
       proximo_estado_matrizTransicaoEstados[i][j] = i;
    }
  }
  proximo_estado_matrizTransicaoEstados[ESPERA][NENHUM_EVENTO] = ESPERA;
  acao_matrizTransicaoEstados[ESPERA][NENHUM_EVENTO] = A00;

  proximo_estado_matrizTransicaoEstados[ESPERA][CANCELAR] = ESPERA;
  acao_matrizTransicaoEstados[ESPERA][CANCELAR] = A00;

  proximo_estado_matrizTransicaoEstados[ESPERA][DEPOSITAR_TROCO] = ESPERA;
  acao_matrizTransicaoEstados[ESPERA][DEPOSITAR_TROCO] = A08;

  proximo_estado_matrizTransicaoEstados[ESPERA][ESCOLHER_PROD] = ESPERA;
  acao_matrizTransicaoEstados[ESPERA][ESCOLHER_PROD] = A03;

  proximo_estado_matrizTransicaoEstados[ESPERA][DEPOSITAR_DIN] = OPERANDO;
  acao_matrizTransicaoEstados[ESPERA][DEPOSITAR_DIN] = A01;

  proximo_estado_matrizTransicaoEstados[OPERANDO][CANCELAR] = ESPERA;
  acao_matrizTransicaoEstados[OPERANDO][CANCELAR] = A02;

  proximo_estado_matrizTransicaoEstados[OPERANDO][DEPOSITAR_DIN] = OPERANDO;
  acao_matrizTransicaoEstados[OPERANDO][DEPOSITAR_DIN] = A01;

  proximo_estado_matrizTransicaoEstados[OPERANDO][ESCOLHER_PROD] = OPERANDO;
  acao_matrizTransicaoEstados[OPERANDO][ESCOLHER_PROD] = A03;

  proximo_estado_matrizTransicaoEstados[OPERANDO][CONFIRMAR] = VERIFICANDO;
  acao_matrizTransicaoEstados[OPERANDO][CONFIRMAR] = A04;

  proximo_estado_matrizTransicaoEstados[VERIFICANDO][SALDO_INS] = OPERANDO;
  acao_matrizTransicaoEstados[VERIFICANDO][SALDO_INS] = A06;

  proximo_estado_matrizTransicaoEstados[VERIFICANDO][SEM_ESTOQUE] = OPERANDO;
  acao_matrizTransicaoEstados[VERIFICANDO][SEM_ESTOQUE] = A10;


  proximo_estado_matrizTransicaoEstados[VERIFICANDO][SALDO_SUF] = CONFIRMANDO;
  acao_matrizTransicaoEstados[VERIFICANDO][SALDO_SUF] = A05;

  proximo_estado_matrizTransicaoEstados[CONFIRMANDO][CONFIRMAR] = ESPERA;
  acao_matrizTransicaoEstados[CONFIRMANDO][CONFIRMAR] = A07;

  proximo_estado_matrizTransicaoEstados[ESPERA][SEL_REESTOQUE] = MANUTENCAO;
  acao_matrizTransicaoEstados[ESPERA][SEL_REESTOQUE] = A09;

  proximo_estado_matrizTransicaoEstados[MANUTENCAO][TERMINAR_M] = ESPERA;
  acao_matrizTransicaoEstados[MANUTENCAO][TERMINAR_M] = A00;


} // initStateMachine

/************************************************************************
 iniciaSistema
 Inicia o sistema ...
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
void iniciaSistema()
{
   iniciaMaquinaEstados();
} // initSystem


/************************************************************************
 obterEvento
 Obtem um evento
 Parametros de entrada: nenhum
 Retorno: codigo do evento
*************************************************************************/
char* teclas;

int decodificarDepositarDin()
{
    if (teclas[0] == '+')
    {
        return true;
    }
    return false;
}//decodificarAcionar

int decodificarCancelar()
{
    if (teclas[0] == 'x')
    {
        return true;
    }
    return false;
}

int decodificarEscolherProd()
{
    if (teclas[0] == '1' || teclas[0] == '2' || teclas[0] == '3' || teclas[0] == '4')
    {
        if (teclas[0] == '1')
            prod_sel = 1;
        else if (teclas[0] == '2')
            prod_sel = 2;
        else if (teclas[0] == '3')
            prod_sel = 3;
        else if (teclas[0] == '4')
            prod_sel = 4;
        return true;
    }
    return false;
}

int decodificarConfirmar(){
    if (teclas[0] == 's')
    {
        return true;
    }
    return false;
}

int decodificarDepositarTroco()
{
    if (teclas[0] == 't')
    {
        return true;
    }
    return false;
}
int decodificarSemEstoque(){
    if(consultaEstoque(prod_sel)==0){
        return true;
    }

    return false;
}

int decodificarManutencao(){

    if (teclas[0] == 'r'){
        return true;

    }
    return false;
}

int decodificarTermino_M(){
    return true;
    return false;

}

int obterEvento()
{
  int retval = NENHUM_EVENTO;
  if (saldo_suf==1){
    return SALDO_SUF;
  }
  if (saldo_suf==2){
    return SALDO_INS;
  }

  teclas = recebeTexto();

  if (decodificarDepositarDin())
    return DEPOSITAR_DIN;
  if (decodificarCancelar())
    return CANCELAR;
  if (decodificarEscolherProd())
    return ESCOLHER_PROD;
  if (decodificarSemEstoque())
    return SEM_ESTOQUE;
  if (decodificarConfirmar())
    return CONFIRMAR;
  if (decodificarDepositarTroco())
    return DEPOSITAR_TROCO;
  if (decodificarManutencao())
    return SEL_REESTOQUE;
  else if (decodificarTermino_M())
    return TERMINAR_M;


  return retval;

} // obterEvento

/************************************************************************
 obterAcao
 Obtem uma acao da Matriz de transicao de estados
 Parametros de entrada: estado (int)
                        evento (int)
 Retorno: codigo da acao
*************************************************************************/
int obterAcao(int estado, int codigoEvento) {
  return acao_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao


/************************************************************************
 obterProximoEstado
 Obtem o proximo estado da Matriz de transicao de estados
 Parametros de entrada: estado (int)
                        evento (int)
 Retorno: codigo do estado
*************************************************************************/
int obterProximoEstado(int estado, int codigoEvento) {
  return proximo_estado_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao


/************************************************************************
 Main
 Loop principal de controle que executa a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
int main() {

  int codigoEvento;
  int codigoAcao;
  int estado;
  int eventoInterno;

  estado = ESPERA;
  eventoInterno = NENHUM_EVENTO;

  iniciaSistema();
  printf ("Vending Machine Ligada.\n");
  printf("#######################Seja Bem-Vindo!!##########################\n");
  printf("#Posicao         Produto               Preco           Unidades #\n");
        printf("#    1           Telefone celular      R$1,30          %d       #\n", consultaEstoque(1));
        printf("#    2           Salgado               R$0,40          %d       #\n", consultaEstoque(2));
        printf("#    3           Chocolate             R$0,50          %d       #\n", consultaEstoque(3));
        printf("#    4           Brinquedo             R$1,00          %d       #\n", consultaEstoque(4));
        printf("#################################################################\n");
  printf("Adicione moedas de 10 centavos (R$0,10) com a tecla '+' .\n");
  printf("Escolha um produto com as teclas de 1 a 4.\n");
  printf("Confirme a selecao e a liberacao do produto com a tecla 's'.\n");
  printf("Cancele com a tecla 'x'.\n");
  printf("Recarregue uma moeda de troco na maquina com a tecla 't'.\n");
  printf("Recarregue o estoque de produtos com a tecla 'r'. \n\n\n");
  while (true) {
    if (eventoInterno == NENHUM_EVENTO) {
        codigoEvento = obterEvento();
    } else {
        codigoEvento = eventoInterno;
    }
    if (codigoEvento != NENHUM_EVENTO)
    {
       codigoAcao = obterAcao(estado, codigoEvento);
       estado = obterProximoEstado(estado, codigoEvento);
       eventoInterno = executarAcao(codigoAcao);
       printf("Estado: %d Evento: %d Acao:%d\n", estado, codigoEvento, codigoAcao);
    }
  } // while true
} // main
