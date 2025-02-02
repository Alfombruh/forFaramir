#include <iostream>
#include <cstdlib>

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

class TarjetaCredito
{
private:
    // estas variables son privadas porque no queremos que se puedan modificar desde fuera de la clase
    int numero;
    int cvv;
    Fecha fecha_caducidad;
    int saldo;

public:
    TarjetaCredito()
    {
        numero = rand() % 1000000000;
        cvv = rand() % 1000;
        fecha_caducidad.dia = rand() % 31;
        fecha_caducidad.mes = rand() % 12;
        fecha_caducidad.anio = rand() % 100 + 2020;
    };
    TarjetaCredito()
    {
        std::cout << "Se ha borrado un objeto de la clase TarjetaCredito" << std::endl;
    };

    int getNumero()
    {
        return numero;
    };
    int getCVV()
    {
        return cvv;
    };
    Fecha getFechaCaducidad()
    {
        return fecha_caducidad;
    };
    int getSaldo()
    {
        return saldo;
    };

    void sacarDinero(int cantidad)
    {
        if (cantidad > saldo)
        {
            std::cout << "No tienes suficiente saldo" << std::endl;
            return;
        }
        saldo -= cantidad;
    };

    void ingresarDinero(int cantidad)
    {
        saldo += cantidad;
    };
};

class Persona
{
private:
    std::string seguridad_social;
    std::string DNI;

public:
    // atributos de la clase
    std::string nombre;
    int edad;
    float estatura;
    TarjetaCredito tarjeta;

    // Esto ya sabes lo que es, es el constructor. Cuando declaras un objeto de esta clase se llama a esta funcion/metodo.
    Persona()
    {
        seguridad_social = rand() % 1000000000 + 1000000000;
        DNI = rand() % 1000000000 + 1000000000;
        std::cout << "Se ha creado un objeto de la clase Persona" << std::endl;
    };
    // Igual que la anterior sabes que esto es el destructor. Se llama cuando el objeto se tiene que borrar de memoria.
    ~Persona()
    {
        std::cout << "Se ha borrado un objeto de la clase Persona" << std::endl;
    };
    // como no podemos acceder a los miembros privados de la clase desde fuera de la clase creamos metodos publicos para poder verlos o modificarlos
    void setSeguridadSocial(std::string ss)
    {
        seguridad_social = ss;
    };
    void setDNI(std::string dni)
    {
        DNI = dni;
    };
    std::string getSeguridadSocial()
    {
        return seguridad_social;
    };
    std::string getDNI()
    {
        return DNI;
    };

    // Dejando de lado los getters y setters, podemos crear metodos para que hagan otras cosas, voy a hacer aqui un par de ejemplos.
    void saludar()
    {
        std::cout << "Hola, me llamo " << nombre << " y tengo " << edad << " años" << std::endl;
    };
    Persona tenerHijo()
    {
        Persona hijo;
        hijo.nombre = "Hijo de " + nombre;
        hijo.edad = 0;
        hijo.estatura = 0.5;
        return hijo;
    }

    void decirDatosPersonales()
    {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Seguridad Social: " << seguridad_social << std::endl;
        std::cout << "DNI: " << DNI << std::endl;
    }
    // Aqui declaramos el metodo. Le decimos el tipo de dato que devuelve, el tipo de dato que recibe y el nombre de la funcion.
    void saludarAPersona(Persona p);
};
// Aqui hacemos la logica de la metodo. Cuando declaramos un metodo tenemos que decir a que clase pertenece, por eso ponemos Persona:: delante del nombre del metodo.
// Si no pusiese Persona:: delante del nombre del metodo, el compilador no sabria a que clase pertenece el metodo y se creeria que es una funcionl.
void Persona::saludarAPersona(Persona p)
{
    std::cout << "Hola " << p.nombre << ", soy " << nombre << std::endl;
};

int main()
{
    Persona p1;
    p1.nombre = "Pepe";
    p1.edad = 20;
    p1.estatura = 1.7;
    p1.saludar();
    p1.decirDatosPersonales();
    p1.tarjeta.getCVV();
    p1.tarjeta.getNumero();
    p1.tarjeta.getFechaCaducidad();
    p1.tarjeta.getSaldo();
    p1.tarjeta.ingresarDinero(1000);
    p1.tarjeta.sacarDinero(500);
    p1.tarjeta.getSaldo();
    return (0);
}