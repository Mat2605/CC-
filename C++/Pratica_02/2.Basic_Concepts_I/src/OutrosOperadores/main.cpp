#include <iostream>
#include <utility>

using namespace std;
bool cmp_greater(unsigned int a, signed int b) {
    return a > b;
}

int main() {
    int I = 4, U = 3;
    unsigned int x = 6;
    signed int y = -6;

    cout << (I < U ? -1 : (I == U ? 0 : 1)) << endl;

    bool value = cmp_greater(x, y);
    cout << "\n" << value;

    return 0;
}
