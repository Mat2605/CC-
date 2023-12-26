#include <iostream>
using namespace std;
class Privados{
    private: //para declarar membros private
    string nome;
    int id;
    public:
    void setNome(string s){
        this->nome = s;
    }
    void setId(int i){
        this->id = i;
    }
    string getNome(){
        return this->nome;
    }
    int getId(){
        return this->id;
    }
};
int main(){
    Privados obj;
    //obj.id = 1; erro de compilação
    obj.setId(2605);
    obj.setNome("Matheus Nogueira Moreira");
    cout << obj.getNome() << "|" << obj.getId() << "\n";
    return 0;
}