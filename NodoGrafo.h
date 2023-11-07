#ifndef _NODOGRAFO_
#define _NODOGRAFO_ 1
#include "Arco.h"
#include <vector>

using namespace std;

class NodoGrafo {
private:
    int id;
    vector<Arco *> listaArcos;
    bool visitado;
    bool procesado;

public:
    NodoGrafo(int id) {
        this->id = id;
        this->visitado = false; // Inicializar visitado en falso
        this->procesado = false; // Inicializar procesado en falso
    }

    int getId() {
        return id;
    }

    void setId(int pId) {
        this->id = pId;
    }

    void setVisitado(bool valor) {
        this->visitado = valor;
    }

    bool getVisitado() const {
        return visitado;
    }

    void setProcesado(bool valor) {
        this->procesado = valor;
    }

    bool getProcesado() const {
        return procesado;
    }

    void addArc(Arco *pArco) {
        this->listaArcos.push_back(pArco);
    }

    vector<Arco *> getArcs() {
        return this->listaArcos;
    }
    
};

#endif