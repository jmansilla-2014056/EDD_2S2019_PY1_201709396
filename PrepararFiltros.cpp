//
// Created by User on 18/nullptr9/2nullptr19.
//

#include "PrepararFiltros.h"
#include "GenerarMatrizes.h"
#include "NodoMatris.h"
#include "Matris.h"
#include "Report.h"
#include <string>
#include <vector>
#include <regex>
#include <windows.h>

using namespace std;
vector<string> temp;
vector<vector<Matris*>> capas;
int seleccion;
int base;
string nombreCapa;

string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

void PrepararFiltros::pedirImgen()  {
    temp = this->getListanombreimagen();
    capas = this->getListaimagenes();
    for(size_t l=0; l<temp.size();l++){
        cout << to_string(l) + "." + temp[l]  << endl;
    }
    cout << "Seleccine una imagen" << endl;
   // generarImagen(2);
   base = capas.size();
    cin >> seleccion;

}

void PrepararFiltros::generarImagenNegative() {
    regex verificar("\\d{1}*,\\d{1}*,\\d{1}*");
    string gg;
    cout << to_string(seleccion) << endl;
    cout << temp[seleccion] << endl;
    ofstream css, html;
    int contador = 0;
    vector<vector<Matris *>> flotante;
    flotante = capas;
    for (auto &item : flotante[seleccion]) {
        cout << item->getName() << endl;
        Matris* copiaMatris = new Matris();
        cout << item->getName() << endl;
        if (contador == 0) {
            string nombre_archivo = temp[seleccion] + ".css";
            string nombre_archivoH = temp[seleccion] + ".html";
            gg = nombre_archivoH;
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
            continue;
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
                if(aux1->dato != "x") {
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                     "background: rgb(" + aux1->dato + ");\n"
                     "}" << endl;
                    copiaMatris->insertar_elementos(aux1->x,aux1->y,aux1->dato,c);
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }
        auto* report = new Report();
        copiaMatris->SetName(item->getName()+"_Negative");
        copiaMatris->graficar();
        capas[seleccion].push_back(copiaMatris);
    //    report->generar_capa(copiaMatris->root);
    //    Reportar(copiaMatris,7);
    //    copiaMatris->graficar("x");
    //    item->graficar("_Normal");
    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
    string abrir = ExePath() + gg;
    abrir = ReplaceAll(abrir,"cmake-build-debug","");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);
}




void PrepararFiltros::Reportar_Normal() {
    for (auto &item : capas[seleccion]) {
        if(item->getName().find("_Normal") != std::string::npos ){
            cout << item->getName() << endl;
        }
    }
    cout << "Escriba nombre de la capa" << endl;
    cin >> nombreCapa;
    for (auto &item : capas[seleccion]) {
        if(item->getName() == nombreCapa ){
            item->abrirGrafica();
        }
    }
}


