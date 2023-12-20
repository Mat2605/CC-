#include <iostream>
using namespace std;
union A {
    int x;
    char y;
}; 
int main(){
    A a;
    a.x = 1023;
    a.y = 0; 
    cout << a.x;  //512 + 256 = 768
    return 0;
}