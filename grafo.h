#include <iostream>
#include <string>
#include <vector>
#include "NodoGrafo.h"
#include "INodo.h"
#include <map>
#include <queue>
#include "Arco.h"

using namespace std;

class Grafo {

  private:
    vector<NodoGrafo*> listaNodos;
    bool esDirigido = true;
    map<int, NodoGrafo*> hashNodos; 

    void resetNodos() {
      for(NodoGrafo* nodo : listaNodos){
        nodo->procesado = false;
        nodo->visitado = false;
      }
    }

  public:

    Grafo(bool pDirigido) : esDirigido(pDirigido) {}

    int getSize() {
      return listaNodos.size();
    }

    void addNodo(INodo* pNodo) {
      NodoGrafo* nuevoNodo = new NodoGrafo(pNodo->getId());
      listaNodos.push_back(nuevoNodo);
      hashNodos[pNodo->getId()] = nuevoNodo;
    }

    void addArco(NodoGrafo* pOrigen, NodoGrafo* pDestino, int pPeso){
      Arco* nuevoArco = new Arco(pOrigen, pDestino, pPeso);
      pOrigen->addArco(nuevoArco);

      if(!esDirigido){
        Arco* arcoInverso = new Arco(pDestino, pOrigen, pPeso);
        pDestino->addArco(arcoInverso);
      }
    }

    vector<INodo*> deepPath(INodo* pOrigen){
      vector<INodo*> result;
      resetNodos();

      NodoGrafo* origen = hashNodos[pOrigen->getId()];
      dfs(origen, result);

      return result;
    }

    void dfs(NodoGrafo* actual, vector<INodo*>& result){
      
      if(actual == nullptr) return;

      actual->visitado = true;
      result.push_back(actual);

      for(Arco* arco : actual->arcos){
        NodoGrafo* adyacente = arco->destino;
        if(!adyacente->visitado){
          dfs(adyacente, result); 
        }
      }
    }

    vector<NodoGrafo*> getNodos(){
        return listaNodos;
    }

};