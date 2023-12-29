#include "../Headers/usuario.hpp"
#define UnidadeCopo 240 //cada copo de água
class ConjuntoUsuarios{
    private:
        double quantidade_copos;
        double totalLitros;
        double coposMAX;
        double coposMIN;
    public:
        Usuario obj;
        ConjuntoUsuarios(string var_nome, string var_email, string var_senha, int var_id, int var_idade, double var_peso, bool estado);
        void set_quantidade_copos(double var);
        void set_totalLitros(double var);
        void set_coposMAX(double var);
        void set_coposMIN(double var);
        double get_coposMAX();
        double get_coposMIN();
        double get_quantidade_copos();
        double get_totalLitros();

};
class AdiministraUsuario{
    public:
        AdiministraUsuario(string var_nome, string var_email, string var_senha, int var_id, int var_idade, double var_peso, bool estado);
        vector<ConjuntoUsuarios> Lista;
        double calcularporpeso(int index);
        double calcularporidade(int index);

}; 