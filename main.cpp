#include <iostream>
#include "Grafo.h"
#include "Puerto.h"
#include "NodoGrafo.h"
#include <vector>

using namespace std;

int main() {
    

    Grafo grafo(true); // Crear un grafo dirigido

    // Crear nodos y agregarlos al grafo
    PuertoMaritimo* nodo1 = new PuertoMaritimo("Puerto de Shanghai", "Shanghai, China", 1000, 1);
    PuertoMaritimo* nodo2 = new PuertoMaritimo("Puerto de Singapur", "Singapur", 1500, 2);
    PuertoMaritimo* nodo3 = new PuertoMaritimo("Puerto de Shenzhen", "Shenzhen, China", 2000, 3);
    PuertoMaritimo* nodo4 = new PuertoMaritimo("Puerto de Ningbo-Zhoushan", "Ningbo, China", 1200, 4);
    PuertoMaritimo* nodo5 = new PuertoMaritimo("Puerto de Hong Kong", "Hong Kong", 2500, 5);

    PuertoMaritimo* nodo6 = new PuertoMaritimo("Puerto de Busan", "Busan, Corea del Sur", 3000, 6);
    PuertoMaritimo* nodo7 = new PuertoMaritimo("Puerto de Qingdaor", "Qingdao, China", 1050, 7);
    PuertoMaritimo* nodo8 = new PuertoMaritimo("Puerto de Guangzhou", "Guangzhou, China", 2500, 8);
    PuertoMaritimo* nodo9 = new PuertoMaritimo("Puerto de Jebel Ali", "Dubái, Emiratos Árabes Unidos", 1320, 9);
    PuertoMaritimo* nodo10 = new PuertoMaritimo("Puerto de Port Hedland", "Port Hedland, Australia", 2700, 10);

    PuertoMaritimo* nodo11 = new PuertoMaritimo("Puerto de Dalian", "Dalian, China", 1400, 11);
    PuertoMaritimo* nodo12 = new PuertoMaritimo("Puerto de Tianjin ", "Singapur", 1500, 12);
    PuertoMaritimo* nodo13 = new PuertoMaritimo("Puerto de Rotterdam", "Rotterdam, Países Bajos", 2880, 13);
    PuertoMaritimo* nodo14 = new PuertoMaritimo("Puerto de Amberes ", "Amberes, Bélgica", 1430, 14);
    PuertoMaritimo* nodo15 = new PuertoMaritimo("Puerto de Kaohsiung", "Kaohsiung, Taiwán", 250, 15);

    PuertoMaritimo* nodo16 = new PuertoMaritimo("Puerto de Hamburgo", "Hamburgo, Alemania", 100, 16);
    PuertoMaritimo* nodo17 = new PuertoMaritimo("Puerto de New York/New Jersey", "Nueva York, EE.UU", 150, 17);
    PuertoMaritimo* nodo18 = new PuertoMaritimo("Puerto de Los Ángeles", "Los Ángeles, EE.UU.", 200, 18);
    PuertoMaritimo* nodo19 = new PuertoMaritimo("Puerto de Long Beach", "Long Beach, EE.UU.", 120, 19);
    PuertoMaritimo* nodo20 = new PuertoMaritimo("Puerto de Santos", "Santos, Brasil", 250, 20);

    // Agrega más nodos de manera similar

    grafo.addNode(nodo1);
    grafo.addNode(nodo2);
    grafo.addNode(nodo3);
    grafo.addNode(nodo4);
    grafo.addNode(nodo5);
    grafo.addNode(nodo6);
    grafo.addNode(nodo7);
    grafo.addNode(nodo8);
    grafo.addNode(nodo9);
    grafo.addNode(nodo10);
    grafo.addNode(nodo11);
    grafo.addNode(nodo12);
    grafo.addNode(nodo13);
    grafo.addNode(nodo14);
    grafo.addNode(nodo15);
    grafo.addNode(nodo16);
    grafo.addNode(nodo17);
    grafo.addNode(nodo18);
    grafo.addNode(nodo19);
    grafo.addNode(nodo20);

    // Agrega más nodos al grafo

    // Más arcos entre puertos de Asia

    // Grupo 1
    grafo.addArc(nodo1, nodo2, 300);  
    grafo.addArc(nodo1, nodo3, 800);
    grafo.addArc(nodo2, nodo3, 1200);
    grafo.addArc(nodo1, nodo4, 700);
    grafo.addArc(nodo2, nodo4, 900);

    // Grupo 2  
    grafo.addArc(nodo5, nodo6, 500);
    grafo.addArc(nodo5, nodo7, 400); 
    grafo.addArc(nodo6, nodo7, 600);
    grafo.addArc(nodo5, nodo8, 350);
    grafo.addArc(nodo6, nodo8, 480);

    // Grupo 3
    grafo.addArc(nodo9, nodo10, 1100);   
    grafo.addArc(nodo9, nodo11, 900);
    grafo.addArc(nodo10, nodo11, 1400);
    grafo.addArc(nodo9, nodo12, 1300);  
    grafo.addArc(nodo10, nodo12, 890);

    // Grupo 4  
    grafo.addArc(nodo13, nodo14, 1600);
    grafo.addArc(nodo13, nodo15, 1900);  
    grafo.addArc(nodo14, nodo15, 800); 
    grafo.addArc(nodo13, nodo16, 1200);
    grafo.addArc(nodo14, nodo16, 1700);

    // Grupo 4  
    grafo.addArc(nodo17, nodo18, 1300);
    grafo.addArc(nodo17, nodo19, 1200);  
    grafo.addArc(nodo18, nodo19, 2000); 
    grafo.addArc(nodo17, nodo19, 1700);
    grafo.addArc(nodo18, nodo20, 1100);

    vector<vector<NodoGrafo*>> connectedComponents = grafo.deepPath(nodo1);


    // Imprime las componentes conexas
    for (size_t i = 0; i < connectedComponents.size(); i++)
    {
        cout << "Componente Conexa " << i + 1 << ", Tamaño = " << connectedComponents[i].size() <<  ":" << endl ;

        for(int j=0; j<connectedComponents[i].size(); j++) {
            PuertoMaritimo puerto = *((PuertoMaritimo*)(void*)connectedComponents[i][j]);
            cout << "ID: " << puerto.getId() << ", Nombre: " << puerto.getNombre() << ", Ciudad: " << puerto.getCiudad() << endl;

        }
       
    }

    return 0;
}