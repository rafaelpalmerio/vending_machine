#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "teclado.h"

/************************
 recebeTexto
 Recebe texto do teclado
 entradas
   nenhuma
 saidas
   tecla lida do teclado ou NENHUMA_TECLA
*************************/

char buf[10];
char* recebeTexto()
{
    printf("Digite:");
    scanf("%s", buf);
    return buf;
}
