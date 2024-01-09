#include <iostream>
#include <tuple>

using namespace std;

int main() {
    // Criando tuples usando diferentes métodos
    tuple<int, string> tuple1(3, "abc");
    tuple<int, string> tuple2 = make_tuple(4, "zzz");

    // Exibindo os valores do primeiro e segundo elementos da tuple1
    cout << "tuple1.get<0>(): " << get<0>(tuple1) << endl;   // Saída: 3
    cout << "tuple1.get<1>(): " << get<1>(tuple1) << endl;   // Saída: "abc"

    // Trocando os valores de tuple1 e tuple2 usando swap
    swap(tuple1, tuple2);

    // Exibindo os valores do primeiro e segundo elementos da tuple2 após a troca
    cout << "get<0>(tuple2): " << get<0>(tuple2) << endl;   // Saída: 4
    cout << "get<1>(tuple2): " << get<1>(tuple2) << endl;   // Saída: "zzz"

    // Comparando os valores do primeiro elemento de tuple1 e tuple2
    cout << "(get<0>(tuple1) > get<0>(tuple2)): " << (get<0>(tuple1) > get<0>(tuple2)) << endl; // Saída: 1 (true)

    return 0;
}
