//
// Created by User on 11/09/2019.
//

#include "GenerarImagen.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <sstream>
#include <string>
#include "Matris.h"

GenerarImagen::GenerarImagen() {
}

    void GenerarImagen::generarImagen(Matris *matris) {
        ofstream css, html;
        html.open("Imagen.html");
        css.open("Imagen.css");

        html << "!DOCTYPE html <html> <head> < link rel=\"Imagen.css\" </head> <body> class=\"canvas\">" << endl;
        css << "body{background: #333333; height: 100vh; display:flex; justify-content: center; align-items: center;}" << endl;
        css << ".canvas{width: 57px; height: 100px;}\n .pixel{float: left;width:30px;height:50px;}" << endl;

        NodoMatris* nodoFila = matris->root->abajo;
        int i = 1;
        while(nodoFila != 0){
            NodoMatris* nodoColumna=nodoFila->siguiente;
            while(nodoColumna != 0){
                html << "<div class=\"pixel\"></div>" << endl;
                if(nodoColumna->dato != "x"){
                    for(int j =0; j < nodoColumna->dato.size(); j++){
                        if(nodoColumna->dato[j] == '-'){
                            nodoColumna->dato[j] = ',';
                        }
                    }
                    css << ".pixel:nth-child("<< i << "){ background: rgb(" << nodoColumna->dato << ");}" << endl;
                }
                i++;
                nodoColumna = nodoColumna->siguiente;
            }
            nodoFila = nodoFila->abajo;
        }
        html << "</div></body></html>" << endl;

    }
