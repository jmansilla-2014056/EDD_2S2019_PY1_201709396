/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matris.cpp
 * Author: User
 * 
 * Created on 10 de septiembre de 2019, 08:25 AM
 */

#include<cstdlib>
#include <cstring>
#include "NodoMatris.h"
#include "Matris.h"

using namespace std;

NodoMatris* Matris::buscar_fila(int y) {
    NodoMatris* temp = root;
    while (temp != nullptr) {
        if (temp->y == y) {
            return temp;
        }
        temp = temp->abajo;
    }
    return nullptr;
}

NodoMatris* Matris::buscar_columna(int x) {
    NodoMatris* temp = root;
    while (temp != nullptr) {
        if (temp->x == x) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

NodoMatris* Matris::insertar_ordenado_columna(NodoMatris *nuevo, NodoMatris *cabesa_col) {
    NodoMatris* temp = cabesa_col;
    bool bandera = false;
    while(true){
        if(temp->x == nuevo->x){
            //Si la posicion es la misma, sobre escribo
            temp->y = nuevo->y;
            temp->dato = nuevo->dato;
            return temp; //Retornamos el puntero
        }
        else if(temp->x > nuevo->x){
            // Tengo que insertarlo antes de temp
            bandera = true;
            break;
        }
        if(temp->siguiente != nullptr){
            temp = temp->siguiente;
        }
        else{
            //Tengo que insertar nuevo de temp
            //bandera = false
            break;
        }
    }
    if (bandera) {
        nuevo->siguiente = temp;
        temp->anterior->siguiente = nuevo;
        nuevo->anterior = temp->anterior;
        temp->anterior = nuevo;
    }else{
        temp-> siguiente = nuevo;
        nuevo-> anterior = temp;
    }
    return  nuevo;
}

NodoMatris *Matris::insertar_ordenado_fila(NodoMatris *nuevo, NodoMatris *cabesa_fila) {
    NodoMatris* temp = cabesa_fila;
    bool bandera = false;
    while(true){
        if(temp->y == nuevo->y){
            //Si la posicion es la misma, sobre escribo
            temp->x = nuevo->x;
            temp->dato = nuevo->dato;
            return temp; //Retornamos el puntero
        }
        else if(temp->y > nuevo->y){
            // Tengo que insertarlo antes de temp
            bandera = true;
            break;
        }
        if(temp->abajo != nullptr){
            temp = temp->abajo;
        }
        else{
            //Tengo que insertar nuevo de temp

            break;
        }
    }
    if (bandera) {
        nuevo->abajo = temp;
        temp->arriba->abajo = nuevo;
        nuevo->arriba = temp->arriba;
        temp->arriba = nuevo;
    }else{
        //Insertar antes de temporal
        temp-> abajo = nuevo;
        nuevo-> arriba = temp;
    }
    return  nuevo;
}

NodoMatris* Matris::crear_columna(int x) {
    NodoMatris* cabeza_columna = root;
    NodoMatris* columna = insertar_ordenado_columna(new NodoMatris(x,-1,"COL",0),cabeza_columna);
    return columna;
}

NodoMatris* Matris::crear_fila(int y) {
    NodoMatris* cabeza_fila = root;
    NodoMatris*  fila = insertar_ordenado_fila(new NodoMatris(-1,y,"FIL",0),cabeza_fila);
    return fila;
}

void Matris::insertar_elementos(int x, int y, string dato, int correlativo) {
    auto* nuevo = new NodoMatris(x,y,dato, correlativo);
    cout << correlativo << endl;
    NodoMatris* NodoColumna = buscar_columna(x);
    NodoMatris* NodoFila = buscar_fila(y);
    //1. Columna no existe y fila no existe
    if(NodoColumna == nullptr and NodoFila == nullptr){
        cout << "caso 1" << endl;
        //Crear Columna
        NodoColumna = crear_columna(x);
        //Crear Fila
        NodoFila = crear_fila(y);
        //Insertar de forma ordenada en columna
        nuevo = insertar_ordenado_columna(nuevo, NodoFila);
        //Insertar de forma ordenada en fila
        nuevo = insertar_ordenado_fila(nuevo, NodoColumna);
        return;
    }
        //2.columna no existe y fila existe
    else if(NodoColumna == nullptr and NodoFila != nullptr){
        cout << "caso 2" << endl;
        //crear Columna
        NodoColumna = crear_columna(x);
        //insertar de forma ordenada en columna
        nuevo = insertar_ordenado_columna(nuevo,NodoFila);
        //insertar de forma ordenea en fila
        nuevo = insertar_ordenado_fila(nuevo,NodoColumna);
    }
        //3.fila no existe y columna existe
    else if(NodoFila == nullptr and NodoColumna!= nullptr){
        cout << "caso 3" << endl;
        //Crear fila
        NodoFila = crear_fila(y);
        //Insertar de forma ordena en columna
        nuevo = insertar_ordenado_columna(nuevo,NodoFila);
        //Insertar de forma ordenada en fila
        nuevo  =  insertar_ordenado_fila(nuevo, NodoColumna);

    }
        //4.Existe Fila y columna
    else if(NodoFila != nullptr and NodoColumna!= nullptr){
        cout << "caso 4" << endl;
        //Insertar de forma ordenada columna
        nuevo = insertar_ordenado_columna(nuevo, NodoFila);
        //Insertar de forma ordena fila
        nuevo  =  insertar_ordenado_fila(nuevo, NodoColumna);
    }

}

void Matris::rrecorreMatriz() {
    NodoMatris* aux = root;
    int c = 1;
    while (aux!= nullptr){
        NodoMatris* aux1 = aux;
        while (aux1!= nullptr){
            if(aux1->y==-1 or aux1->x==-1){
                aux1 = aux1->siguiente;
                continue;
            }

            cout<< "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu" << endl;
            cout<< "Color:" + aux1->dato + " X:" + to_string(aux1->x) + " Y:" + to_string(aux1->y) + " Correlativo" + to_string(c) << endl;
            aux1 = aux1->siguiente;
            c++;
        }
        aux = aux->abajo;
    }
}

void Matris::SetName(const string n) {
    name = n;
}

string Matris::getName() {
    return this->name;
}






