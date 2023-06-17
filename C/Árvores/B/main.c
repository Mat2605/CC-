#include <stdio.h>
#include <stdlib.h>
//Link para auxiliar remoção:https://www.programiz.com/dsa/deletion-from-a-b-tree
//ordem 3 
#define MAX 4
//máximo de chaves possíveis
#define MIN 2
//mínimo de chaves possíveis

struct BTreeNode {
  //composto por uma lista e um vetor de números
  int val[MAX + 1], count; //vetor de números
  //count --> total de elemntos na página
  struct BTreeNode *link[MAX + 1];
  //link do nó com filhos,0 sendo o ponteiro mais a esquerda do nó
};

struct BTreeNode *root;
//auxilia na alocação de memória

// Criação de um novo nó,alocação de memória.
struct BTreeNode *createNode(int val, struct BTreeNode *child) {
  struct BTreeNode *newNode;
  newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  newNode->val[1] = val;
  newNode->count = 1;
  //posição do último elemento adicionado
  newNode->link[0] = root;
  newNode->link[1] = child;
  //valores default
  //apontadodr para os filhos e para os elementos da mesma página
  return newNode;
}

// Insere o valor no nó
void insertNode(int val, int pos, struct BTreeNode *node, struct BTreeNode *child) {
  int j = node->count;
  while (j > pos) {
    node->val[j + 1] = node->val[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->val[j + 1] = val;
  node->link[j + 1] = child;
  node->count++;
}

// Função para dividir um nó,reorganizar a árvore para inserir o valor
void splitNode(int val, int *pval, int pos, struct BTreeNode *node,struct BTreeNode *child, struct BTreeNode **newNode) {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;
    
  *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  j = median + 1;
  /*A variável j é inicializada com median + 1,
   pois os elementos e filhos que precisam ser movidos começam a partir dessa posição*/
  while (j <= MAX) {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }

  node->count = median;
  (*newNode)->count = MAX - median;
  if (pos <= MIN) {
    insertNode(val, pos, node, child);
  } else {
    insertNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];

  node->count--;
  //elemento removido
}

// Decide qual função splitNode e insert deve ser usada
int setValue(int val, int *pval, struct BTreeNode *node, struct BTreeNode **child) {
  int pos;
  if (!node) {
    *pval = val;
    *child = NULL;
    return 1; // Arvore vazia,retorna flag 1 para sinalizar a necessidade de criar uma raiz
  }

  // Verifica se o valor é menor,maior ou igual que o primeiro elemento do nó
  if (val < node->val[1]) {
    pos = 0;
  } else {
    // Procura a posição correta para inserção no nó
    for (pos = node->count; (val < node->val[pos] && pos > 1); pos--);
    // Verifica se o valor já está presente no nó
    if (val == node->val[pos]) {
      printf("Valores Duplicados!\n");
      return 0; // Indica que a inserção falhou devido a duplicação de valores
    }
  }
  
  // Decide aqui o que fazer,inserir o valor na página ou dividir o nó
  //setValue retorna 1 caso o nó for vazio,caso o filho for vazio,reorganizar a árvore
  if (setValue(val, pval, node->link[pos], child)) {
    if (node->count < MAX) {
      // Insere o valor no nó atual
      insertNode(*pval, pos, node, *child);
    } else {
      // Caso contrário, o nó precisa ser dividido
      splitNode(*pval, pval, pos, node, *child, child);
      return 1; // Indica que a inserção foi concluída com sucesso após a divisão
    }
  }
  return 0; // Indica que a inserção falhou
}


// Função para inserir um valor na árvore B
void insert(int val) {
  int flag, i;
  struct BTreeNode *child;

  flag = setValue(val, &i, root, &child);
  //i
  if (flag)
  //arvore vazia,erro ao alocar um valor,criar raiz
    root = createNode(i, child);
}

// Função para pesquisar um valor na árvore B
//valor procurado,ponteiro com null,raiz da árvore
void search(int val, int *pos, struct BTreeNode *myNode) {

  //pos auxilia na pesquisa de cada nó
  //atualizado recursivamente para os proximos
  if (!myNode) {
    //árvore vazia
    return;
  }

  if (val < myNode->val[1]) {
    //caso o valor buscado é menor do que a primeira chave,a menor
    *pos = 0;
    //caso for menor,o valor provavelmente para o nó filho,chamada recursiva
  } else {
    //pesquisa nos restantes elementos na página
    for(*pos = myNode->count; (val < myNode->val[*pos] && *pos > 1); (*pos)--);
    if (val == myNode->val[*pos]) {
      printf("%d Encontrado!", val);
      return;
    }
  }
  search(val, pos, myNode->link[*pos]);
  return;
}

//As funções de remoção devem respeitar a norma imposta por Min.
//caso contrário,Nesse caso, emprestamos uma chave do nó irmão vizinho imediato na ordem da esquerda para a direita.
//Em outras palavras,o nó mais a direita do pai assume o seu lugar e o pai assumi o lugar do filho removido
//Olhar em remoção
// Função para percorrer os nós da árvore B,ordem crescente
void traversal(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
    //raiz existe
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i]);
      //mostra todos a esquerda
      printf("%d ", myNode->val[i + 1]);
    }
    //mesmo processo para cada nó,direita
    traversal(myNode->link[i]);
  }
}

int main(void) {
  int val, ch;

  // Inserir valores na árvore B
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  insert(5);
  insert(6);
  insert(7);
  insert(8);
  insert(9);
  insert(10);

  // Percorrer a árvore B e imprimir os valores
  traversal(root);

  printf("\n");

  // Pesquisar um valor na árvore B
  search(1, &ch, root);
  return 0;
}


