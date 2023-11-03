
#include <iostream>
#include <string>
#include "NodoGrafo.h"

using namespace std;

class PuertoMaritimo : public NodoGrafo {

  public:
    string nombre;
    string ciudad;

    PuertoMaritimo(string nombre, string ciudad, int id) : NodoGrafo(id) {
      this->nombre = nombre;
      this->ciudad = ciudad; 
    }

    string getNombre() {
      return nombre;
    }

    string getCiudad() {
      return ciudad;
    }

};



