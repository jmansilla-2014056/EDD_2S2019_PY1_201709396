//
// Created by User on 18/09/2019.
//


#include <iostream>
#include<fstream>
#include "GenerarMatrizes.h"
#include "Matris.h"
#include <vector>
#include <windows.h>
#include <algorithm>
#include "GenerarMatrizes.h"
#ifndef EDD_2S2019_PROYECTO1_201709396_PREPARARFILTROS_H
#define EDD_2S2019_PROYECTO1_201709396_PREPARARFILTROS_H
using namespace std;

    class PrepararFiltros: GenerarMatrizes{
    public:
        void pedirImgen();
        void generarImagenNormal(int x);
        void verMatrises();
        void Reportar(Matris* matris, int filter);

        void generar_Reporte(Matris *tmp);

        void generar_Reporte(NodoMatris *tmp);
    };


#endif //EDD_2S2019_PROYECTO1_201709396_PREPARARFILTROS_H
