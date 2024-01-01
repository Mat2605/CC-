// util.cpp
#include <iostream>
#include "util.hpp"

int globalVar = 42;  // Definição da variável global

void printGlobalVar() {
    std::cout << "Global variable: " << globalVar << std::endl;
}
