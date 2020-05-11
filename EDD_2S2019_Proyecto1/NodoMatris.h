/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoMatrisMatrisMatris.h
 * Author: User
 *
 * Created on 10 de septiembre de 2019, 07:50 AM
 */

#ifndef NODOMATRIs_H
#define NODOMATRIs_H
#include <string>

using namespace std;
class NodoMatris {
public:

    NodoMatris(int x, int y, string dato, int correlatividad):
            y(y), x(x), dato(dato), correlatividad(correlatividad) {
    }
    //Constructor
    NodoMatris();
    NodoMatris *arriba=nullptr;
    NodoMatris *abajo=nullptr;
    NodoMatris *siguiente=nullptr;
    NodoMatris *anterior=nullptr;
    int y=0;
    int x=0;
    string dato="";
    int correlatividad=0;
private:
};



#endif /* NODOMATRIs_H */

