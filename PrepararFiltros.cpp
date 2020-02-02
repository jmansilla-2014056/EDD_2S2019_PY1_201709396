//
// Created by User on 18/nullptr9/2nullptr19.
//

#include "PrepararFiltros.h"
#include "GenerarMatrizes.h"
#include "NodoMatris.h"
#include "Matris.h"
#include "Report.h"
#include "ListaDobleE.h"
#include <string>
#include <vector>
#include <regex>
#include <windows.h>

using namespace std;
vector<string> temp;
vector<vector<Matris*>> capas;
int seleccion;
int base;
int nombreCapa;
string nombreFiltro;

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

////////////////////////////////////////////////////////NORMAL

void PrepararFiltros::generarImagenNormal() {
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
                  "width:"+to_string(item->image_width)+"px;\n"
                   "height:"+to_string(item->image_height)+"px;\n"
                    "\n"
                    "}\n"
                    ".pixel{\n"
                    "float: left;\n"
                    "width:"+to_string(item->pixel_widt)+"px;\n"
                                                         "height:"+to_string(item->pixel_height)+"px;\n"
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
                if(regex_match(aux1->dato,verificar)) {
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                     "background: rgb(" + aux1->dato + ");\n"
                     "}" << endl;
                    copiaMatris->insertar_elementos(aux1->x ,aux1->y,aux1->dato,c);
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }

        copiaMatris->SetName(item->getName()+"_Normal");
        copiaMatris->graficar();

        capas[seleccion][0]->CAP.push_back(copiaMatris);

    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
    string abrir = ExePath() + gg;
    abrir = ReplaceAll(abrir,"cmake-build-debug","Root\\");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);
}


void PrepararFiltros::generarImagenNegativeCapaEspecifica(string nombre) {
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
                  "width:"+to_string(item->image_width)+"px;\n"
                                                        "height:"+to_string(item->image_height)+"px;\n"
                                                                                                "\n"
                                                                                                "}\n"
                                                                                                ".pixel{\n"
                                                                                                "float: left;\n"
                                                                                                "width:"+to_string(item->pixel_widt)+"px;\n"
                                                                                                                                     "height:"+to_string(item->pixel_height)+"px;\n"
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


                if(regex_match(aux1->dato,verificar)) {

                    string convertidor;
                    vector<string> v{explode(aux1->dato, ',')};
                    for(auto &&rgb : v){
                        int color = 255-stoi(rgb);
                        if (item->getName()==nombre){
                            convertidor = convertidor + to_string(color) + ",";
                        } else{
                            convertidor = convertidor + rgb + ",";
                        }

                    }
                    convertidor = convertidor.substr(0, convertidor.size()-1);
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                                                                "background: rgb(" + convertidor + ");\n"
                                                                                                   "}" << endl;

                    copiaMatris->insertar_elementos(aux1->x ,aux1->y,convertidor,c);
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }
        copiaMatris->SetName(item->getName()+"_Negativo");
        copiaMatris->graficar();
        capas[seleccion][0]->CAP.push_back(copiaMatris);
    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
    string abrir = ExePath() + gg;
    abrir = ReplaceAll(abrir,"cmake-build-debug","Root\\");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);
}






/////////////////////////////////NEGATIVE

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
                  "width:"+to_string(item->image_width)+"px;\n"
                                             "height:"+to_string(item->image_height)+"px;\n"
                  "\n"
                  "}\n"
                  ".pixel{\n"
                  "float: left;\n"
                  "width:"+to_string(item->pixel_widt)+"px;\n"
                                                       "height:"+to_string(item->pixel_height)+"px;\n"
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


                if(regex_match(aux1->dato,verificar)) {

                    string convertidor;
                    vector<string> v{explode(aux1->dato, ',')};
                    for(auto &&rgb : v){
                        int color = 255-stoi(rgb);
                        convertidor = convertidor + to_string(color) + ",";
                    }
                    convertidor = convertidor.substr(0, convertidor.size()-1);
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                                                                "background: rgb(" + convertidor + ");\n"
                                                                                                  "}" << endl;

                    copiaMatris->insertar_elementos(aux1->x ,aux1->y,convertidor,c);
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }
        copiaMatris->SetName(item->getName()+"_Negativo");
        copiaMatris->graficar();
        capas[seleccion][0]->CAP.push_back(copiaMatris);
    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
    string abrir = ExePath() + gg;
    abrir = ReplaceAll(abrir,"cmake-build-debug","Root\\");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);
}


/////////////////////////////////ESCALA DE GRISES

void PrepararFiltros::generarImagenGray() {
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
                  "width:"+to_string(item->image_width)+"px;\n"
                                                        "height:"+to_string(item->image_height)+"px;\n"
                                                                                                "\n"
                                                                                                "}\n"
                                                                                                ".pixel{\n"
                                                                                                "float: left;\n"
                                                                                                "width:"+to_string(item->pixel_widt)+"px;\n"
                                                                                                                                     "height:"+to_string(item->pixel_height)+"px;\n"
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


                if(regex_match(aux1->dato,verificar)) {

                    string convertidor;
                    vector<string> v{explode(aux1->dato, ',')};
                    int r = stoi(v[0])*0.30;
                    int g = stoi(v[1])*0.59;
                    int b = stoi(v[2])*0.11;
                    string escala = to_string(r+g+b);
                    convertidor = escala +","+ escala + "," + escala;
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                                                                "background: rgb(" + convertidor + ");\n"
                                                                                                   "}" << endl;

                    copiaMatris->insertar_elementos(aux1->x ,aux1->y,convertidor,c);
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }
        copiaMatris->SetName(item->getName()+"_Gray");
        copiaMatris->graficar();

        capas[seleccion][0]->CAP.push_back(copiaMatris);

    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
    string abrir = ExePath() + gg;
    abrir = ReplaceAll(abrir,"cmake-build-debug","Root\\");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);
}


/////////////////////////////////XMIRROR

void PrepararFiltros::generarImagenXMIRROR() {
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

                  "transform: scale(-1, 1); width:"+to_string(item->image_width)+"px;\n"
                                                        "height:"+to_string(item->image_height)+"px;\n"
                                                                                                "\n"
                                                                                                "}\n"
                                                                                                ".pixel{\n"
                                                                                                "float: left;\n"
                                                                                                "width:"+to_string(item->pixel_widt)+"px;\n"
                                                                                                                                     "height:"+to_string(item->pixel_height)+"px;\n""}" << endl;
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
                if(regex_match(aux1->dato,verificar)) {
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                                                                "background: rgb(" + aux1->dato + ");\n"
                                                                                                   "}" << endl;
                    copiaMatris->insertar_elementos((item->max_columna)-(aux1->x) ,aux1->y,aux1->dato,c);
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }
        copiaMatris->SetName(item->getName()+"_XMIRROR");
        copiaMatris->graficar();
        capas[seleccion][0]->CAP.push_back(copiaMatris);
    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
    string abrir = ExePath()  +"\\" + gg;
    abrir = ReplaceAll(abrir,"cmake-build-debug","Root\\");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);
}

/////////////////////////////////YMIRROR

void PrepararFiltros::generarImagenYMIRROR() {
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

                  "transform: scale(1, -1); width:"+to_string(item->image_width)+"px;\n"
                                                                                 "height:"+to_string(item->image_height)+"px;\n"
                                                                                                                         "\n"
                                                                                                                         "}\n"
                                                                                                                         ".pixel{\n"
                                                                                                                         "float: left;\n"
                                                                                                                         "width:"+to_string(item->pixel_widt)+"px;\n"
                                                                                                                                                              "height:"+to_string(item->pixel_height)+"px;\n""}" << endl;
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
                if(regex_match(aux1->dato,verificar)) {
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                                                                "background: rgb(" + aux1->dato + ");\n"
                                                                                                  "}" << endl;
                    copiaMatris->insertar_elementos(aux1->x , (item->max_fila- aux1->y) ,aux1->dato,c);
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }
        copiaMatris->SetName(item->getName()+"_YMIRROR");
        copiaMatris->graficar();
        capas[seleccion][0]->CAP.push_back(copiaMatris);
    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
    string abrir = ExePath() +gg;
    cout << abrir << endl;
    abrir = ReplaceAll(abrir,"cmake-build-debug","Root\\");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);
}

void PrepararFiltros::generarImagenMosaico(int x, int y){

    regex verificar("\\d{1}*,\\d{1}*,\\d{1}*");
    string gg;
    cout << to_string(seleccion) << endl;
    cout << temp[seleccion] << endl;
    ofstream html;
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
            gg = temp[seleccion] + "_Mosaico.html";
            html.open(temp[seleccion] + "_Mosaico.html");

            html << "<!DOCTYPE html>" << endl;
            html << "<head>" << endl;
            html << R"(<link rel="stylesheet" href=")"+nombre_archivo+"\">"<< endl;
            html << "</head>\n"
                    "<body>" << endl;

            contador++;
            html << "<table style=\"width:100%\">" << endl;
            continue;
        }

    }


    for(int i=0; i<=x-1; i++) {
        cout << "Mosaico" << endl;
        html << "<tr>" << endl;
        for (int j = 0; j <= y-1; j++) {

            html << "<td>" << endl;
            html << "<div>" << endl;
            html <<R"(<iframe width=")"+ to_string((capas[seleccion][0]->image_width+20))  +"px"+ " height=" + to_string((capas[seleccion][0]->image_height+20)) + "px\" src=" + "\""+  temp[seleccion]  +R"(.html" scrolling="no" frameborder="no" ></iframe>)" << endl;
            html << "</div>" << endl;
            html << "</td>" << endl;

        }
        html << "</tr>" << endl;
    }



    html << "</table>" << endl;

     html <<       "</body>\n"
            "</html>" << endl;

    html.close();
    string abrir = ExePath() +gg;
    cout << abrir << endl;
    abrir = ReplaceAll(abrir,"cmake-build-debug","Root\\");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);

}

void PrepararFiltros::generarImagenDOBLE() {
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

                  "transform: scale(-1, -1); width:"+to_string(item->image_width)+"px;\n"
                                                                                 "height:"+to_string(item->image_height)+"px;\n"
                                                                                                                         "\n"
                                                                                                                         "}\n"
                                                                                                                         ".pixel{\n"
                                                                                                                         "float: left;\n"
                                                                                                                         "width:"+to_string(item->pixel_widt)+"px;\n"
                                                                                                                                                              "height:"+to_string(item->pixel_height)+"px;\n""}" << endl;
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
                if(regex_match(aux1->dato,verificar)) {
                    css << ".pixel:nth-child(" + to_string(c) + "){\n"
                                                                "background: rgb(" + aux1->dato + ");\n"
                                                                                                  "}" << endl;
                    copiaMatris->insertar_elementos((item->max_fila - aux1->x) , (item->max_fila- aux1->y) ,aux1->dato,c);
                }
                html << "<div class=\"pixel\">\n"
                        "</div>" << endl;
                aux1 = aux1->siguiente;
                c++;
            }
            aux = aux->abajo;
        }
        copiaMatris->SetName(item->getName()+"_DOUBLE");
        copiaMatris->graficar();
        capas[seleccion][0]->CAP.push_back(copiaMatris);
    }
    html << "</div>\n"
            "</body>\n"
            "</html>" << endl;
    css.close();
    html.close();
    string abrir = ExePath() + gg;
    abrir = ReplaceAll(abrir,"cmake-build-debug","Root\\");
    cout << abrir << endl;
    ShellExecute(NULL, NULL,abrir.c_str(),NULL, NULL, SW_SHOW);
}

void PrepararFiltros::Reportar_Normal() {
    int numero_capa=0;

    for (auto &item1: capas[seleccion][0]->CAP) {
        if(item1->getName().find("_Normal") != std::string::npos){
            cout << item1->getName() << endl;
        }
    }

    cout << "Escriba el nombre" << endl;
    cin >> nombreFiltro;

    for (auto &item2: capas[seleccion][0]->CAP) {
        if(item2->getName() == nombreFiltro){
            item2->abrirGrafica();
        }
    }

}

void PrepararFiltros::Reportar_Filter() {

    for (auto &item1: capas[seleccion][0]->CAP) {
        if(item1->getName().find("_Normal") != std::string::npos ){

        }else{
            cout << item1->getName() << endl;
        }
    }

    cout << "Escriba el nombre" << endl;
    cin >> nombreFiltro;

    for (auto &item2: capas[seleccion][0]->CAP) {
        if(item2->getName() == nombreFiltro){
            item2->abrirGrafica();
        }
    }

}

void PrepararFiltros::Reportar_Lineal(int tipo) {

    for (auto &item1: capas[seleccion][0]->CAP) {
            cout << item1->getName() << endl;
    }

    cout << "Escriba el nombre" << endl;
    cin >> nombreFiltro;

    for (auto &item2: capas[seleccion][0]->CAP) {
        if(item2->getName() == nombreFiltro){
            if(tipo==1){
                item2->graficarF();
            }else{
                item2->graficarC();
            }

        }
    }

}

void PrepararFiltros::ReportarCircular() {
        ListaDobleE* lde = new ListaDobleE();
        for (auto &item: capas[seleccion][0]->CAP) {
            lde->insertarNodo(item->getName());
            cout << item->getName() << endl;
        }
        lde->printList(temp[seleccion]+"Reporte_filtros");
}
