#include "C:\Users\mathe\Documents\CC++\C\Proprios\Trabalhos_PAA\TP0\.h\functions.h"
void initialize_matriz(char matriz[LINE][COLUMN]) {
    for (int i = 0; i < COLUMN; i++) {
        matriz[0][i] = '-';
        matriz[LINE - 1][i] = '-';
    }
    for (int i = 1; i < LINE - 1; i++) {
        matriz[i][0] = '|';
        matriz[i][COLUMN - 1] = '|';
    }
    for (int i = 1; i < LINE - 1; i++) {
        for (int j = 1; j < COLUMN - 1; j++) {
            matriz[i][j] = ' ';
        }
    }
}
void CopiarMatriz(char matriz[LINE][COLUMN],char matrizDemo[LINE][COLUMN]){
    for(int i = 1;i<LINE-1;i++){
        for(int j = 1;j<COLUMN;j++){
            if(matriz[i][j]!=matrizDemo[i][j]){
                matriz[i][j] = matrizDemo[i][j];
            }
        }
    }
}
void CompararMatriz(char matriz[LINE][COLUMN],char matrizDemo[LINE][COLUMN]){
    for(int i = 1;i<LINE-1;i++){
        for(int j = 1;j<COLUMN;j++){
            if(matriz[i][j]!=matrizDemo[i][j]){
                matrizDemo[i][j] = ' ';
            }
        }
    }
}
int Menu(char matriz[LINE][COLUMN],char matrizDemo[LINE][COLUMN]) {
    printf("PROGRAMA GERADOR DE ARTE\n");
    printf("=========================\n");
    initialize_matriz(matriz);
    initialize_matriz(matrizDemo);
    int EntradaUsuario, quantidadeDesenhos,NumeroPontos,NumeroMais,NumeroX,Reiniciar = 1;
    do {
        printf("[1] Desenhar '*' \n");
        printf("[2] Desenhar '+'\n");
        printf("[3] Desenhar 'X' \n");
        printf("[4] Construir Arte Mesclando As Opcoes 1, 2, 3 Aleatoriamente\n");
        printf("[5] Desenhar Estrela\n");
        printf("[6] Apresentar Desenho Final e Finalizar Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &EntradaUsuario);
        if (EntradaUsuario >= 1 && EntradaUsuario <= 5) {
                printf("\nDigite o numero de desenhos que deseja construir: ");
                scanf("%d", &quantidadeDesenhos);
                if (quantidadeDesenhos <= 0) {
                    quantidadeDesenhos = 1 + rand() % (100 - 1 + 1);
                } else if (quantidadeDesenhos > 100) {
                    quantidadeDesenhos = 100;
                }
                if(EntradaUsuario==4){
                    if(quantidadeDesenhos<3){
                        quantidadeDesenhos = 3;
                    }
                    d o{
                        NumeroPontos = 1 + rand() % (quantidadeDesenhos);
                        while((quantidadeDesenhos-1)<=NumeroPontos||NumeroPontos==quantidadeDesenhos){
                            NumeroPontos = 1 + rand() % (quantidadeDesenhos);
                        }
                        NumeroMais = 1 + rand() % ((quantidadeDesenhos - NumeroPontos));
                        while((quantidadeDesenhos - NumeroPontos - NumeroMais)==0){
                            NumeroMais = 1 + rand() % ((quantidadeDesenhos - NumeroPontos));
                        }
                        NumeroX = 1 + rand() %(quantidadeDesenhos - NumeroPontos - NumeroMais);
                    }while((NumeroPontos+NumeroMais+NumeroX)!=quantidadeDesenhos);
                }
                do{
                    switch (EntradaUsuario) {
                        case 1:
                            DesenharPonto(quantidadeDesenhos, matrizDemo);
                            break;
                        case 2:
                            DesenharSimboloMais(quantidadeDesenhos, matrizDemo);
                            break;
                        case 3:
                            DesenharX(quantidadeDesenhos,matrizDemo);
                            break;
                        case 4:
                            DesenharRandomicamente(NumeroPontos,NumeroMais,NumeroX,matrizDemo);
                            break;
                        case 5:
                            DesenharEstrela(quantidadeDesenhos,matrizDemo);
                            break;
                    }
                    Print_Matriz(matrizDemo);
                    printf("\nDeseja Refazer o Desenho? \n\tSe sim,Digite 0: \nSua resposta:  ");
                    scanf("%d",&Reiniciar);
                    if(Reiniciar==0){
                        CompararMatriz(matriz,matrizDemo);
                    }
                }while(Reiniciar==0);
                CopiarMatriz(matriz,matrizDemo);

            }else if (EntradaUsuario == 6) {
                Print_Matriz(matriz);
                return 0;
            } else {
                printf("Digite uma opcao valida: \n");
        }
    } while (1);
}

int VerificarEspacoPonto(int plus_line,int plus_column,char matriz[LINE][COLUMN]){
    if(matriz[plus_line][plus_column]==' '){
        return 1;
    }
    for(int i = 1;i<LINE-1;i++){
        for(int j = 1;j<COLUMN-1;j++){
            if(matriz[i][j]==' '){
                return -1;
            }
        }
    }
    return 0;
}

int VerificarEspacoSimboloMais(int plus_line, int plus_column, char matriz[LINE][COLUMN]) {
    if (matriz[plus_line][plus_column] == ' ' &&
        matriz[plus_line + 1][plus_column] == ' ' &&
        matriz[plus_line - 1][plus_column] == ' ' &&
        matriz[plus_line][plus_column + 1] == ' ' &&
        matriz[plus_line][plus_column - 1] == ' ') {
        return 1;
    } else {
        for(int i = 1;i<LINE-1;i++){
            for(int j = 1;j<COLUMN-1;j++){
                if (matriz[i][j] == ' ' &&
                    matriz[i + 1][j] == ' ' &&
                    matriz[i - 1][j] == ' ' &&
                    matriz[i][j + 1] == ' ' &&
                    matriz[i][j - 1] == ' '){
                        return -1;
                }

            }
        }
    }
    return 0;
}
int VerificarEspacoSimboloX(int plus_line, int plus_column, char matriz[LINE][COLUMN]) {
    if (matriz[plus_line][plus_column] == ' ' &&
        matriz[plus_line - 1][plus_column - 1] == ' ' &&
        matriz[plus_line - 1][plus_column + 1] == ' ' &&
        matriz[plus_line + 1][plus_column - 1] == ' ' &&
        matriz[plus_line + 1][plus_column + 1] == ' ') {
        return 1;
    }else{
        for(int i = 1;i<LINE-1;i++){
            for(int j = 1;j<COLUMN-1;j++){
                if(matriz[i][j] == ' ' &&
                   matriz[i - 1][j - 1] == ' ' &&
                   matriz[i - 1][j + 1] == ' ' &&
                   matriz[i + 1][j - 1] == ' ' &&
                   matriz[i + 1][j + 1] == ' '){
                    return -1;
                }
            }
        }

    }
    return 0;
}
int VerificarEspacoEstrela(int plus_line,int plus_column,char matriz[LINE][COLUMN]){
    if (matriz[plus_line][plus_column] == ' ' &&
        matriz[plus_line][plus_column - 1] == ' ' &&
        matriz[plus_line][plus_column + 1] == ' ' &&
        matriz[plus_line][plus_column - 2] == ' ' &&
        matriz[plus_line][plus_column + 2] == ' '&&
        matriz[plus_line+1][plus_column - 1] == ' ' &&
        matriz[plus_line+1][plus_column + 1] == ' ' &&
        matriz[plus_line+1][plus_column] == ' ' &&
        matriz[plus_line-1][plus_column] == ' '&&
        matriz[plus_line-1][plus_column+1] == ' ' &&
        matriz[plus_line-1][plus_column-1]==' '&&
        matriz[plus_line-2][plus_column]==' ' &&
        matriz[plus_line+2][plus_column]== ' ') {
        return 1;
    }else{
        for(int i = 2;i<LINE-1;i++){
            for(int j = 2;j<COLUMN-1;j++){
                if(matriz[i][j] == ' ' &&
                   matriz[i][j-1] == ' ' &&
                   matriz[i][j+1] == ' ' &&
                   matriz[i][j-2] == ' ' &&
                   matriz[i][j+2] == ' '&&
                   matriz[i+1][j-1] == ' ' &&
                   matriz[i+1][j+1] == ' ' &&
                   matriz[i+1][j] == ' ' &&
                   matriz[i-1][j] == ' '&&
                   matriz[i-1][j+1] == ' ' &&
                   matriz[i-1][j-1]==' '&&
                   matriz[i-2][j]==' ' &&
                   matriz[i+2][j]== ' '){
                    return -1;
                }
            }
        }

    }
    return 0;

}
void DesenharPonto(int EntradaUsuario, char matriz[LINE][COLUMN]) {
    while (EntradaUsuario > 0) {
        int point_line, point_column;
        do {
            point_line = 1 + rand() % (LINE - 2);
            point_column = 1 + rand() % (COLUMN - 2);
        } while (VerificarEspacoPonto(point_line, point_column, matriz)==-1);

        if (VerificarEspacoPonto(point_line, point_column, matriz)==1) {
            matriz[point_line][point_column] = '*';
            EntradaUsuario-=1;
        } else if(VerificarEspacoPonto(point_line,point_column,matriz)==0){
            printf("\nNao foi possivel desenhar mais simbolos.\n");
            return;
        }
    }
}

void DesenharSimboloMais(int EntradaUsuario, char matriz[LINE][COLUMN]) {
    int point_column, point_line;
    while(EntradaUsuario>0){
        do{
            point_line = 1 + rand() % (LINE-2);
            point_column = 1 + rand() % (COLUMN-2);
        }while(VerificarEspacoSimboloMais(point_line,point_column,matriz)==-1);
        if(VerificarEspacoSimboloMais(point_line,point_column,matriz)==1){
            matriz[point_line][point_column] = '*';
            matriz[point_line + 1][point_column] = '*';
            matriz[point_line - 1][point_column] = '*';
            matriz[point_line][point_column + 1] = '*';
            matriz[point_line][point_column - 1] = '*';
            EntradaUsuario-=1;
        }else if(VerificarEspacoSimboloMais(point_line,point_column,matriz)==0){
            printf("\nNao foi possivel desenhar mais simbolos.\n");
            return;
        }
    }
}
void DesenharX(int EntradaUsuario,char matriz[LINE][COLUMN]){
    int point_column, point_line;
    while(EntradaUsuario>0) {
        do{
            point_line = 1 + rand() % (LINE-2);
            point_column = 1 + rand() % (COLUMN-2);
        } while (VerificarEspacoSimboloX(point_line,point_column,matriz)==-1);
        if(VerificarEspacoSimboloX(point_line,point_column,matriz)==1){
            matriz[point_line][point_column] = '*';
            matriz[point_line-1][point_column+1] = '*';
            matriz[point_line+1][point_column+1] = '*';
            matriz[point_line-1][point_column-1] = '*';
            matriz[point_line+1][point_column-1] = '*';
            EntradaUsuario-=1;
        }else if(VerificarEspacoSimboloX(point_line,point_column,matriz)==0){
            printf("\nNao foi possivel desenhar mais simbolos.\n");
            return;
        }
    }
}
void DesenharRandomicamente(int NumeroPontos,int NumeroSomas,int NumeroX,char matriz[LINE][COLUMN]){
    DesenharPonto(NumeroPontos,matriz);
    DesenharSimboloMais(NumeroSomas,matriz);
    DesenharX(NumeroX,matriz);
}

void DesenharEstrela(int EntradaUsuario,char matriz[LINE][COLUMN]){
    int point_column, point_line;
    while(EntradaUsuario>0){
        do{
            point_line = 1 + rand() % (LINE-2);
            point_column = 1 + rand() % (COLUMN-2);
        }while((VerificarEspacoEstrela(point_line,point_column,matriz))==-1);
        if(VerificarEspacoEstrela(point_line,point_column,matriz)==1){
            matriz[point_line][point_column] = '*';
            matriz[point_line][point_column - 1] = '*';
            matriz[point_line][point_column+ 1] = '*';
            matriz[point_line][point_column - 2] = '*';
            matriz[point_line][point_column + 2] = '*';
            matriz[point_line+1][point_column - 1] = '*';
            matriz[point_line+1][point_column + 1] = '*';
            matriz[point_line+1][point_column] = '*';
            matriz[point_line-1][point_column] = '*';
            matriz[point_line-1][point_column+1] = '*';
            matriz[point_line-1][point_column-1]='*';
            matriz[point_line-2][point_column]='*' ;
            matriz[point_line+2][point_column]= '*';
            EntradaUsuario-=1;
        }else if(VerificarEspacoEstrela(point_line,point_column,matriz)==0){
            printf("\nNao foi possivel desenhar mais simbolos.\n");
            return;
        }
    }
}
void Print_Matriz(char matriz[LINE][COLUMN]){
    for(int i = 0;i<LINE;i++){
        for(int j = 0;j<COLUMN;j++){
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }
}
