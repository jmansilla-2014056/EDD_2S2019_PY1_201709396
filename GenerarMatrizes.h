//
// Created by User on 15/09/2019.
//
#include "NodoMatris.h"
#include "Matris.h"
#include <string>
#include <vector>
#ifndef EDD_2S2019_PROYECTO1_201709396_GENERARMATRIZES_H
#define EDD_2S2019_PROYECTO1_201709396_GENERARMATRIZES_H
using namespace std;

class GenerarMatrizes {
private:
    static vector<string> listanombreimagen;
    static vector<vector<Matris*>> listaimagenes;
public:
    GenerarMatrizes();
    void constriurMatriz(vector<string> order_Rut,const string &path);
    vector<string> getListanombreimagen();
    vector<vector<Matris*>> getListaimagenes();
};

#endif //EDD_2S2019_PROYECTO1_201709396_GENERARMATRIZES_H
