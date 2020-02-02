#include <iostream>
#include "Menu.h"

int main() {
    Menu* menu = new Menu();
    auto* matris = new Matris();
    matris->insertar_elementos(2,3,"dos coma tres",0);
    matris->insertar_elementos(3,4,"tres como cuatro",0);
    matris->insertar_elementos(2,2,"dos co ma dos",0);
    matris->insertar_elementos(2,2,"dos co ma dos",0);
    matris->insertar_elementos(3,5,"tres coma cinco",0);
    matris->SetName("xxxxxx");
    matris->graficar();
    std::cout << "Hello, World!" << std::endl;

    return 0;
}