# include <iostream>
void f() { 
    std::cout << "global" << std::endl; 
}

namespace ns1 {
    void f() { std::cout << "ns1::f()" << std::endl; }
    void g() { std::cout << "ns1::g()" << std::endl; }
} // namespace ns1
int main () {
    f(); // ok, print "global"
    using namespace ns1; 
    g(); // ok, print "ns1::g()", only one choice
    // f(); // ambíguo
    ::f(); // ok, print "global"
    ns1::f(); // ok, print "ns1::f()"
}
