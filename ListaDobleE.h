//
// Created by User on 26/09/2019.
//

#ifndef EDD_2S2019_PROYECTO1_201709396_LISTADOBLEE_H
#define EDD_2S2019_PROYECTO1_201709396_LISTADOBLEE_H

#include <string>
#include "Nodo.h"

using namespace std;

class ListaDobleE {

public:
    Nodo* primero = nullptr;
    Nodo* ultimo = nullptr;
    void insertarNodo(string dato);
    void printList(string nombre);
};

#endif //EDD_2S2019_PROYECTO1_201709396_LISTADOBLEE_H
