#include <iostream>

struct PersonaEstructura{
    std::string nombre;
    int edad;
    float estatura;
};

class PersonaClase{
    std::string nombre;
    int edad;
    float estatura;
};

class PersonaClasePublica{
    public:
        std::string nombre;
        int edad;
        float estatura;
    private:
        std::string apellido;
};

void hola(PersonaClasePublica persona){
    std::cout << "Hola! Soy " << persona.nombre << "tengo " << persona.edad << "y mido " << persona.estatura << std::endl;
}

int main(){
    PersonaEstructura p1;
    PersonaClase p2;
    p1.nombre = "Juan";
    p1.edad = 20;
    p1.estatura = 1.70;
    //estas lineas generan error porque los atributos de la clase son privados por privado
    p2.nombre = "Pedro";
    p2.edad = 30;
    p2.estatura = 1.80;
    //Vamos a hacer que funcione con la clase PersonaClasePublica
    PersonaClasePublica p3;
    p3.nombre = "Pedro";
    p3.edad = 30;
    p3.estatura = 1.80;
    hola(p3);
    p3.apellido = "Perez";
    //El Apellido nos da error porque es privado
    return (0);
}