#include "INodo.h"
#include <iostream>
#include <string>
using namespace std;

class Arco {
  public:
    NodoGrafo* origen;
    NodoGrafo* destino;
    int peso;
    
    Arco(NodoGrafo* pOrigen, NodoGrafo* pDestino, int pPeso){
      origen = pOrigen;
      destino = pDestino;
      peso = pPeso;
    }
};
