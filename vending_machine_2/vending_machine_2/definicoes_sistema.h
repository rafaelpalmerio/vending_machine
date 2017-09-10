
#ifndef DEFINICOES_SISTEMA_H_INCLUDED
#define DEFINICOES_SISTEMA_H_INCLUDED

#define true  1
#define false 0


#define NUM_ESTADOS 5
#define NUM_EVENTOS 8

// ESTADOS
#define ESPERA      0
#define OPERANDO    1
#define VERIFICANDO 2
#define CONFIRMANDO 3
#define MANUTENCAO   4

// EVENTOS
#define NENHUM_EVENTO  -1
#define CANCELAR        0
#define DEPOSITAR_DIN   1
#define ESCOLHER_PROD   2
#define CONFIRMAR       3
#define SALDO_INS       4
#define SALDO_SUF       5
#define DEPOSITAR_TROCO 6
#define SEL_REESTOQUE   7
#define TERMINAR_M      8
#define SEM_ESTOQUE     9

// ACOES
#define NENHUMA_ACAO -1
#define A00  0
#define A01  1
#define A02  2
#define A03  3
#define A04  4
#define A05  5
#define A06  6
#define A07  7
#define A08  8
#define A09  9
#define A10 10



#endif // DEFINICOES_SISTEMA_H_INCLUDED
