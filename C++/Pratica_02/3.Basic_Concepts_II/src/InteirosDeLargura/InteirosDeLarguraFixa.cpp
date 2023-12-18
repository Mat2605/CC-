#include <iostream>
using namespace std;
int main(){
    //int8_t / uint8_t

    uint8_t a = '2'; // é interpretado como char
    int8_t b = '9'; // é interpretado como char
    cout << a << "\n";
    cout << b << "\n";

    //int16_t / uint16_t
    int16_t c = 15;
    uint16_t d = 16;
    cout << c << "\n";
    cout << d << "\n";

    //int32_t / uint32_t
    int32_t e = 33;
    uint32_t f = 23;
    cout << e << "\n";
    cout << f << "\n";

    //int64_t / uint64_t
    //2^63 − 1 = 9,223,372,036,854,775,807 para int64_t
    int64_t g = 90000000;
    uint64_t h = 54;
    cout << g << "\n";
    cout << h << "\n";

    return 0;
}