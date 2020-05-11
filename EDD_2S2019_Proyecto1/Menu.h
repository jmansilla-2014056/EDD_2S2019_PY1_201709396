//
// Created by User on 12/09/2019.
//

#ifndef EDD_2S2019_PROYECTO1_201709396_MENU_H
#define EDD_2S2019_PROYECTO1_201709396_MENU_H


#include "PrepararArchivos.h"
#include "PrepararFiltros.h"

class Menu {
public:
    void menu();
    PrepararArchivos* pr = new PrepararArchivos();
    PrepararFiltros* pf = new PrepararFiltros();
};


#endif //EDD_2S2019_PROYECTO1_201709396_MENU_H
