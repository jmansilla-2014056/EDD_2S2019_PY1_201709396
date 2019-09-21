//
// Created by User on 15/09/2019.
//
#include <iostream>
#include<fstream>
#include "GenerarMatrizes.h"
#include "Matris.h"
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;

static vector<Matris*> listamatrix;
vector<vector<Matris*>> GenerarMatrizes::listaimagenes;
vector<string> GenerarMatrizes::listanombreimagen;
ifstream files;

GenerarMatrizes::GenerarMatrizes() {
}

vector<string> explode(const string& s, const char& c)
{
    string buff{""};
    vector<string> v;

    for(auto n:s)
    {
        if(n != c) buff+=n; else
        if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);

    return v;
}

std::string GenerarMatrizes::ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

void GenerarMatrizes::constriurMatriz(vector<string> order_Rut, const string& path) {
    int pixel_width=0;
    int image_width=0;
    int pixel_height=0;
    int image_height=0;
    vector<string> filas;
    cout << "Generando archivos de:" << endl;

    for(size_t i=0; i<order_Rut.size();i++) {
        int correlativo = 1;
        string name = ReplaceAll(order_Rut[i], ".csv", "");
        auto *matris = new Matris();
        matris->pixel_widt = pixel_width;
        matris->image_width = image_width;
        matris->pixel_height = pixel_height;
        matris->image_height = image_height;
        string xd = order_Rut[i];
        string concatenar = path + xd;
        matris->SetName(name.substr(0, name.size()-1));
        cout << xd << endl;
        std::ios_base::iostate exceptionMask = files.exceptions() | std::ios::failbit;
        files.exceptions(exceptionMask);
        try {
            files.open(concatenar, ios::in);
        }
        catch (std::ios_base::failure &e) {
            std::cerr << e.what() << '\n';
        }
        if (files.is_open()) {
            cout << "file is open" << endl;
        } else {
            cout << "file isn't open" << endl;
        }

        if (files.fail()) {
            cout << "file open fail" << endl;
        } else {
            cout << "file open success" << endl;
        }

        while (files.good()) {
            string line;
            getline(files, line, '\n');
            cout << line << endl;
            filas.push_back(line);
        }
        files.clear();
        files.close();

        for (size_t y = 0; y < filas.size() ; y++) {
            vector<string> v{explode(filas[y], ',')};
            for (size_t x = 0; x < v.size() ; x++) {


                cout << v[x] << endl;
                string color = v[x];//  color = ReplaceAll(color,"\n","");
                matris->insertar_elementos(x, y, ReplaceAll(color,"-",","), correlativo);

                correlativo++;

            }

        }

        filas.clear();

        if (i != 0) {
            listamatrix.push_back(matris);
        }
    }

    vector<string> u{explode(path,'\\')};

    cout << u[u.size()-1] << endl;
    listanombreimagen.push_back(u[u.size()-1]);
    listaimagenes.push_back(listamatrix);
    listamatrix.clear();

}

vector<string> GenerarMatrizes::getListanombreimagen() {
    return listanombreimagen;
}

vector<vector<Matris *>> GenerarMatrizes::getListaimagenes() {
    return listaimagenes;
}
