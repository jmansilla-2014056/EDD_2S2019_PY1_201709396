//
// Created by User on 18/nullptr9/2nullptr19.
//

#include "PrepararFiltros.h"
#include "GenerarMatrizes.h"
#include "NodoMatris.h"
#include "Matris.h"
#include <string>
#include <vector>
#include <regex>

using namespace std;
vector<string> temp;
vector<vector<Matris*>> capas;
int seleccion;
void PrepararFiltros::pedirImgen()  {
    temp = this->getListanombreimagen();
    capas = this->getListaimagenes();
    for(size_t l=0; l<temp.size();l++){
        cout << to_string(l) + "." + temp[l]  << endl;
    }
    cout << "Seleccine una imagen" << endl;
   // generarImagen(2);
    cin >> seleccion;

}

void PrepararFiltros::generarImagen(int x) {
    regex verificar("\\d{1}*-\\d{1}*-\\d{1}*");
    cout << to_string(seleccion) << endl;
    cout << temp[seleccion] << endl;
    ofstream css, html;
    int contador = 0;
    vector<vector<Matris*>> flotante;
    flotante = capas;
    for(auto &item : flotante[seleccion]) {
        cout << item->getName() << endl;

        if (contador == 0) {
            string nombre_archivo = temp[seleccion] + ".css";
            html.open(temp[seleccion] + ".html");
            css.open(nombre_archivo);

            html << "<!DOCTYPE html>" << endl;
            html << "<head>" << endl;
            html << R"(<link rel="stylesheet" href=")"+nombre_archivo+"\">"<< endl;
            html << "</head>\n"
                    "<body> <div class=\"canvas\">" << endl;
            css << "body{\n"
                   "background: #333333;\n"
                   "height: 100vh;\n"
                   "display:flex;\n"
                   "justify-content: center;\n"
                   "align-items: center;\n"
                   "}" << endl;
            css <<".canvas{\n"
                  "width:570px;\n"
                  "height:510px;\n"
                  "\n"
                  "}\n"
                  ".pixel{\n"
                  "float: left;\n"
                  "width:30px;\n"
                  "height:30px;\n"
                  "}" << endl;
            contador++;
        }

        NodoMatris* aux = item->root;
        int c = 1;
        while (aux!= nullptr){
            NodoMatris* aux1 = aux;
            while (aux1!= nullptr){
                if(aux1->y==-1 or aux1->x==-1){
                    aux1 = aux1->siguiente;
                    continue;
                }
                if(aux1->dato!="x") {
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                     "background: rgb(" + aux1->dato + ");\n"
                     "}" << endl;
                    cin<< 
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }

    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
}

void PrepararFiltros::verMatrises() {
    for(auto &item : capas[seleccion]) {
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        item->rrecorreMatriz();
    }
}

