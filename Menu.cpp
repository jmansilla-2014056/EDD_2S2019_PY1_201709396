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
int filtro=0;
int reportes=0;

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
        cout << "\t5 Reportes" << endl;
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
                cout << "0. Aplicar filtro normal  \n";
                cout << "1. Aplicar filtro negativo  \n";
                cout << "2. Aplicar filtro escala de grises  \n";
                cout << "3. Aplicar filtro XMIRROR  \n";
                cout << "4. Aplicar filtro YMIRROR  \n";
                cout << "5. Aplicar filtro YX MIRROR  \n";
                cin >> filtro;
                if(filtro==0){
                    pf->generarImagenNormal();
                }else if(filtro==1){
                    pf->generarImagenNegative();
                }else if(filtro==2){
                    pf->generarImagenGray();
                }else if(filtro==3){
                    pf->generarImagenXMIRROR();
                }else if(filtro==4){
                    pf->generarImagenYMIRROR();
                }else if(filtro==5){
                    pf->generarImagenDOBLE();
                }
                break;
            case '4':
                system("clear");
                cout << "Aplicar filtro a una capa\n";
            case '5':
                cout << "0. Matris dispera (Capas normales)  \n";
                cout << "1. Matris dispera (Capas con filtro)  \n";
                cout << "2. Linealizar filas de una capa  \n";
                cout << "3. Linealizar columna de una capa  \n";
                cin >> reportes;
                if(reportes==0){
                    pf->Reportar_Normal();
                }else if(reportes==1){
                    pf->Reportar_Filter();
                }else if(reportes==2){
                    pf->Reportar_Lineal(1);
                }else if(reportes==3){
                    pf->Reportar_Lineal(2);
                }
                //exit(1);
                break;
            case '6':
                system("clear");
                cout << "Salir \n";
                bandera=true;

            default:
                system("clear");
                cout << "Opcion no valida.\a\n";
                break;

        }
    }while(!bandera);

}
