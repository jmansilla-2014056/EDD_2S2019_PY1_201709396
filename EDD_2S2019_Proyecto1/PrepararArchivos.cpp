//
// Created by User on 13/09/2019.
//
#include <iostream>
#include<fstream>
#include<windows.h>
#include "PrepararArchivos.h"
#include "GenerarMatrizes.h"

using namespace std;

std::vector<string> rutas;
std::vector<string> temporal;
GenerarMatrizes* generarMatrizes = new  GenerarMatrizes();

void PrepararArchivos::enlistarRutas(const string &ruta, const string &filename) {

    ifstream file;
    string temp = ruta+filename;
    cout << filename << endl;
    file.open(temp, ios::in);

    //Leer el archivo y guardar datos
    while (file.good()) {
        string line;
        getline(file, line, ',');
        cout << line << endl;
        rutas.push_back(line);
        getline(file, line, '\n');
        cout << line << endl;
        rutas.push_back(line);
    }
    file.close();
    cout << "Pase" << endl;
    //Borrar datos inicesarios
    rutas.erase(rutas.begin());
    rutas.erase(rutas.begin());

    //Optimizar espacio
    string order_Rut[(rutas.size()/2)];

    //Obtener ruta de la carpeta
    string directory;
    const size_t last_slash_idx = ruta.rfind('\\');
    if (std::string::npos != last_slash_idx)
    {
        directory = ruta.substr(0, last_slash_idx);
    }
    cout << "Pase 2"<< endl;
    //Ordener archivos y guardarlos
    for(size_t i=0; i<rutas.size();i++){
        cout << rutas[i] << endl;
        cout << rutas[i+1] << endl;
        int x = stoi(rutas[i]);
        order_Rut[x] = rutas[i+1];//directory +"\\" + rutas[i+1];
        i++;
    }

    cout << "Pase 3 " << endl;
    for(auto &item : order_Rut){
       temporal.push_back(item);
       cout << item << endl;
    }

    generarMatrizes->constriurMatriz(temporal, ruta);
    temporal.clear();
    rutas.clear();
}


