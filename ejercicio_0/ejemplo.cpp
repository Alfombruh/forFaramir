#include <iostream>

//Aqui definimos una estructura que se va a llamar Persona
//"Persona" es un tipo de dato, como un int, float, char, etc...
//Asi que si queremos declarar una variable de tipo Persona lo haremos como con un int, float, char, etc...
struct Persona{
    std::string nombre;
    int edad;
    float estatura;
};

//Como dato curioso, al ser Persona un tipo de dato, podrias hacer una estructura que user Persona como dato
struct ListaPersonas{
    Persona personas[10];
    int cantidadPersonas;
};
//Aunque esta estructura no la usamos

void variablesCrearPersona(std::string nombre, int edad, float estatura){
    std::string nombrePersona = nombre;
    int edadPersona = edad;
    float estaturaPersona = estatura;
    std::cout << nombrePersona << "mide " << estaturaPersona << "y tiene " << edad << "años" << std::endl;

};

void estructuraCrearPersona(std::string nombre, int edad, float estatura){
    Persona persona; //Aqui estamos creando la estructura de persona, despues tendremos que rellenar sus datos
    persona.nombre = nombre;
    persona.edad = edad;
    persona.estatura = estatura;
    std::cout << persona.nombre << "mide " << persona.estatura << "y tiene " << persona.edad << "años" << std::endl;
};

int main(){
    //vamos a llamar a una funcion que hace una logica con variables
    variablesCrearPersona("Juan", 20, 1.70);
    //vamos a llamar a otra funcion que hace la misma logica con una estructura
    estructuraCrearPersona("Pedro", 25, 1.80);
    return (0);
}