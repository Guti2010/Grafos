#ifndef _PUERTO_
#define _PUERTO_ 1

#include <string>
#include "NodoGrafo.h"

using namespace std;

class PuertoMaritimo : public NodoGrafo {
private:
    string nombre;
    string ciudad;
    int capacidad;

public:
    PuertoMaritimo(string nombre, string ciudad, int capacidad, int id) : NodoGrafo(id) {
        this->nombre = nombre;
        this->ciudad = ciudad;
        this->capacidad= capacidad;
    }

    string getNombre() const {
        return nombre;
    }

    void setNombre(const string& value) {
        nombre = value;
    }

    string getCiudad() const {
        return ciudad;
    }

    void setCiudad(const string& value) {
        ciudad = value;
    }

    int getCapacidad(){
        return capacidad;
    }

    void setCapacidad(int capacidad){
        this->capacidad = capacidad;
    }
};

#endif
