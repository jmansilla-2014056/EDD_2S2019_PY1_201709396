//
// Created by User on 12/09/2019.
//
#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "PrepararArchivos.h"
#include "PrepararFiltros.h"

using namespace std;

bool bandera=false;
char tecla;

void Menu::menu() {
    do{
        system("clear");
        cin.clear();
        cout << "Menu" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 Cargar archivos" << endl;
        cout << "\t2 Seleccionar imagen" << endl;
        cout << "\t3 Aplicar filtro general" << endl;
        cout << "\t4 Aplicar filtro a una capa" << endl;

        cout << "\t4 Salir" << endl << endl;

        cin >> tecla;
        string input = "";
        string input2 = "";
        switch(tecla)
        {
            case '1':
                system("clear");
                cout << "Ingrese ruta\n";
                cin >> input;
                cout << "Ingrese nombre archivo\n";
                cin >> input2;
                pr->enlistarRutas(input,input2);
                break;
            case '2':
                system("clear");
                pf->pedirImgen();
                break;
            case '3':
                system("clear");
                cout << "Aplicar filtro general\n";
                pf->generarImagen(7);
                break;
            case '4':
                system("clear");
                cout << "Aplicar filtro a una capa\n";
            case '5':
                system("clear");
                cout << "Salir \n";
                bandera=true;
                //exit(1);
                break;

            default:
                system("clear");
                cout << "Opcion no valida.\a\n";
                break;

        }
    }while(!bandera);

}
