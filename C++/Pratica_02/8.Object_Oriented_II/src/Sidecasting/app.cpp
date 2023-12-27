#include <iostream>

class ClasseA {
public:
    virtual void mensagem() {
        std::cout << "Mensagem da ClasseA\n";
    }
};

class ClasseB : public ClasseA {
public:
    void outraMensagem() {
        std::cout << "Mensagem da ClasseB\n";
    }
};

int main() {
    ClasseB classeBObj;
    ClasseA* classeAPtr = dynamic_cast<ClasseA*>(&classeBObj);  // Sidecasting (Cross-cast)

    if (classeAPtr != nullptr) {
        classeAPtr->mensagem();
    } else {
        std::cout << "A conversão falhou.\n";
    }

    return 0;
}
