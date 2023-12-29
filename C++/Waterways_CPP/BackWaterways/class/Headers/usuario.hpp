#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Usuario {
private:
    string nome_usuario;
    string email_usuario;
    string senha_usuario;
    int id_usuario;
    int idade_usuario;
    double peso_usuario;
    bool usuario_saude;

public:
    Usuario(string var_nome, string var_email, string var_senha, int var_id, int var_idade, double var_peso, bool estado);

    void set_nome_usuario(string var);
    void set_email_usuario(string var);
    void set_senha_usuario(string var);
    void set_id_usuario(int var);
    void set_idade_usuario(int var);
    void set_peso_usuario(double var);
    void set_usuario_saude(bool var);

    string get_nome_usuario() const;
    string get_email_usuario() const;
    string get_senha_usuario() const;
    int get_id_usuario() const;
    int get_idade_usuario() const;
    double get_peso_usuario() const;
    bool get_usuario_saude() const;
};

#endif
