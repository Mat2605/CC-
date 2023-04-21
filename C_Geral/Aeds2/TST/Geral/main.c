#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct No {
	char data;
	unsigned FimString : 1;

	struct No *esq, *eq, *dir;
};

// A utility function to create a new ternary search tree
// No
struct No* newNo(char data)
{
	struct No* temp = (struct No*)malloc(sizeof(struct No));
	temp->data = data;
	temp->FimString = 0;
	temp->esq = temp->eq = temp->dir = NULL;
	return temp;
}

// Insere um elemento na árvore 
void insert(struct No** root, char* word)
{
	// Base Case: Tree is empty
	if (!(*root))
		*root = newNo(*word);

	//caso o valor for menor que o nó principal,cria se um nó a esquerda e o armazena
	if ((*word) < (*root)->data)
		insert(&((*root)->esq), word);
    //caso o valor for menor que o nó principal,cria se um nó a esquerda e o armazena
	else if ((*word) > (*root)->data)
		insert(&((*root)->dir), word);

	// caso o valor já esteja no nó
	else {
		if (*(word + 1))
			insert(&((*root)->eq), word + 1);

		else
            //no momento é o último elemento da árvore
			(*root)->FimString = 1;
	}
}
//Leitura
void traverseTSTUtil(struct No* root, char* buffer,
					int depth)
{
	if (root) {
		// Começa com os elementos a esquerda,depois os iguais e depois os da direita
		traverseTSTUtil(root->esq, buffer, depth);
        //caractere por caractere
		buffer[depth] = root->data;
		if (root->FimString) {
			buffer[depth + 1] = '\0';
			printf("%s\n", buffer);
		}
		traverseTSTUtil(root->eq, buffer, depth + 1);

		traverseTSTUtil(root->dir, buffer, depth);
	}
}

void traverseTST(struct No* root)
{
	char buffer[MAX];
	traverseTSTUtil(root, buffer, 0);
}

// busca
int searchTST(struct No* root, char* word)
{
	if (!root)
		return 0;
        //arvore vazia

	if (*word < (root)->data)
		return searchTST(root->esq, word);

	else if (*word > (root)->data)
		return searchTST(root->dir, word);

	else {
		if (*(word + 1) == '\0')
			return root->FimString;

		return searchTST(root->eq, word + 1);
	}
}

// Driver program to test above functions
int main()
{
	struct No* root = NULL;

	insert(&root, "Casa");
	insert(&root, "Capela");
	insert(&root, "Jogos");
	insert(&root, "Joao");

	printf(	"Ordem Transversal:\n");
	traverseTST(root);
    if(searchTST(root,"Casa")){
        printf("Encontrado!\n");
    }else{
        printf(" Não Encontrado!\n");
    }

	return 0;
}
