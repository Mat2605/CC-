#include <iostream>
#include <string>
using namespace std;
void texto(string txt="abc");
int main(int argc,char *argv[]){
    //omitir um parâmetro em uma função
    texto("ABC");
    texto();
    return 0;

}
void texto(string txt){
    cout << "Texto: " <<txt << "\n";
}