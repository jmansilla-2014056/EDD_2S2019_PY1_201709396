//
// Created by User on 10/09/2019.
//

#ifndef EDD_2S2019_PROYECTO1_201709396_MATRIS_H
#define EDD_2S2019_PROYECTO1_201709396_MATRIS_H


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matris.h
 * Author: User
 *
 * Created on 10 de septiembre de 2019, 08:25 AM
 */

#include "NodoMatris.h"
#include<stdlib.h>
#include<iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <utility>

class Matris {
public:

    NodoMatris* root = new NodoMatris(-1,-1,"Root",0);

    NodoMatris* buscar_fila(int y);
    NodoMatris* buscar_columna(int x);

    NodoMatris* insertar_ordenado_columna(NodoMatris* nuevo, NodoMatris* cabesa_col);
    NodoMatris* insertar_ordenado_fila(NodoMatris* nuevo, NodoMatris* cabesa_fila);
    NodoMatris* crear_columna(int x);
    NodoMatris* crear_fila(int y);
    void insertar_elementos(int x, int y, string dato, int correlativo);
    void SetName(string n);
    void rrecorreMatriz();
    string getName();

    int pixel_widt = 0;
    int image_width = 0;
    int pixel_height = 0;
    int image_height = 0;
    void graficarF();
    void graficar(string nombre);
private:
    string name;

    void AbrirGrafica(string nombre);
};

#endif /* MATRIs_H */

