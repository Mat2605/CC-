#include <iostream>
#include <typeinfo>
#include <type_traits>

using namespace std;

template <typename T>
void printTypeInfo(const T& value) {
    cout << "Type: " << typeid(T).name() << endl;
    cout << "Is Integer: " << boolalpha << is_integral<T>::value << endl;
    cout << "Is Floating Point: " << boolalpha << is_floating_point<T>::value << endl;
    cout << "Is Class: " << boolalpha << is_class<T>::value << endl;
    cout << "Is Pointer: " << boolalpha << is_pointer<T>::value << endl;
    cout << "Is Array: " << boolalpha << is_array<T>::value << endl;
    cout << "Is Same as int: " << boolalpha << is_same<T, int>::value << endl;
    cout << "--------------------------" << endl;
}

int main() {
    int integerValue = 42;
    float floatValue = 3.14;
    string stringValue = "Hello, World!";
    char charArray[] = {'a', 'b', 'c'};

    printTypeInfo(integerValue);
    printTypeInfo(floatValue);
    printTypeInfo(stringValue);
    printTypeInfo(charArray);

    return 0;
}
