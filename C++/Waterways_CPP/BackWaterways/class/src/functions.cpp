#include "../Headers/functions.hpp"

void ConjuntoUsuarios::set_quantidade_copos(double var){
    this->quantidade_copos = var;
}
void ConjuntoUsuarios::set_totalLitros(double var){
    this->totalLitros = var;
}

double ConjuntoUsuarios::get_quantidade_copos(){
    return quantidade_copos;
}
        
double ConjuntoUsuarios::get_totalLitros(){
    return totalLitros;
}

void ConjuntoUsuarios::set_coposMAX(double var){
    this->coposMAX = var;
}

void ConjuntoUsuarios::set_coposMIN(double var){
    this->coposMIN = var;

}

double ConjuntoUsuarios::get_coposMAX(){
    return this->coposMAX;
}

double ConjuntoUsuarios::get_coposMIN(){
    return this->coposMIN;
}

ConjuntoUsuarios::ConjuntoUsuarios(string var_nome, string var_email, string var_senha, int var_id, int var_idade, double var_peso, bool estado) : obj(var_nome, var_email, var_senha, var_id, var_idade, var_peso, estado) {
    set_quantidade_copos(0.0);
    set_totalLitros(0.0);
    set_coposMAX(0.0);
    set_coposMIN(0.0);
}

AdiministraUsuario::AdiministraUsuario(string var_nome, string var_email, string var_senha, int var_id, int var_idade, double var_peso, bool estado) {
    ConjuntoUsuarios NovoUsuario(var_nome, var_email, var_senha, var_id, var_idade, var_peso, estado);
    Lista.push_back(NovoUsuario);
}

double AdiministraUsuario::calcularporpeso(int index){
    return Lista[index].obj.get_peso_usuario() * 35; //retorna em ml
}

double AdiministraUsuario::calcularporidade(int index){
    return 0.0;
}
