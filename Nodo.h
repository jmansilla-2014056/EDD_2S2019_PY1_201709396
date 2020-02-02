//
// Created by User on 26/09/2019.
//

#ifndef EDD_2S2019_PROYECTO1_201709396_NODO_H
#define EDD_2S2019_PROYECTO1_201709396_NODO_H

#include <string>

using  namespace std;

class Nodo {
public:
    Nodo *siguiente=nullptr;
    Nodo *atras=nullptr;
    string data="";
};


#endif //EDD_2S2019_PROYECTO1_201709396_NODO_H
