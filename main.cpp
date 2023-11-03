
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "grafo.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Grafo grafo(true);  // El grafo es dirigido

    // Agregar 20 puertos al grafo
    grafo.addNodo(new PuertoMaritimo("Puerto de Los Angeles", "Los Angeles", 1));
    grafo.addNodo(new PuertoMaritimo("Puerto de Long Beach", "Long Beach", 2));
    grafo.addNodo(new PuertoMaritimo("Puerto de Nueva York", "Nueva York", 3));
    grafo.addNodo(new PuertoMaritimo("Puerto de Miami", "Miami", 4));
    grafo.addNodo(new PuertoMaritimo("Puerto de Rotterdam", "Rotterdam", 5));
    grafo.addNodo(new PuertoMaritimo("Puerto de Singapur", "Singapur", 6));
    grafo.addNodo(new PuertoMaritimo("Puerto de Shanghái", "Shanghái", 7));
    grafo.addNodo(new PuertoMaritimo("Puerto de Busan", "Busan", 8));
    grafo.addNodo(new PuertoMaritimo("Puerto de Hong Kong", "Hong Kong", 9));
    grafo.addNodo(new PuertoMaritimo("Puerto de Los Ángeles", "Los Ángeles", 10));
    grafo.addNodo(new PuertoMaritimo("Puerto de Hamburgo", "Hamburgo", 11));
    grafo.addNodo(new PuertoMaritimo("Puerto de Amberes", "Amberes", 12));
    grafo.addNodo(new PuertoMaritimo("Puerto de Róterdam", "Róterdam", 13));
    grafo.addNodo(new PuertoMaritimo("Puerto de Barcelona", "Barcelona", 14));
    grafo.addNodo(new PuertoMaritimo("Puerto de Valencia", "Valencia", 15));
    grafo.addNodo(new PuertoMaritimo("Puerto de Pusan", "Pusan", 16));
    grafo.addNodo(new PuertoMaritimo("Puerto de Shenzhen", "Shenzhen", 17));
    grafo.addNodo(new PuertoMaritimo("Puerto de Kaohsiung", "Kaohsiung", 18));
    grafo.addNodo(new PuertoMaritimo("Puerto de Hong Kong", "Hong Kong", 19));
    grafo.addNodo(new PuertoMaritimo("Puerto de Ningbo", "Ningbo", 20));

    // Establecer arcos entre los puertos
    grafo.addArco(&puerto1, &puerto2, 10);  // Arco con peso 10
    grafo.addArco(&puerto1, &puerto3, 5);   // Arco con peso 5
    grafo.addArco(&puerto2, &puerto4, 7);   // Arco con peso 7
    grafo.addArco(&puerto3, &puerto5, 12);  // Arco con peso 12
    grafo.addArco(&puerto4, &puerto6, 9);   // Arco con peso 9
    grafo.addArco(&puerto5, &puerto7, 15);  // Arco con peso 15
    grafo.addArco(&puerto6, &puerto8, 11);  // Arco con peso 11
    grafo.addArco(&puerto7, &puerto9, 8);   // Arco con peso 8
    grafo.addArco(&puerto8, &puerto10, 13); // Arco con peso 13
    grafo.addArco(&puerto9, &puerto11, 6);  // Arco con peso 6
    // Continuar estableciendo arcos entre otros puertos aquí

    // Realizar un recorrido en profundidad desde un nodo de inicio (por ejemplo, el Puerto de Los Angeles)
    vector<INodo*> resultado = grafo.deepPath(&puerto1);

    // Imprimir el resultado del recorrido en profundidad
    cout << "Recorrido en Profundidad:" << endl;
    for (INodo* nodo : resultado) {
        cout << "Visitando Nodo ID: " << nodo->getId() << " (Nombre: " << dynamic_cast<PuertoMaritimo*>(nodo)->getNombre() << ")" << endl;
    }

    return 0;
}