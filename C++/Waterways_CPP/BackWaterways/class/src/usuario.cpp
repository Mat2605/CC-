#include "../Headers/usuario.hpp"
#include <iostream>  

Usuario::Usuario(string var_nome, string var_email, string var_senha, int var_id, int var_idade, double var_peso, bool estado) {
    set_nome_usuario(var_nome);
    set_email_usuario(var_email);
    set_senha_usuario(var_senha);
    set_id_usuario(var_id);
    set_idade_usuario(var_idade);
    set_peso_usuario(var_peso);
    set_usuario_saude(estado);
}

void Usuario::set_nome_usuario(string var) {
    this->nome_usuario = var;
}

void Usuario::set_email_usuario(string var) {
    this->email_usuario = var;
}

void Usuario::set_senha_usuario(string var) {
    this->senha_usuario = var;
}

void Usuario::set_id_usuario(int var) {
    this->id_usuario = var;
}

void Usuario::set_idade_usuario(int var) {
    this->idade_usuario = var;
}

void Usuario::set_peso_usuario(double var) {
    this->peso_usuario = round(var * 100.0) / 100.0;
}

void Usuario::set_usuario_saude(bool var) {
    this->usuario_saude = var;
}

string Usuario::get_nome_usuario() const {
    return nome_usuario;
}

string Usuario::get_email_usuario() const {
    return email_usuario;
}

string Usuario::get_senha_usuario() const {
    return senha_usuario;
}

int Usuario::get_id_usuario() const {
    return id_usuario;
}

int Usuario::get_idade_usuario() const {
    return idade_usuario;
}

double Usuario::get_peso_usuario() const {
    return peso_usuario;
}

bool Usuario::get_usuario_saude() const {
    return usuario_saude;
}
