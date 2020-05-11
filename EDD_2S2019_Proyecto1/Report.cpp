//
// Created by User on 20/09/2019.
//

#include "Report.h"
#include "NodoMatris.h"
#include "PrepararFiltros.h"
#include "GenerarMatrizes.h"
#include "NodoMatris.h"
#include "Matris.h"
#include <string>
#include <vector>
#include <regex>
#include <windows.h>

void Report::generar_Reporte(NodoMatris *tmp, string nombre) {
    ofstream file;
    cout << "Generar reporte:" << endl;
    cout << nombre << endl;
    file.open(nombre+".dot");
    file << "digraph Grafica{" << endl;
    file << "node[shape=box]" << endl;
    file << "Cabecera [with=1.5 style=filled, fillcolor=green, group= 1];";

    file << "e0[shape=point, width= 0];";
    file << "e1[shape=point, width= 0];";

    NodoMatris* aux = tmp;
    aux = aux->abajo;
    while (aux != nullptr) {
        file << "f" << aux->x << "[label=\"" << aux->y << "\"width = 1.5 style=filled, fillcolor=gray, group= 0 ]" << endl;
        if (aux->abajo != nullptr) {
            file << "f" << aux->abajo->y << "[label=\"" << aux->abajo->y << "\"width = 1.5 style=filled, fillcolor=gray, group= 0 ]" << endl;
            file << "f" << aux->y << "->f" << aux->abajo->y << endl;
            file << "f" << aux->abajo->y << "->f" << aux->y << endl;

        }

        aux = aux->abajo;
    }

    aux = tmp->siguiente;
    while (aux != nullptr) {
        file << "c" << aux->x << "[label=\"" << aux->x << "\"width = 1.5 style=filled, fillcolor=gray, group= " << aux->x << " ]" << endl;
        if (aux->siguiente != nullptr) {
            file << "c" << aux->siguiente->x << "[label=\"" << aux->siguiente->x << "\"width = 1.5 style=filled, fillcolor=gray, group= " << aux->siguiente->x << " ]" << endl;

            file << "c" << aux->x << "->c" << aux->siguiente->x << endl;
            file << "c" << aux->siguiente->x << "->c" << aux->x << endl;

        }
        aux = aux->siguiente;
    }
    aux = tmp->abajo;

    while (aux != nullptr) {
        NodoMatris* t = aux->siguiente;
        while (t != nullptr) {
            file << "F" << t->y << "_C" << t->x << "[width = 1.5 style=filled, fillcolor=gray, group= " << t->x << ", rank = f" << t->y << ";]" << endl;
            if (t->siguiente != nullptr) {
                file << "F" << t->y << "_C" << t->x << "->" << "F" << t->siguiente->y << "_C" << t->siguiente->x << endl;
            }
            if (t->abajo != nullptr) {
                file << "F" << t->y << "_C" << t->x << "->" << "F" << t->abajo->y << "_C" << t->abajo->x << endl;
            }
            if (t->arriba != nullptr and t->arriba->y != 0) {
                file << "F" << t->y << "_C" << t->x << "->" << "F" << t->arriba->y << "_C" << t->arriba->x << endl;
            }
            if (t->anterior != nullptr and t->anterior->x != 0) {
                file << "F" << t->y << "_C" << t->x << "->" << "F" << t->anterior->y << "_C" << t->anterior->x << endl;
            }
            if (t->anterior->x == 0) {
                file << "f" << t->anterior->y << "->F" << t->y << "_C" << t->x << endl;
                file << "F" << t->y << "_C" << t->x << "->" << "f" << t->anterior->y << endl;
            }
            if (t->arriba->y == 0) {
                file << "c" << t->arriba->x << "->F" << t->y << "_C" << t->x << endl;
                file << "F" << t->y << "_C" << t->x << "->" << "c" << t->arriba->x << endl;
            }

            t = t->siguiente;
        }
        aux = aux->abajo;
    }

    aux = tmp->abajo;
    while (aux != nullptr) {
        file << "{rank = same f" << aux->y << ";";
        NodoMatris* t = aux->siguiente;
        while (t != nullptr) {
            file << "F" << t->y << "_C" << t->x << ";";
            t = t->siguiente;
        }
        file << "}";
        aux = aux->abajo;
    }
    file << "{rank = same;Cabecera;" << endl;
    aux = tmp->siguiente;
    while (aux != nullptr) {
        file << "c" << aux->x << ";";
        aux = aux->siguiente;
    }
    file << "}" << endl;

    file << "Cabecera->f1" << endl;
    file << "Cabecera->c1" << endl;
    file << "}" << endl;

    string comand = "dot -Tpng" + nombre +".dot -o "+nombre+".png";
    system(comand.c_str());
    string title = "ca.png";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void Report::generar_capa(NodoMatris* tmp) {
    ofstream file;
    file.open("ca.dot");
    file << "digraph Grafica{" << endl;
    file << "node[shape=box]" << endl;
    file << "Cabecera [with=1.5, style=filled, fillcolor=green, group= 1];";

    file << "e0[shape=point, width= 0];";
    file << "e1[shape=point, width= 0];";

    NodoMatris* aux = tmp;
    aux = aux->abajo;
    while (aux != nullptr) {
        file << "f" << aux->y << "[label=\"" << aux->y << "\"width = 1.5 style=filled, fillcolor=gray, group= 0 ]" << endl;
        if (aux->abajo != nullptr) {
            file << "f" << aux->abajo->y << "[label=\"" << aux->abajo->y << "\"width = 1.5 style=filled, fillcolor=gray, group= 0 ]" << endl;


            file << "f" << aux->y << "->f" << aux->abajo->y << endl;
            file << "f" << aux->abajo->y << "->f" << aux->y << endl;

        }

        aux = aux->abajo;
    }

    aux = tmp->siguiente;
    while (aux != nullptr) {
        file << "c" << aux->x << "[label=\"" << aux->x << "\"width = 1.5 style=filled, fillcolor=gray, group= " << aux->x << " ]" << endl;
        if (aux->siguiente != nullptr) {
            file << "c" << aux->siguiente->x << "[label=\"" << aux->siguiente->x << "\"width = 1.5 style=filled, fillcolor=gray, group= " << aux->siguiente->x << " ]" << endl;

            file << "c" << aux->x << "->c" << aux->siguiente->x << endl;
            file << "c" << aux->siguiente->x << "->c" << aux->x << endl;

        }
        aux = aux->siguiente;
    }
    aux = tmp->abajo;

    while (aux != nullptr) {
        NodoMatris* t = aux->siguiente;
        while (t != nullptr) {
            file << "F" << t->y << "_C" << t->x << "[width = 1.5 style=filled, fillcolor=gray, group= " << t->x << ", rank = f" << t->y << ";]" << endl;
            if (t->siguiente != nullptr) {
                file << "F" << t->y << "_C" << t->x << "->" << "F" << t->siguiente->y << "_C" << t->siguiente->x << endl;
            }
            if (t->abajo != nullptr) {
                file << "F" << t->y << "_C" << t->x << "->" << "F" << t->abajo->y << "_C" << t->abajo->x << endl;
            }
            if (t->arriba != nullptr and t->arriba->y != 0) {
                file << "F" << t->y << "_C" << t->x << "->" << "F" << t->arriba->y << "_C" << t->arriba->x << endl;
            }
            if (t->anterior != nullptr and t->anterior->x != 0) {
                file << "F" << t->y << "_C" << t->x << "->" << "F" << t->anterior->y << "_C" << t->anterior->x << endl;
            }
            if (t->anterior->x == 0) {
                file << "f" << t->anterior->y << "->F" << t->y << "_C" << t->x << endl;
                file << "F" << t->y << "_C" << t->x << "->" << "f" << t->anterior->y << endl;
            }
            if (t->arriba->y == 0) {
                file << "c" << t->arriba->x << "->F" << t->y << "_C" << t->x << endl;
                file << "F" << t->y << "_C" << t->x << "->" << "c" << t->arriba->x << endl;
            }


            t = t->siguiente;
        }
        aux = aux->abajo;
    }

    aux = tmp->abajo;
    while (aux != nullptr) {
        file << "{rank = same f" << aux->y << ";";
        NodoMatris* t = aux->siguiente;
        while (t != nullptr) {
            file << "F" << t->y << "_C" << t->x << ";";
            t = t->siguiente;
        }
        file << "}";
        aux = aux->abajo;
    }
    file << "{rank = same;Cabecera;" << endl;
    aux = tmp->siguiente;
    while (aux != nullptr) {
        file << "c" << aux->x << ";";
        aux = aux->siguiente;
    }
    file << "}" << endl;

    file << "Cabecera->f1" << endl;
    file << "Cabecera->c1" << endl;
    file << "}" << endl;

    system("dot -Tpng ca.dot -o ca.png");
    string title = "ca.png";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}



