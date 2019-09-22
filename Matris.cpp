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
#include "Report.h"
#include "NodoMatris.h"
#include "PrepararFiltros.h"
#include "GenerarMatrizes.h"
#include "NodoMatris.h"
#include "Matris.h"
#include <string>
#include <vector>
#include <regex>
#include <windows.h>
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
    this->max_columna++;
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
    this->max_fila++;
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


void Matris::graficarF() {
    ofstream grafica;
    NodoMatris* aux = this->root;

    grafica.open(this->getName() +"LF"+ ".dot", ios::out);

    if (!grafica.fail()) {
        grafica << "digraph {" << endl << "node [shape = rectangle, height=0.5, width=1.2];" << endl
                << "graph [nodesep = 1];" << endl << "rankdir=TB;" << endl;

        NodoMatris *tempA = this->root->abajo;
        NodoMatris *temp = this->root;
        int pos = 1;

        if (tempA != nullptr) {
            temp = tempA->siguiente;
        }

        while (tempA != nullptr) {
            if (temp != nullptr) {
                grafica << "\"" << pos << "\"[label=\"(" << temp->x << "," << temp->y << ")" << temp->dato << "\"];"
                        << endl;
                if (pos != 1) {
                    int anterior = pos - 1;
                    grafica << "\"" << anterior << "\"->\"" << pos << "\";" << endl;
                }
                pos++;
                temp = temp->siguiente;
            } else {
                tempA = tempA->abajo;
                if (tempA != nullptr) {
                    temp = tempA->siguiente;
                }
            }
        }

        grafica << "}";

        grafica.close();

        string creacion = "dot -Tjpg " + this->getName() + "_LF"+ "" + ".dot -o " + this->getName() + ".jpg";
        system(creacion.c_str());
        creacion = this->getName() + "_LF" + ".jpg";
        system(creacion.c_str());
        Matris* temporal = this;
        temporal->SetName(temporal->getName()+"LF");
        temporal->abrirGrafica();

    }
}


void Matris::abrirGrafica() {
    string title = this->getName()  + ".jpg";
    ShellExecute(nullptr, "open", title.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void Matris::graficarC() {
    ofstream grafica;

    grafica.open(this->getName()+"_LC" + ".dot", ios::out);

    if (!grafica.fail()) {
        grafica << "digraph {" << endl << "node [shape = rectangle, height=0.5, width=1.2];" << endl << "graph [nodesep = 1];" << endl << "rankdir=TB;" << endl;

        NodoMatris *tempA = this->root->siguiente;
        NodoMatris *temp = this->root;
        bool primero = true;
        int pos = 1;

        if (tempA != nullptr)
        {
            temp = tempA->abajo;
        }

        while (tempA != nullptr)
        {
            if (temp != nullptr) {
                grafica << "\"" << pos << "\"[label=\"(" << temp->x << "," << temp->y << ")"<< temp->dato << "\"];" << endl;
                if (pos != 1)
                {
                    int anterior = pos - 1;
                    grafica << "\"" << anterior << "\"->\"" << pos << "\";" << endl;
                }
                pos++;
                temp = temp->abajo;
            }
            else{
                tempA = tempA->siguiente;
                if (tempA != nullptr){
                    temp = tempA->abajo;
                }
            }
        }
        grafica << "}";
        grafica.close();
        string creacion = "dot -Tjpg " + this->getName() + "_LC"+ "" + ".dot -o " + this->getName() + ".jpg";
        system(creacion.c_str());
        creacion = this->getName() + "_LC" + ".jpg";
        system(creacion.c_str());
        Matris* temporal = this;
        temporal->SetName(temporal->getName()+"LC");
        temporal->abrirGrafica();

    }
}



void Matris::graficar() {
    ofstream grafica;
    grafica.open(this->getName() + ".dot", ios::out);
    if (!grafica.fail()) {
        grafica << "digraph {" << endl << "node [shape = rectangle, height=0.5, width=1.2];" << endl << "graph [nodesep = 1];" << endl << "rankdir=TB;" << endl;
        NodoMatris *tempA = this->root;
        NodoMatris *temp = this->root;
        bool primero = true;
        while (tempA != nullptr){
            if (tempA == this->root){
                if (temp == this->root) {
                    grafica << "\"" << temp->x << "-" << temp->y << "\"[label=\"" << temp->dato << "\"];" << endl;
                    temp = temp->abajo;
                }
                else if(temp != nullptr){
                    grafica << "\"" << temp->x << "-" << temp->y << "\"[label=\"" << temp->y << "\"];" << endl;
                    temp = temp->abajo;
                }
                else{
                    tempA = tempA->siguiente;
                    temp = tempA;
                }
            }
            else{
                if (primero){
                    grafica << "\"" << temp->x << "-" << temp->y << "\"[label=\"" << temp->x << "\"];" << endl;
                    temp = temp->abajo;
                    primero = false;
                }
                else if (temp != nullptr) {
                    grafica << "\"" << temp->x << "-" << temp->y << "\"[label=\"" << temp->dato << "\"];" << endl;
                    temp = temp->abajo;
                }
                else{
                    tempA = tempA->siguiente;
                    temp = tempA;
                    primero = true;
                }
            }
        }
        tempA = this->root;
        temp = tempA;

        while (tempA != nullptr)
        {
            if (tempA == this->root){
                if (temp == this->root) {
                    grafica << "\"" << temp->x << "-" << temp->y << "\"->\"" << temp->siguiente->x << "-" << temp->siguiente->y << "\"[dir=both];" << endl;
                    grafica << "\"" << temp->x << "-" << temp->y << "\"->\"" << temp->abajo->x << "-" << temp->abajo->y << "\"[dir=both];" << endl;
                    temp = temp->abajo;
                }
                else {
                    //imprime nodo derecho
                    if (temp->siguiente != nullptr)
                    {
                        grafica << "\"" << temp->x << "-" << temp->y << "\"->\"" << temp->siguiente->x << "-" << temp->siguiente->y << "\"[dir=both];" << endl;
                    }
                    if (temp->abajo != nullptr)
                    {
                        grafica << "\"" << temp->x << "-" << temp->y << "\"->\"" << temp->abajo->x << "-" << temp->abajo->y << "\"[dir=both];" << endl;
                        temp = temp->abajo;
                    }
                    else
                    {
                        tempA = tempA->siguiente;
                        temp = tempA;
                    }
                }
            }
            else
            {
                if (tempA == temp) {
                    if (temp->siguiente != nullptr){
                        grafica << "\"" << temp->x << "-" << temp->y << "\"->\"" << temp->siguiente->x << "-" << temp->siguiente->y << "\"[dir=both];" << endl;
                    }
                    if (temp->abajo != nullptr){
                        grafica << "\"" << temp->x << "-" << temp->y << "\"->\"" << temp->abajo->x << "-" << temp->abajo->y << "\"[dir=both];" << endl;
                        temp = temp->abajo;
                    }
                    else
                    {
                        tempA = tempA->siguiente;
                        temp = tempA;
                    }
                }
                else
                {
                    if (temp->siguiente != nullptr){
                        grafica << "\"" << temp->x << "-" << temp->y << "\"->\"" << temp->siguiente->x << "-" << temp->siguiente->y << "\"[dir=both];" << endl;
                    }
                    if (temp->abajo != nullptr){
                        grafica << "\"" << temp->x << "-" << temp->y << "\"->\"" << temp->abajo->x << "-" << temp->abajo->y << "\"[dir=both];" << endl;
                        temp = temp->abajo;
                    }
                    else{
                        tempA = tempA->siguiente;
                        temp = tempA;
                    }
                }
            }
        }
        tempA = this->root;
        temp = tempA;
        while (tempA != nullptr)
        {
            if (tempA == this->root){
                grafica << "{ rank=same; ";

                grafica << "\"" << temp->x << "-" << temp->y << "\" ";
                temp = temp->siguiente;

                while (temp != nullptr)
                {
                    grafica << "\"" << temp->x << "-" << temp->y << "\" ";
                    temp = temp->siguiente;
                }

                grafica << "};" << endl;
                tempA = tempA->abajo;
                temp = tempA;
            }
            else {
                grafica << "{ rank=same; ";
                grafica << "\"" << temp->x << "-" << temp->y << "\" ";
                temp = temp->siguiente;
                while (temp != nullptr)
                {
                    grafica << "\"" << temp->x << "-" << temp->y << "\" ";
                    temp = temp->siguiente;
                }
                grafica << "};" << endl;
                tempA = tempA->abajo;
                temp = tempA;
            }
        }

        grafica << "}";

        grafica.close();

        string creacion = "dot -Tjpg " + this->getName() + ".dot -o " + this->getName() + ".jpg";
        system(creacion.c_str());

        creacion = this->getName() + ".jpg";
        system(creacion.c_str());

    }

}

