#ifndef FUNCIONESBONZO_H_INCLUDED
#define FUNCIONESBONZO_H_INCLUDED

// DECLARACIÓN DE FUNCIONES

using namespace std;


// FUNCIONES MENU
void menuBienvendidaImprimir();
void menuPrincipalImprimir();
void creditosImprimir();
void salidaImprimir();
void rankingImprimir(int resultadoPartidaPuntos[2], string resultadoPartidaNombres[2], int rankingPuntos[5], string rankingNombres[5]);
void actualizarRanking(int resultadoPartidaPuntos[2], string resultadoPartidaNombres[2], int rankingPuntos[5], string rankingNombres[5]);
//bool esNumero(int ingresoNumero);
bool opcionValida(int opcion);
bool esSN(char ingresoSN);
bool salir();


// FUNCIONES LÓGICA PRINCIPAL
void jugar(int resultadoPartidaPuntos[2], string resultadoPartidaNombres[2]);
void cargarNombres(string nombresJugadores[2]);                                 // 1) Func. CargarNombres
void determinarJugadorInic(string nombresJugadores[2], int &jugadorActual);     // 2) Funcion quién empieza primero
int tirarDado();                                                                // 3) Func. Tirar Dados
void jugarRonda(int jugadorActual, int ronda, string nombreJugador[],int &puntosJugador,
        bool soloDosDados[], int &maximosLanzamientos, int &bonzosTotales, bool &juegoAcabado, int puntosPorJugador[]); // 4) Funcion Jugar Ronda
void graficarDado(int dados[], int numDados, bool mostrarNumDado);                                                      //5) Funcion p. graficar los dados
void mostrarHitos(string nombresJugadores[], int puntosPorJugador[], int bonzoPorJugador[],
        int maximosLanzamientosExitososPorJugador[], bool juegoAcabado, int jugadorActual);                 //6) Func. mostrar Hitos
void mostrarResultadosFinales(string nombresJugadores[], int puntosPorJugador[], int bonzoPorJugador[]);    //6) Func. mostrar Hitos


#endif // FUNCIONESBONZO_H_INCLUDED
