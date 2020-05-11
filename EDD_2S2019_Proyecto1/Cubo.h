//
// Created by User on 11/09/2019.
//

#ifndef EDD_2S2019_PROYECTO1_201709396_CUBO_H
#define EDD_2S2019_PROYECTO1_201709396_CUBO_H

#include <string>

class Cubo {
public:
    Cubo();
    Cubo(std::string name, int pixelAncho, int pixelAlto, int imagenAlto, int  imagenAncho );
    std::string name;
    int row = 0;
    int column = 0;
    int size = 0;
    int pixel = 0;
};

#endif //EDD_2S2019_PROYECTO1_201709396_CUBO_H
