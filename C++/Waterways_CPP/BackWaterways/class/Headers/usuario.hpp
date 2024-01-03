#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std;

class Usuario {
private:
    //Campos a serem preenchidos pelo usuário.
    string nome_usuario;
    string email_usuario;
    string senha_usuario;
    int id_usuario;
    int idade_usuario;
    double peso_usuario; //em KG
    double copostotais;
    double litrostotais;
    bool usuario_saude;

public:
    Usuario(string var_nome, string var_email, string var_senha, int var_id, int var_idade, double var_peso, bool estado);

    inline void set_nome_usuario(string var);
    inline void set_email_usuario(string var);
    inline void set_senha_usuario(string var);
    inline void set_id_usuario(int var);
    inline void set_idade_usuario(int var);
    inline void set_peso_usuario(double var);
    inline void set_copos_totais(double var);
    inline void set_litros_totais(double var);
    inline void set_usuario_saude(bool var);

    inline string get_nome_usuario() const;
    inline string get_email_usuario() const;
    inline string get_senha_usuario() const;
    inline int get_id_usuario() const;
    inline int get_idade_usuario() const;
    inline double get_peso_usuario() const;
    inline double get_copos_totais() const;
    inline double get_litros_totais() const;
    inline bool get_usuario_saude() const;
};

#endif
