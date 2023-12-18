#include <iostream>
#include <limits>

int main() {
    
    std::cout << "Máximo valor para int8_t: " << static_cast<int>(std::numeric_limits<int8_t>::max()) << std::endl;
    std::cout << "Mínimo valor para int8_t: " << static_cast<int>(std::numeric_limits<int8_t>::min()) << std::endl;

    std::cout << "Máximo valor para uint8_t: " << static_cast<unsigned>(std::numeric_limits<uint8_t>::max()) << std::endl;
    std::cout << "Mínimo valor para uint8_t: " << static_cast<unsigned>(std::numeric_limits<uint8_t>::min()) << std::endl;

    std::cout << "Máximo valor para int16_t: " << std::numeric_limits<int16_t>::max() << std::endl;
    std::cout << "Mínimo valor para int16_t: " << std::numeric_limits<int16_t>::min() << std::endl;

    std::cout << "Máximo valor para uint16_t: " << std::numeric_limits<uint16_t>::max() << std::endl;
    std::cout << "Mínimo valor para uint16_t: " << std::numeric_limits<uint16_t>::min() << std::endl;

    std::cout << "Máximo valor para int32_t: " << std::numeric_limits<int32_t>::max() << std::endl;
    std::cout << "Mínimo valor para int32_t: " << std::numeric_limits<int32_t>::min() << std::endl;

    std::cout << "Máximo valor para uint32_t: " << std::numeric_limits<uint32_t>::max() << std::endl;
    std::cout << "Mínimo valor para uint32_t: " << std::numeric_limits<uint32_t>::min() << std::endl;

    std::cout << "Máximo valor para int64_t: " << std::numeric_limits<int64_t>::max() << std::endl;
    std::cout << "Mínimo valor para int64_t: " << std::numeric_limits<int64_t>::min() << std::endl;

    std::cout << "Máximo valor para uint64_t: " << std::numeric_limits<uint64_t>::max() << std::endl;
    std::cout << "Mínimo valor para uint64_t: " << std::numeric_limits<uint64_t>::min() << std::endl;

    std::cout << "Máximo valor para int: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Mínimo valor para int: " << std::numeric_limits<int>::min() << std::endl;

    std::cout << "Máximo valor para unsigned int: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Mínimo valor para unsigned int: " << std::numeric_limits<unsigned int>::min() << std::endl;

    std::cout << "Máximo valor para short: " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "Mínimo valor para short: " << std::numeric_limits<short>::min() << std::endl;

    std::cout << "Máximo valor para unsigned short: " << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "Mínimo valor para unsigned short: " << std::numeric_limits<unsigned short>::min() << std::endl;

    std::cout << "Máximo valor para long: " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "Mínimo valor para long: " << std::numeric_limits<long>::min() << std::endl;

    std::cout << "Máximo valor para unsigned long: " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "Mínimo valor para unsigned long: " << std::numeric_limits<unsigned long>::min() << std::endl;

    std::cout << "Máximo valor para long long: " << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "Mínimo valor para long long: " << std::numeric_limits<long long>::min() << std::endl;

    std::cout << "Máximo valor para unsigned long long: " << std::numeric_limits<unsigned long long>::max() << std::endl;
    std::cout << "Mínimo valor para unsigned long long: " << std::numeric_limits<unsigned long long>::min() << std::endl;

    std::cout << "Máximo valor para float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Mínimo valor para float: " << std::numeric_limits<float>::min() << std::endl;

    std::cout << "Máximo valor para double: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Mínimo valor para double: " << std::numeric_limits<double>::min() << std::endl;

    std::cout << "Máximo valor para long double: " << std::numeric_limits<long double>::max() << std::endl;
    std::cout << "Mínimo valor para long double: " << std::numeric_limits<long double>::min() << std::endl;

    return 0;
}

