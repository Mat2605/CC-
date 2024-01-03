#include "../Headers/usuario.hpp"

Usuario::Usuario(string var_nome, string var_email, string var_senha, int var_id, int var_idade, double var_peso, bool estado) {
    set_nome_usuario(var_nome);
    set_email_usuario(var_email);
    set_senha_usuario(var_senha);
    set_id_usuario(var_id);
    set_idade_usuario(var_idade);
    set_peso_usuario(var_peso);
    set_copos_totais(0.0);
    set_litros_totais(0.0);
    set_usuario_saude(estado);
}

inline void Usuario::set_nome_usuario(string var) {
    this->nome_usuario = var;
}

inline void Usuario::set_email_usuario(string var) {
    this->email_usuario = var;
}

inline void Usuario::set_senha_usuario(string var) {
    this->senha_usuario = var;
}

inline void Usuario::set_id_usuario(int var) {
    this->id_usuario = var;
}

inline void Usuario::set_idade_usuario(int var) {
    this->idade_usuario = var;
}

inline void Usuario::set_peso_usuario(double var) {
    this->peso_usuario = var;
}

inline void Usuario::set_copos_totais(double var){
    this->copostotais += var;
}
inline void Usuario::set_litros_totais(double var){
    this->litrostotais += var;
}


inline void Usuario::set_usuario_saude(bool var) {
    this->usuario_saude = var;
}


inline string Usuario::get_nome_usuario() const {
    return nome_usuario;
}

inline string Usuario::get_email_usuario() const {
    return email_usuario;
}

inline string Usuario::get_senha_usuario() const {
    return senha_usuario;
}

inline int Usuario::get_id_usuario() const {
    return id_usuario;
}

inline int Usuario::get_idade_usuario() const {
    return idade_usuario;
}

inline double Usuario::get_peso_usuario() const {
    return peso_usuario;
}

inline double Usuario::get_copos_totais() const{
    return copostotais;

}
inline double  Usuario::get_litros_totais() const{
    return litrostotais;
}

inline bool Usuario::get_usuario_saude() const {
    return usuario_saude;
}
