#include<stdio.h>
#include<stdlib.h>
 
// Crie uma estrutura, item contendo uma chave e 
//um valor representando os dados a serem inseridos na tabela hash.
struct item 
{
    int key;
    int value;
};
 
/* Crie outra estrutura, hash table_item com dados variáveis ​​(chave e valor) e 
sinalize como uma variável de status que informa sobre o status do índice do array */
struct hashtable_item {
    int flag;
    /*
     * flag = 0 : valor não existe
     * flag = 1 : valor existe
     * flag = 2 : valor existe pelo menos uma vez
    */
    struct item *data;
};
/*Agora crie um array de estrutura (hashtable_item) de algum tamanho (10, neste caso).
 Esta matriz será nossa tabela de hash*/
struct hashtable_item *array;
int size = 0;
//tamanho da tabela
int max = 10;
 
/* inicializar a tabela hash */
void init_array(){
    int i;
    for (i = 0; i < max; i++) {
	array[i].flag = 0;
	array[i].data = NULL;
    }
}
 
/* calcula o hashcode */
int hashcode(int key){
    return (key % max);
}
 
/* Inserir*/
void insert(int key, int value)
{
    int index = hashcode(key);
    int i = index;
 
    /* criar um novo no para inserir na tabela */
    struct item *new_item = (struct item*) malloc(sizeof(struct item));
    new_item->key = key;
    new_item->value = value;
 
    /* encontrar um espaço vago no array,quando ocorrer uma colisão o algoritmo procura nas próximas
    posições na tabela,caso chegue a max-1,tenta a partir de 0 e se não encontrar,a tabela está cheia*/
    while (array[i].flag == 1) {
 
	if (array[i].data->key == key) {
 
		/* chave já está inserida */
		printf("\n Key already exists, hence updating its value \n");
		array[i].data->value = value;
		return;
	}
    //avança uma posição
	i = (i + 1) % max;
    //tenta percorrer todas as posições até achar um espaço vazio
	if (i == index) {
		printf("\n Hash table is full, cannot insert any more item \n");
		return;
	}
 
    }
 
    array[i].flag = 1;
    array[i].data = new_item;
    size++;
    printf("\n Key (%d) has been inserted \n", key);
 
} 
 
 
/* remover um elemento */
void remove_element(int key)
{
    int index = hashcode(key);
    int  i = index;
 
    /* flag == 0 o elemento não teria sido inserido */
    while (array[i].flag != 0) 
    {
        //elemento presente na tabela e igual ao valor de busca
	if (array[i].flag == 1  &&  array[i].data->key == key ) 
        {
 
		// caso a chave na posição i é o valor procurado
		array[i].flag =  2;
		array[i].data = NULL;
		size--;
		printf("\n Key (%d) has been removed \n", key);
		return;
 
	}
    //procurar até encotrar,até chegar ao limite.
	i = (i + 1) % max;
	if (i == index)
        {
		break;
	}
 
    }
 
    printf("\n This key does not exist \n");
 
}
 
/* to display all the elements of hash table */
void display()
{
    int i;
    for (i = 0; i < max; i++)
    {
	struct item *current = (struct item*) array[i].data;
 
	if (current == NULL) 
        {
	    printf("\n Array[%d] has no elements \n", i);
	}
	else
        {
	    printf("\n Array[%d] has elements -: \n  %d (key) and %d(value) ", i, current->key, current->value);
	}
    }
 
}
 
int size_of_hashtable()
{
    return size;
}
 
int main(){
	//um problema com esse modo de armazenamento é o agrupamento primário,longas sequencias de posições ocupadas
	//a medida que a tabela cresce o custo computacional cresce
	int choice, key, value, n, c;
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item*));
	init_array();
 
	do {
		printf("Implementation of Hash Table in C with Linear Probing \n\n");
		printf("MENU-: \n1.Inserting item in the Hashtable" 
                              "\n2.Removing item from the Hashtable" 
                              "\n3.Check the size of Hashtable"
                              "\n4.Display Hashtable"
		       "\n\n Please enter your choice-:");
 
		scanf("%d", &choice);
 
		switch(choice) 
                {
 
		case 1:
 
		      printf("Inserting element in Hashtable\n");
		      printf("Enter key and value-:\t");
		      scanf("%d %d", &key, &value);
		      insert(key, value);
 
		      break;
 
		case 2:
 
		      printf("Deleting in Hashtable \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);
 
		      break;
 
		case 3:
 
		      n = size_of_hashtable();
		      printf("Size of Hashtable is-:%d\n", n);
 
		      break;
 
		case 4:
 
		      display();
 
		      break;
 
		default:
 
		       printf("Wrong Input\n");
 
		}
 
		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
 
	}while(c == 1);
    return 0;
 
}