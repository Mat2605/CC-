#include "var.h"
int main(void){
    ListaInteiro LI;
    inteiro var;
    var.valor = 300;
    inicializar_lista(&LI);
    lista_vazia(&LI);
    inserir_valor(&LI,&var);
    imprimir(&LI);

    return 0;
}