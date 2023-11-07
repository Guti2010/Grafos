#ifndef _GRAFO_
#define _GRAFO_ 1
#include <vector>
#include "NodoGrafo.h"
#include <map>
#include <queue>
#include <stack>
#include "Arco.h"

using namespace std;

class Grafo
{
private:
    vector<NodoGrafo *> listaNodos;
    bool esDirigido = true;
    std::map<int, NodoGrafo *> hashNodos;

    void resetNodes()
    {
        for (NodoGrafo *current : listaNodos)
        {
            current->setProcesado(false);
            current->setVisitado(false);
        }
    }

    NodoGrafo *findNotVisited()
    {
        NodoGrafo *result = nullptr;
        for (NodoGrafo *current : listaNodos)
        {
            if (!current->getVisitado())
            {
                result = current;
                break;
            }
        }
        return result;
    }

public:
    Grafo(bool pDirigido)
    {
        this->esDirigido = pDirigido;
    }

    int getSize()
    {
        return this->listaNodos.size();
    }

    void addNode(NodoGrafo *pNodo)
    {
        this->listaNodos.push_back(pNodo);
        hashNodos.insert(pair<int, NodoGrafo *>(pNodo->getId(), pNodo));
    }

    void addArc(NodoGrafo *pOrigen, NodoGrafo *pDestino, int pPeso)
    {
        Arco* newArc = new Arco(pOrigen, pDestino, pPeso);;

        pOrigen->addArc(newArc);
        if (!this->esDirigido)
        {
            Arco* reverseArc = new Arco(pDestino, pOrigen, pPeso);

            pDestino->addArc(reverseArc);
        }
    }

    NodoGrafo *getNodo(int pId)
    {
        return hashNodos.at(pId);
    }

    // DFS para encontrar un componente conexo
    void DFS(NodoGrafo* start, vector<NodoGrafo*>& component, vector<NodoGrafo*> listaNodos) {

        stack<NodoGrafo*> stack;
        stack.push(start);

        while (!stack.empty()) {

            NodoGrafo* current = stack.top();
            stack.pop();

            if (!current->getVisitado()) {

                component.push_back(current);
                current->setVisitado(true);
                
                vector<Arco*> adyacentes = current->getArcs(); // Todos los arcos

                for (int indiceArcos = 0; indiceArcos < adyacentes.size(); ++indiceArcos)
                {
                    Arco* arco = adyacentes.at(indiceArcos);
                    NodoGrafo *adyacente = (NodoGrafo *)arco->getDestino();
                    if (!adyacente->getProcesado())
                    {
                        stack.push(adyacente);
                        adyacente->setProcesado(true);
                    }
                }
                
            }
        }
    }

    // Encontrar componentes conexos
    vector<vector<NodoGrafo*>> deepPath(NodoGrafo* startNode) {

        vector<vector<NodoGrafo*>> components;

        // DFS para primer componente
        vector<NodoGrafo*> firstComponent;
        DFS(startNode, firstComponent, this->listaNodos);
        components.push_back(firstComponent);

        // DFS para otros componentes
        for (NodoGrafo* nodo : listaNodos) {
            if (!nodo->getVisitado()) {
                vector<NodoGrafo*> component;
                DFS(nodo, component, listaNodos);
                components.push_back(component);
            }
        }

        return components;

    }
    vector<NodoGrafo *> broadPath(NodoGrafo *pOrigen)
    {
        vector<NodoGrafo *> result;
        queue<NodoGrafo *> nodosProcesados;
        int visitados = 0;

        resetNodes();

        NodoGrafo *puntoPartida = this->getNodo(pOrigen->getId());
        nodosProcesados.push(puntoPartida);
        puntoPartida->setProcesado(true);

        do
        {
            while (!nodosProcesados.empty())
            {
                NodoGrafo *actual = nodosProcesados.front();
                nodosProcesados.pop();

                actual->setVisitado(true);
                visitados++;
                result.push_back(actual);

                vector<Arco *> adyacentes = actual->getArcs();

                for (int indiceArcos = 0; indiceArcos < adyacentes.size(); ++indiceArcos)
                {
                    Arco* arco = adyacentes.at(indiceArcos);
                    NodoGrafo *adyacente = (NodoGrafo *)arco->getDestino();
                    if (!adyacente->getProcesado())
                    {
                        nodosProcesados.push(adyacente);
                        adyacente->setProcesado(true);
                    }
                }
            }

            if (visitados < this->getSize())
            {
                puntoPartida = this->findNotVisited();
                nodosProcesados.push(puntoPartida);
                puntoPartida->setProcesado(true);
            }
        } while (visitados < this->getSize());
        

        return result;
    }

    vector<NodoGrafo *> getNodos() {
        return listaNodos;
    }

};

#endif