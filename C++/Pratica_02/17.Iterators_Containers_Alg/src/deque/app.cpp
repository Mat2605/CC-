#include <deque>
#include <iostream>

using namespace std;

int main() {
    // Criando deques de inteiros e strings
    deque<int> queue1 {2, 3, 2};
    deque<string> queue2 = {"abc", "efg"};
    deque<int> queue3(2); // [0, 0]
    deque<int> queue4{2}; // [2]
    deque<int> queue5(2, -1); // [-1, -1]

    // Preenchendo queue5 com o valor 3
    fill(queue5.begin(), queue5.end(), 3); // Igual a {3, 3}

    // Adicionando um elemento no início da deque
    queue1.push_front(5); // [5, 2, 3, 2]

    // Acessando o primeiro elemento da deque
    int firstElement = queue1[0]; // Retorna 5

    // Exibindo os elementos da deque usando range-based for loop
    cout << "Elements of queue1: ";
    for (const auto& it : queue1) {
        cout << it << ", ";
    }
    cout << endl;

    // Tamanho da deque
    cout << "queue1 size: " << queue1.size() << endl;

    // Verificando se a deque está vazia
    cout << "Is queue1 empty: " << (queue1.empty() ? "true" : "false") << endl;

    return 0;
}
