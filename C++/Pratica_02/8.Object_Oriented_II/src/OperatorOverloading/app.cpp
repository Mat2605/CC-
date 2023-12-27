#include <iostream>
//sobrecarga de operadores
struct Point {
    int x, y;

    // Sobrecarga do operador de adição
    Point operator+(const Point& p) const {
        return {x + p.x, y + p.y};
    }

    // Sobrecarga do operador de subtração
    Point operator-(const Point& p) const {
        return {x - p.x, y - p.y};
    }

    // Sobrecarga do operador de multiplicação por escalar
    Point operator*(int scalar) const {
        return {x * scalar, y * scalar};
    }

    // Sobrecarga do operador de igualdade
    bool operator==(const Point& p) const {
        return (x == p.x) && (y == p.y);
    }

    // Sobrecarga do operador de saída para facilitar a impressão
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    using namespace std;

    Point p1 = {2, 3};
    Point p2 = {1, 4};

    // Exemplo de adição
    Point resultadoSoma = p1 + p2;
    cout << "Soma: " << resultadoSoma << endl;

    // Exemplo de subtração
    Point resultadoSubtracao = p1 - p2;
    cout << "Subtração: " << resultadoSubtracao << endl;

    // Exemplo de multiplicação por escalar
    Point resultadoMultiplicacao = p1 * 2;
    cout << "Multiplicação por escalar: " << resultadoMultiplicacao << endl;

    // Exemplo de igualdade
    if (p1 == p2) {
        cout << "Os pontos são iguais." << endl;
    } else {
        cout << "Os pontos são diferentes." << endl;
    }

    return 0;
}
