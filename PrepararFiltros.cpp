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
    cin >> seleccion;

}

void PrepararFiltros::generarImagenNormal(int x) {
    regex verificar("\\d{1}*,\\d{1}*,\\d{1}*");
    string gg;
    cout << to_string(seleccion) << endl;
    cout << temp[seleccion] << endl;
    ofstream css, html;
    int contador = 0;
    for(auto &item : capas[seleccion]) {
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
    //    copiaMatris->SetName(item->getName());
    //    report->generar_capa(copiaMatris->root);

     //   Reportar(copiaMatris,7);
     //   copiaMatris->graficar("x");
     item->graficar("_Normal");
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

void PrepararFiltros::verMatrises() {
    for(auto &item : capas[seleccion]) {
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        item->rrecorreMatriz();
    }
}


void PrepararFiltros::Reportar(Matris* matris, int filter) {

    regex verificar("\\d{1}*,\\d{1}*,\\d{1}*");
    ofstream txt;
    txt.open(matris->getName()+".txt");
    txt << "digraph L {" << endl;
    txt << "node [shape=box]" << endl;
    txt << "   Mt[ label = \"Matrix\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];\n"
           "\n"
           "    /* empty nodes, needed to override graphiz' default node placement */\n"
           "    e0[ shape = point, width = 0 ];\n"
           "    e1[ shape = point, width = 0 ];" << endl;

    //Agrupar filas base
    int cuenta_filas = 0;
    NodoMatris* aux = matris->root;
    while (aux!= nullptr){
         txt << " U"+ to_string(cuenta_filas) + "[label = \""+aux->dato+"\"    pos = \"5.3,3.5!\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];" << endl;
         aux = aux->abajo;
         cuenta_filas++;
    }

    //Linkear filas base
    int cuenta_links = 0;
    NodoMatris* aux1 = matris->root;
    while (aux1!= nullptr){
        txt << " U"+ to_string(cuenta_links)+ "->U" + to_string(cuenta_links+1) << endl;
        cuenta_links++;
        cout<< aux1->x << endl;
        cout<<aux1->y<< endl;
        aux1 = aux1->abajo;

    }

    cout<<"Sali"<< endl;

    //Agrupar columnas base
    int cuenta_columnas = 0;
    NodoMatris* aux2 = matris->root->abajo;
    while (aux2!= nullptr){
        txt << " A"+ to_string(cuenta_columnas) + "[label = \""+aux->dato+"\"    pos = \"5.3,3.5!\" width = 1.5 style = filled, fillcolor = bisque1, group ="+ to_string(cuenta_columnas +2) +"];" << endl;
        aux2 = aux2->siguiente;
        cuenta_columnas++;
    }

    //Linkear columnas base
    int cuenta_enlases = 0;
    NodoMatris* aux3 = matris->root;
    while (aux3!= nullptr){
        txt << " A"+ to_string(cuenta_enlases)+ "->A" + to_string(cuenta_enlases+1) << endl;
        cuenta_enlases++;
        aux3 = aux3->siguiente;
    }

    txt<<"Mt -> U0;\n"
         "    Mt -> A0;" << endl;

    //linealizar A o Mt
    int cuenta_linear = 0;
    NodoMatris* aux4 = matris->root;
    txt << "{rank = same; Mt";
    while (aux4!= nullptr){
        txt << "; A" + to_string(cuenta_linear);
        cuenta_linear++;
        aux4 = aux4->siguiente;
    }
    txt << ";}" << endl;

    //Recorrer el resto
    NodoMatris* aux5 = matris->root;


    //int cuenta_columnas = 0;


    txt << "}" << endl;
    txt.close();
}


