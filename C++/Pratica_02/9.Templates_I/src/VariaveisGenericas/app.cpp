#include <iostream>
using namespace std;
template<typename T>
constexpr T pi{ 3.1415926535897932385 };
template<typename T>
T circular_area(T r) {
    return pi<T> * r * r; 
}
int main(){
    cout << circular_area(3.3f) << "\n";
    cout << circular_area(3.3)<< "\n" ;
    return 0;
}