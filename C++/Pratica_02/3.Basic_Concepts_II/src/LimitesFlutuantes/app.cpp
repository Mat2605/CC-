#include <limits>
#include <iostream>
using namespace std;

int main() {

    float maxValue = std::numeric_limits<float>::max();
    cout << "Maior valor: " << maxValue << "\n";

    float lowestValue = std::numeric_limits<float>::lowest();
    cout << "Lowest Value: " << lowestValue << "\n";

    float minValue = std::numeric_limits<float>::min();
    cout << "Valor mínimo: " << minValue << "\n";

    float denormMinValue = std::numeric_limits<float>::denorm_min();
    cout << "Menor valor denomial: " << denormMinValue << "\n";

    float epsilonValue = std::numeric_limits<float>::epsilon();
    cout << "Valor Epsilon: " << epsilonValue << "\n";

    float infinityValue = std::numeric_limits<float>::infinity();
    cout << "Valor Infinito " << infinityValue << "\n";

    float nanValue = std::numeric_limits<float>::quiet_NaN();
    cout << "Valor NaN: " << nanValue << "\n";
    return 0;
}
