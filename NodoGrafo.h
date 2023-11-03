#include <iostream>
#include <string>
#include "Arco.h"
#include <vector>
#include "INodo.h"

using namespace std;

class NodoGrafo : public INodo {

  public:
    int id;
    bool procesado;
    bool visitado;
    vector<Arco*> arcos;

    NodoGrafo(int pId) : id(pId), procesado(false), visitado(false) {}
    
    int getId() override {
      return id; 
    }

    void addArco(Arco* arco) {
      arcos.push_back(arco);
    }

};
