#include <iostream>
#include "Menu.h"

int main() {
    Menu* menu = new Menu();
    menu->menu();
    std::cout << "Hello, World!" << std::endl;

    return 0;
}