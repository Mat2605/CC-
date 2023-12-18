#include <iostream>
#include <limits>
using namespace std;

int main() {
    auto inf = std::numeric_limits<float>::infinity();
    cout << (-0.0 == 0.0) << "\n"; // true, 0 == 0
    cout << ((5.0f / inf) == ((-5.0f / inf))) << "\n"; // true, 0 == 0
    cout << ((10e40f) == (10e40f + 9999999.0f)) << "\n"; // true, inf == inf
    cout << ((10e40) == (10e40f + 9999999.0f)) << "\n"; //false  
    cout << -inf * -inf << "\n";
    return 0;
}
