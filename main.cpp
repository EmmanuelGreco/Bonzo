#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <windows.h>

#define color SetConsoleTextAttribute

#include <cstdlib>
#include <ctime>

#include "funcionesBonzo.h"

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "es_ES.UTF-8");

    srand(time(0));                                 // Inicializa la semilla para la generaci�n de n�meros aleatorios.

    SetConsoleTitle("BONZO - EQUIPO 13");           // Nombre de la consola
    system("color 0b");                             // Color consola y letras

    int opcionMenu;

    //Funciones del ranking. DEBEN estar aquí ya que mientras el programa esté en ejecución, sin importar cuántos juegos se jueguen, no se deben perder las estadísticas.
    int resultadoPartidaPuntos[2] = {};
    string resultadoPartidaNombres[2] = {};
    int rankingPuntos[5] = {};
    string rankingNombres[5] = {};

    menuBienvendidaImprimir();
    system("pause");

    while(true) {
        system("cls");
        menuPrincipalImprimir();
        cin >> opcionMenu;

        opcionValida(opcionMenu);

        switch(opcionMenu) {
        case 1:
            system("cls");
            //cout << endl;
            //cout << "                                JUGAR                                " << endl;
            //cout << "—————————————————————————————————————————————————————————————————————" << endl;
            //cout << endl;
            jugar(resultadoPartidaPuntos, resultadoPartidaNombres);
            actualizarRanking(resultadoPartidaPuntos, resultadoPartidaNombres, rankingPuntos, rankingNombres);
            //system("pause");
            break;
        case 2:
            system("cls");
            cout << endl;
            cout << "                             ESTADÍSTICAS                            " << endl;
            cout << "—————————————————————————————————————————————————————————————————————" << endl;
            cout << endl;
            rankingImprimir(resultadoPartidaPuntos, resultadoPartidaNombres, rankingPuntos, rankingNombres);
            system("pause");
            break;
        case 3:
            system("cls");
            cout << endl;
            cout << "                               CRÉDITOS                              " << endl;
            cout << "—————————————————————————————————————————————————————————————————————" << endl;
            cout << endl;
            creditosImprimir();
            system("pause");
            break;
        case 4:
            system("cls");
            cout << endl;
            cout << "                                SALIR                                " << endl;
            cout << "—————————————————————————————————————————————————————————————————————" << endl;
            cout << endl;
            if (salir()) {
                salidaImprimir();
                return 0;
            }
            break;
        default:
            cout << endl;
            cout << "  ERROR! Opción no válida!" << endl;
            cout << "  Por favor ingrese un número entre 0 y 4." << endl;
            cout << endl;
            system("pause");
            break;
        }
    }
    return 0;
}
