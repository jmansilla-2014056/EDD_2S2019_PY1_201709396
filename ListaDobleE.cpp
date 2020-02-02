//
// Created by User on 26/09/2019.
//

#include "ListaDobleE.h"
#include "Matris.h"
// A linked list node
#include<cstdlib>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

/* Given a reference (pointer to pointer) to the head of a list
and an string, inserts a new node on the front of the list. */

// This function prints contents of
// linked list starting from the given node

void ListaDobleE::insertarNodo(string dato){
    Nodo* nuevo = new Nodo();
    nuevo->data = std::move(dato);

    if(primero==nullptr){
        primero = nuevo;
        ultimo = nuevo;
        primero->siguiente = primero;
        primero->atras = ultimo;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->atras = ultimo;
        nuevo->siguiente = primero;
        ultimo = nuevo;
        primero->atras = ultimo;
    }
    cout << "\n Nodo nuevo ingresaodo \n\n";

}

void ListaDobleE::printList(string nombre) {
    ofstream grafica;
    grafica.open(nombre+""+ ".dot", ios::out);
    grafica << "digraph {" << endl << "node [shape = rectangle, height=0.5, width=1.2];" << endl
            << "graph [nodesep = 1];" << endl << "rankdir=TB;" << endl;

    Nodo* actual = new Nodo();
    actual = primero;

    long count = 1;
    if(primero!= nullptr){
        do{
            cout<< count << endl;
            cout << actual->data << endl;
            grafica << actual->data + to_string(count) + "[label=\""+ actual->data + "\"];" << endl;
            grafica << actual->data + to_string(count) + "->" + actual->siguiente->data  + to_string(count+1) << endl;
            actual = actual->siguiente;
            count++;
        }while(actual!= ultimo);
    }

    grafica << ultimo->data + to_string(count) + "->" + primero->data +"1" << endl;
    grafica << primero->data +"1" + "->" + ultimo->data + to_string(count)  << endl;

    actual = ultimo;

    if(primero!= nullptr){
        do{
            cout<< count << endl;
            cout << actual->data << endl;
            grafica << actual->data + to_string(count) + "->" + actual->atras->data  + to_string(count-1) << endl;
            actual = actual->atras;
            count--;
        }while(actual!= primero);
    }

    grafica << "}";

    grafica.close();

    string creacion = "dot -Tjpg " + nombre + ".dot -o " + nombre + ".jpg";
    system(creacion.c_str());

    Matris *matriz = new Matris();
    matriz->abrir(nombre);


}