# include <iostream>
namespace ns1 {
    void f() {
        std::cout << "ns1" << std::endl;
    }
} // namespace ns1
namespace ns2 {
    void f() {
        std::cout << "ns2" << std::endl;
    }  
} // namespace ns2
int main () {
    ns1::f(); // print "ns1"
    ns2::f(); // print "ns2"
    // f(); //não é visível fora de ns1 e ns2
}
