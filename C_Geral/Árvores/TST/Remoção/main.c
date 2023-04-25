#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    unsigned FimString : 1;
    char caractere;
    struct Node *esq,*dir,*eq;
}Node;
struct Node* novo_Node(char c){
    struct Node* var = (struct Node*)malloc(sizeof(Node));
    var->caractere = c;
    var->FimString = 0;
    var->dir = NULL;
    var->eq = NULL;
    var->esq = NULL;
    return var;
}
void insere(struct Node **var,char *c){
    //cria o nó caso não exista
    if(!(*var)){
        *var = novo_Node(*c);
    }
    //caso o caractere seja menor que o nó,aloca um valor na esquerda
    if((*var)->caractere>(*c)){
        insere(&((*var)->esq),c);
    //caso o caractere seja maior que o nó,aloca um valor direita
    }else if((*var)->caractere<*c){
        insere(&((*var)->dir),c);
    }else{
        //verifica se o ponteiro c aponta para o último caractere da palavra,caso não for,continua percorrendo a árvore
        if(*(c+1)){
            insere(&((*var)->eq),c+1);
        }else{
            //encerra a inserção da palavra
            (*var)->FimString = 1;
        }
    }
}
void leitura(struct Node* var,int nivel,char *conteudo){
    if(var){
        // A função começa percorrendo para a esquerda, em seguida, 
        //atualiza o conteudo com o caractere do nó atual e verifica se o nó é o fim de uma palavra.
        leitura(var->esq,nivel,conteudo);
        conteudo[nivel] = var->caractere;
        if(var->FimString){
            //se já for o fim string ,a palavra é impressa
            conteudo[nivel+1] = '\0';
            printf("%s\n", conteudo);
        }
        //repete o processo para os filhos no centro e à direita
        leitura(var->eq,nivel+1,conteudo);
        leitura(var->dir,nivel,conteudo);

    }
}
//chama a função leitura
void leituraTst(struct Node* var){
    char conteudo[30];
    leitura(var,0,conteudo);
}
int busca(struct Node* var,char *palavra){
    //Para árvore vazia
    if(!var){
        return 0;
    }
    //comparando o primeiro caractere da palavra com o caractere do nó atual
    //a função é chamada recursivamente para direita ou esquerda
    if(*palavra<(var)->caractere){
        return busca(var->esq,palavra);
    }else if(*palavra>(var)->caractere){
        return busca(var->dir,palavra);
    }else{
        //se chegou no fim da palavra retorna o var->FimString
        if(*(palavra+1)=='\0'){
            return var->FimString;
        }
        //procura na linha central da árvore
        return busca(var->eq,palavra+1);
    }
}
void remove_palavra(Node **var, char *palavra) {
    //Quando a palavra é encontrada, é definido o bit FimString 
    //do último nó da palavra como 0 indicando que aquela 
    //palavra não existe mais na árvore.
    if (*var == NULL) {
        return;
    }
    //Procura a palavra pela árvore
    if (*palavra < (*var)->caractere) {
        remove_palavra(&(*var)->esq, palavra);
    } else if (*palavra > (*var)->caractere) {
        remove_palavra(&(*var)->dir, palavra);
    } else {
        if (*(palavra+1)) {
            remove_palavra(&(*var)->eq, palavra+1);
        } else {
            //se encontra o fim da palavra,para a recursão
            (*var)->FimString = 0;
        }
    }
    //caractere sozinho,sinalizando o final da palavra,retira a palavra
    if ((*var)->FimString == 0 && (*var)->esq == NULL && (*var)->eq == NULL && (*var)->dir == NULL) {
        free(*var);
        *var = NULL;
    }
}

int main(void){
    struct Node* raiz = NULL;
	char palavra1[] = "Casa";
    char palavra2[] = "Capela";
    char palavra3[] = "Jogos";
    char palavra4[] = "Joao";

    insere(&raiz, palavra1);    
    insere(&raiz, palavra2);
    insere(&raiz, palavra3);
    insere(&raiz, palavra4);
    if(busca(raiz,"Casa")){
        printf("\tEncontrado!\n");
    }else{
        printf("\tNão Encontrado!\n");
    }
    remove_palavra(&raiz,"Jogos");
    printf("\tOrdem Transversal: \n");
    leituraTst(raiz);
    return 0;
}