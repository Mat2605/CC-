#include "../Headers/CalcularLitros.hpp"

inline double calcularporpeso(Usuario obj){
    return 35 * obj.get_peso_usuario();
}
inline double calcularporidade(Usuario obj){
    if(obj.get_idade_usuario() <= 17){

        return 40 * obj.get_peso_usuario();
    }else if(obj.get_idade_usuario() >= 18 && obj.get_idade_usuario() <=55){
        
        return 35 * obj.get_peso_usuario();
    }else if(obj.get_idade_usuario() > 55 && obj.get_idade_usuario() <=65){
        return 30 * obj.get_peso_usuario();

    }else if(obj.get_idade_usuario()>66){
        return 25 * obj.get_peso_usuario();

    }
}

inline double C_calcularporpeso(Usuario obj){
    return calcularporpeso(obj)/UnidadeCopo;
}

inline double C_calcularporidade(Usuario obj){
    return calcularporidade(obj)/UnidadeCopo;
}
