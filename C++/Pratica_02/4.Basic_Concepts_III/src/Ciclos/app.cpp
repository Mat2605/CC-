#include <iostream>
using namespace std;

struct A {
    int x;
    int y;
};

int main() {
    for (int i = 1, k = 20; k > 0; i++, k--) {
        cout << "[" << i * k << "]\n";
    }

    int vector[5] = {1, 2, 3, 4, 5};
    for (auto v : vector) {
        cout << (v * 2) << "\n";
    }

    A array[] = {{1, 2}, {5, 6}, {7, 1}};
    int x1, y1;
    for (const auto &elem : array) {
        cout << x1 << "," << y1 << " "; // print: 1,2 5,6 7,1
    }

    return 0;
}

