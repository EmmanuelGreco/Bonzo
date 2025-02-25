#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <iomanip>      // Para utilziar setw(n) en columnas
#include <limits>       // Para numeric_limits en cin.fail()

#define color SetConsoleTextAttribute

#include <cstdlib>
#include <ctime>

#include "funcionesBonzo.h"

// DEFINICIÓN DE FUNCIONES DECLARADAS EN funcionesBonzo.h

using namespace std;

void menuBienvendidaImprimir() {
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );                                // Función para color consola
    //cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << endl;
    cout << "                           By LOS VECTORES®                          " << endl;
    cout << endl;
    cout << "                       Bienvenido a...........                       " << endl;
    cout << endl;
    color(hConsole, 14);
    cout << "          =================================================          " << endl;
    cout << "               #####    ####   ##   #  ######   ####  ®              " << endl;
    cout << "               #    #  #    #  # #  #     #    #    #                " << endl;
    cout << "               #####   #    #  #  # #    #     #    #                " << endl;
    cout << "               #    #  #    #  #   ##   #      #    #                " << endl;
    cout << "               #####    ####   #    #  ######   ####                 " << endl;
    cout << "          =================================================          " << endl;
    color(hConsole, 11);
    int dados[5] = {6, 3, 1, 3, 6};         // Muestro los dados 6 1 6
    int numDados = 5;                       // Le paso la cantidad de dados a mostrar
    bool mostrarNumDado = false;            // No muestro el número de dado (como si sucede en el juego)
    graficarDado(dados, numDados, mostrarNumDado);
    cout << endl;
    cout << endl;
    cout << "  UTN|FRGP" << endl;
    cout << endl;
    cout << "  PROGRAMACION I - TUP - 2024 - 2C" << endl;
    cout << "  NOCHE - VIRTUAL - COMISION 112" << endl;
    cout << endl << endl;
    cout << "                             ~ INGRESAR ~                            " << endl;
    cout << endl << endl;
}

void menuPrincipalImprimir() {
    cout << endl;
    cout << "                           By LOS VECTORES®                          " << endl;
    cout << endl;
    cout << "          =================================================          " << endl;
    cout << "                             BONZO  GAME!                            " << endl;
    cout << "          =================================================          " << endl;
    cout << endl << endl;
    cout << "  ¿Qué desea hacer? (Elija una opción numérica):" << endl;
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << "  1 - JUGAR" << endl;
    cout << "  2 - ESTADÍSTICAS" << endl;
    cout << "  3 - CRÉDITOS" << endl;
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << "  4 - SALIR" << endl;
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << endl;
    cout << "  Seleccione índice del 1 al 4. Opción elegida: ";
}

void creditosImprimir() {
    cout << endl;
    cout << "                           By LOS VECTORES®                          " << endl;
    cout << endl;
    cout << "          =================================================          " << endl;
    cout << "                              EQUIPO 13                              " << endl;
    cout << "          =================================================          " << endl;
    cout << endl;
    cout << "  Legajo   | Apellido, Nombres" << endl;
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << "  28629    | Acevedo, Lourdes" << endl;
    cout << "  31714    | Greco, Emmanuel Antonio" << endl;
    cout << "  31904    | Martinez, Daniel Matias" << endl;
    cout << "  31768    | Taquino, Pedro" << endl;
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << endl;
}

void salidaImprimir() {
    system("cls");
    cout << endl;
    cout << "                                SALIR                                " << endl;
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << endl;
    cout << endl;
    cout << "                         GRACIAS POR JUGAR!!                         " << endl;
    cout << endl;
    cout << endl;
    cout << "==========================  ¡Hasta luego!  ==========================" << endl;
    cout << "                           By LOS VECTORES®                          " << endl;
    cout << endl;
    cout << "          =================================================          " << endl;
    cout << "                              EQUIPO 13                              " << endl;
    cout << "          =================================================          " << endl;
    int dados[5] = {6, 3, 1, 3, 6};     // Muestro los dados 6 1 6
    int numDados = 5;                   // Le paso la cantidad de dados a mostrar
    bool mostrarNumDado = false;        // No muestro el número de dado (como si sucede en el juego)
    graficarDado(dados, numDados, mostrarNumDado);
}

void actualizarRanking(int resultadoPartidaPuntos[2], string resultadoPartidaNombres[2], int rankingPuntos[5], string rankingNombres[5]){
    for (int k = 0; k < 2; k++) {

        //colocar en ranking
        int lugarAsignado = -1;
        //compara para encontrar cual es la posición mas alta donde puede ubicarse, siendo mayor que los numeros por debajo.
        for(int i = 0; i < 5; i++) {
            if (resultadoPartidaPuntos[k] > rankingPuntos[i]) {
                lugarAsignado = i;
            }
        }
        //comenzó con el lugar asignado en -1. Si no fue modificado, significa que el nuevo puntaje no es mayor que los ya presentes en el ranking, por lo que no se debe hacer nada, y retorna.
        if (lugarAsignado == -1) return;
        //se corren todos los demas numeros un lugar
        for(int i = 0; i < lugarAsignado; i++) {
            rankingPuntos[i] = rankingPuntos[i+1];
            rankingNombres[i] = rankingNombres[i+1];
        }
        //se colocan los nuevos datos en el lugar designado.
        rankingPuntos[lugarAsignado] = resultadoPartidaPuntos[k];
        rankingNombres[lugarAsignado] = resultadoPartidaNombres[k];



        //bubble sort
        for(int j = 0; j < 5; j++) {
            bool intercambio = false;
            for(int i = 0; i < 5 - 1 - j; i++) {
                if(rankingPuntos[i] > rankingPuntos[i + 1]) {
                    int auxPuntos = rankingPuntos[i + 1];
                    string auxNombres = rankingNombres[i + 1];

                    rankingPuntos[i + 1] = rankingPuntos[i];
                    rankingNombres[i + 1] = rankingNombres[i];

                    rankingPuntos[i] = auxPuntos;
                    rankingNombres[i] = auxNombres;

                    intercambio = true;
                }
            }
            if (!intercambio) break;
        }
    }
}



void rankingImprimir(int resultadoPartidaPuntos[2], string resultadoPartidaNombres[2], int rankingPuntos[5], string rankingNombres[5]) {

    if (resultadoPartidaPuntos[0] == 0) cout << "  Jugá al menos un juego para poder mostrar el ranking correctamente!\n" << endl;

    //imprimir ranking
    for(int i = 0; i < 5; i++) {
//        cout << "INDICE: " << i << " PUNTOS: " << rankingPuntos[i] << " NOMBRES: " << rankingNombres[i] << endl;
        if (rankingPuntos[4-i] == 0) {
            cout << "  " << i+1 << "°: " << "---------------------------------------------------------------" << endl;
        } else {
            cout << "  " << i+1 << "°: " << rankingNombres[4-i] << ", con " << rankingPuntos[4-i] << " puntos!" << endl;
        }
    }
    cout << "\n";
}

/*bool esNumero(int ingresoNumero)
{
    if (ingresoNumero>=0 && ingresoNumero<=9){
        return true;
    }
    cout << endl;
    cout << "  ERROR! Opción no válida!" << endl;
    cout << "  Por favor ingrese un número entre 0 y 9." << endl;
    cout << endl;
    return false;
}*/

bool opcionValida(int opcion)
{
    if (cin.fail()) {
        // Limpiar el estado de error
        cin.clear();

        while (cin.get() != '\n'){
            // Este LOOP descarta caracteres, no hace nada dentro del ciclo
        }

        // ALTERNATIVAS QUE ENCONTRÉ
        //cin.ignore(stream_size_max, '\n');
        //while (cin.get() != '\n') {                             // Limpiar el estado de error de cin
        //}
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Ignorar la entrada incorrecta hasta el final de la línea

    } else {
        return true;                                              // La opción es válida
    }
}

bool esSN(char ingresoSN) {
    if (ingresoSN=='S' || ingresoSN=='N') {
        return true;
    }
    cout << endl;
    cout << "  ERROR! Opción no válida!" << endl;
    cout << "  Por favor, seleccione una opción válida." << endl;
    cout << endl;
    return false;
}

bool salir() {
    char confirmarSalida;

    while(true) {
        cout << "  ¿Seguro que desea SALIR? Ingrese 'S/N': ";
        cin >> confirmarSalida;

        confirmarSalida = toupper(confirmarSalida);

        if (esSN(confirmarSalida)) {
            if (confirmarSalida == 'S') {
                return true;
            }
            return false;
        }
    }
}


void jugar(int resultadoPartidaPuntos[2], string resultadoPartidaNombres[2]) {
    //SetConsoleCP(65001);
    //SetConsoleOutputCP(65001);
    //setlocale(LC_ALL, "es_ES.UTF-8");

    //srand(time(0));                                                      // Inicializa la semilla para la generaci�n de n�meros aleatorios.

    string nombresJugadores[2];                                          // Contiene los nombres de los jugadores.
    int puntosPorJugador[2] = {};                                        // Contador total de puntos.
    bool soloDosDadosPorJugador[2] = {};                                 // Para verificar quien juega con dos dados.
    int maximosLanzamientosExitososPorJugador[2] = {};                   // M�ximo de secuencias exitosas.
    int bonzoPorJugador[2] = {};                                         // Cantidad de BVAD obtenidos.
    bool juegoAcabado = false;                                           // Bool para chequear si el juego acab� antes.
    int jugadorActual;

    //PASO 1. ELECCI�N DE NOMBRES DE JUGADORES:
    cargarNombres(nombresJugadores);

    //PASO 2. DETERMINAR QUIEN COMIENZA:
    determinarJugadorInic(nombresJugadores, jugadorActual);

    //PASO 3. EJECUTAR 6 RONDAS DE MENOS 2 TURNOS.
    for (int ronda = 1; ronda <= 6; ronda++) {
        for (int turno = 0; turno < 2; turno++) {


            // PASO 4. SE EJECUTA UNA RONDA CORRESPONDIENTE AL JUGADOR QUE VA PRIMERO. SE PASAN LAS VARIABLES DECLARADAS FUERA DE AMBOS LOOPS.
            jugarRonda(jugadorActual, ronda, nombresJugadores, puntosPorJugador[jugadorActual], soloDosDadosPorJugador,
                       maximosLanzamientosExitososPorJugador[jugadorActual], bonzoPorJugador[jugadorActual], juegoAcabado, puntosPorJugador);
            cout << endl;
            system("pause"); // SE DEJA UNA PAUSA PARA PODER LEER EL TEXTO. SE LA COLOCA AQU� Y NO EN LA FUNCION YA QUE ESTA TIENE VARIOS BREAKS INTERNAMENTE.

            // PASO 5. SE CHEQUEA NUEVAMENTE PORQUE, DE HABER PERDIDO EN LA RONDA ANTERIOR, NO DEBE CAMBIARSE EL JUGADOR ACTUAL. DEBE SER RECORDADO PARA BORRARLE LOS PUNTOS.
            if (juegoAcabado) break;

            // PASO 6. SI NO SE ACAB� EL JUEGO, EL JUGADOR ACTUAL CAMBIA.
            if (jugadorActual == 0) {
                jugadorActual = 1;
            } else {
                jugadorActual = 0;
            }
        }
        //NO ELIMINAR ESTE BREAK. ESTA PARA LOOPEAR SOBRE LAS RONDAS RESTANTES SIN QUE SE REALICEN JUGADAS. ESTO ACABA EL JUEGO EN CUESTION DE MILISEGUNDOS.
        if (juegoAcabado) break;
    }

    //PASO 7. HITOS. SE MUESTRAN PUNTOS PARCIALES, LUEGO LOS 3 TIPOS DE PUNTOS EXTRA POSIBLES.
    mostrarHitos(nombresJugadores, puntosPorJugador, bonzoPorJugador, maximosLanzamientosExitososPorJugador, juegoAcabado, jugadorActual);

    //PASO 8. SE MUESTRAN LOS RESULTADOS FINALES OBTENIDOS, Y SE DECLARA UN GANADOR.
    mostrarResultadosFinales(nombresJugadores, puntosPorJugador, bonzoPorJugador);

    //PASO 9. SE ACTUALIZAN LAS VARIABLES EXTERNAS CON LOS PUNTOS OBTENIDOS POR JUGADOR.
    resultadoPartidaPuntos[0] = puntosPorJugador[0];
    resultadoPartidaPuntos[1] = puntosPorJugador[1];
    resultadoPartidaNombres[0] = nombresJugadores[0];
    resultadoPartidaNombres[1] = nombresJugadores[1];
}


// LOOP PRINCIPAL DEL JUEGO
// 1) Func. CargarNombres
void cargarNombres(string nombresJugadores[2]) {
    char confirmar ='N';
    while (toupper(confirmar)!='S') {
        system("cls");
        cout << endl;
        cout << "          =================================================          " << endl;
        cout << "                             BONZO  GAME!                            " << endl;
        cout << "          =================================================          " << endl;
        cout << endl;
        cout << endl;
        cout << "—————————————————————————————————————————————————————————————————————" << endl;
        cout << "  Antes de comenzar, deben registrar sus nombres!" << endl;
        cout << endl << endl;
        for (int i = 0; i < 2; i++) {
            cout << "  Ingrese el nombre del jugador N°" << i+1 <<": ";
            cin >> nombresJugadores[i];
            cout << endl;
        }
        cout << endl;
        cout << "  ¿Desea confirmar los nombres ingresados? (S/N) ";
        cout << endl;
        cout << "—————————————————————————————————————————————————————————————————————" << endl;
        cout << endl << "  ";
        cin >> confirmar;
    }
    system("cls");
}

// 2) Funcion quién empieza primero
void determinarJugadorInic(string nombresJugadores[2], int &jugadorActual) {
    system("cls");
    cout << endl;
    cout << "          =================================================          " << endl;
    cout << "                             BONZO  GAME!                            " << endl;
    cout << "          =================================================          " << endl;
    cout << endl;
    cout << endl;

    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << "  Lanzando dado para decidir quién comienza...\n";
    cout << endl;
    cout << endl;
    int dadoInicial = tirarDado();
    cout << "  Resultado del dado: " << dadoInicial << "\n";
    cout << endl;
    cout << endl;
    if (dadoInicial % 2 != 0) {
        cout << "  El número es impar, comienza *" << nombresJugadores[0] << "*.\n";
        jugadorActual = 0;
    } else {
        cout << "  El número es par, comienza *" << nombresJugadores[1] << "*.\n";
        jugadorActual = 1;
    }
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << endl;
    system("pause");
}

// 3) Func. Tirar Dados
int tirarDado() {
    return rand() % 6 + 1; // Genera un número entre 1 y 6;
}

// 4) Funcion Jugar Ronda
void jugarRonda(int jugadorActual, int ronda, string nombreJugador[], int &puntosJugador,
                bool soloDosDados[], int &maximosLanzamientos, int &bonzosTotales, bool &juegoAcabado, int puntosPorJugador[]) {
    // PASO 4.1. SE DECLARAN VARIABLES QUE SON DECLARADAS EN CADA TURNO, YA QUE EN CADA TURNO DEBEN COMENZAR CON ESTOS VALORES.
    int puntosRonda = 0;            // PUNTOS PARCIALES ACUMULADOS POR RONDA. NO SE SUMAN AUTOMÁTICAMENTE YA QUE LOS NUMEROS PROHIBIDOS PUEDEN HACER QUE SE PIERDAN.
    int lanzamientosExitosos = 0;   // CONTADOR DE LA RACHA DE LANZAMIENTOS EXITOSOS. SI SE OBTIENE UN "NP", SE LLEVA A 0.
    char decision, opcion;          // USADOS EN EL INPUT DE USUARIO.
    int numDados = 3;               // SE DECLARA LA CANTIDAD DE DADOS A USAR, PUEDEN SER 2 O 3. SE ASUMEN 3, PERO EN EL PASO 4.3 PUEDE CAMBIAR.
    bool seQuitara = false;

    // PASO 4.2. SI EL OPONENTE NOS CASTIGÓ, O SI OBTUVIMOS 2 NP EN RONDAS ANTERIORES, LA CANTIDAD DE DADOS ES 2. SE RESETEA LA BANDERA.
    if (soloDosDados[jugadorActual]) {
        numDados = 2;
        soloDosDados[jugadorActual] = false;
    }

    // PASO 4.3. SE DECLARA UN WHILE TRUE PARA PODER SALIR DE EL CON UN BREAK.
    while (true) {
        int oponente = 1;                       // SE ASUME QUE EL OPONENTE SERÁ EL JUGADOR 2...
        if (jugadorActual == 1) oponente = 0;   // ...PERO SI ESTÁ JUGANDO ESTE, ENTONCES EL OPONENTE SERÁ EL JUGADOR 1.
        int cuentaProhibidos = 0;               // SE CUENTA LA CANTIDAD DE "NP" OBTENIDOS POR TIRADA. PUEDE SER 1, 2 O 3. SE ACTUALIZA EN EL PASO 4.6.
        bool duplicar = false;
        int puntosTirada = 0;                   // PUNTOS DE LA TIRADA ACTUAL PARA MOSTRAR POR PANTALLA.

        system("cls");
        cout << endl;
        cout << "          =================================================          " << endl;
        cout << "                             BONZO  GAME!                            " << endl;
        cout << "          =================================================          " << endl;
        cout << endl;
        cout << endl;
        cout << "—————————————————————————————————————————————————————————————————————" << endl;
        cout << "  " << nombreJugador[0] << ": " << puntosPorJugador[0] << " puntos";
        cout << "             " << nombreJugador[1] << ": " << puntosPorJugador[1] << " puntos" << endl;
        cout << endl;
        cout << "  TURNO DE: " << nombreJugador[jugadorActual] << endl;
        cout << endl;
        cout << "    +–––––––––––––––––––––––––––––––––+" << endl;
        cout << "    |    RONDA #" << ronda << "                     |" << endl;
        if (puntosRonda<10) {
            cout << "    |    PUNTOS DE LA RONDA: " << puntosRonda << "        |" << endl;
        } else if (puntosRonda>=10 && puntosRonda<100) {
            cout << "    |    PUNTOS DE LA RONDA: " << puntosRonda << "       |" << endl;
        } else {
            cout << "    |    PUNTOS DE LA RONDA: " << puntosRonda << "      |" << endl;
        }
        cout << "    |    LANZAMIENTOS #" << lanzamientosExitosos << "              |" << endl;
        cout << "    +–––––––––––––––––––––––––––––––––+" << endl;
        cout << endl;
        cout << "  NUMERO PROHIBIDO: " << ronda << endl;
        cout << endl;
        cout << "  LANZAMIENTO #" << lanzamientosExitosos+1 << endl;
        cout << endl;

        // PASO 4.4. SE GENERA UN VECTOR CON LA CANTIDAD DE DADOS NECESARIA, Y SE LO LLENA CON TIRADAS ALEATORIAS.
        int dados[numDados];
        for (int i = 0; i < numDados; i++) {
            dados[i] = tirarDado();
        }

        //DEBUG - USAR PARA PODER INGRESAR VALORES A MANO Y PROBAR EL CÓDIGO EN CASOS ESPECÍFICOS.
//        cout << "\nDado 1: ";
//        cin >> dados[0];
//        cout << "Dado 2: ";
//        cin >> dados [1];
//        if (numDados == 3) {
//            cout << "Dado 3: ";
//            cin >> dados [2];
//        }

        // PASO 4.5. SE GRAFICAN LOS DADOS EN LA FUNCIÓN "graficarDado".
        bool mostrarNumDado = true;
        graficarDado(dados, numDados, mostrarNumDado);

        // PASO 4.6. SE MUESTRAN LOS 2 O 3 DADOS OBTENIDOS. EL TERCERO ESTÁ DENTRO DE UN IF PARA NO PRODUCIR UN ERROR SI EL TIRO SOLO TIENE 2 DADOS.
        cout << endl;
        cout << "  Resultados: " << dados[0] << ", " << dados[1];
        if (numDados == 3) {
            cout << ", " << dados[2];
        }
        cout << endl;

        // PASO 4.7. SE COMPARAN LOS 2 O 3 DADOS OBTENIDOS CON EL NÚMERO DE RONDA (NP). SI COINCIDEN, SE SUMAN AL CONTADOR PREVIAMENTE DECLARADO.
        for (int i = 0; i < numDados; i++) {
            if (dados[i] == ronda) cuentaProhibidos++;
        }

        // PASO 4.8. PENALIZACIONES.
        if (cuentaProhibidos == 1) {            //1 SOLO NP. EL BREAK TERMINA EL TURNO DE FORMA PREMATURA, NO PERMITIENDO TIRAR NUEVAMENTE.
            puntosRonda = 0;
            lanzamientosExitosos = 0;
            cout << endl;
            cout << "  ¡Sacaste el número prohibido! Perdes todos los puntos de esta ronda.\n";
            if (seQuitara) {
                seQuitara = false;
                cout << "  Perdes la ventaja obtenida por el ¡Bonzo Ve A Dormir! Tu oponente podrá usar sus tres dados.\n";
            }
            break;
        } else if (cuentaProhibidos == 2) {     //2 NP. SE PIERDEN TODOS LOS PUNTOS HASTA EL MOMENTO, Y LA SIGUIENTE RONDA SE JUEGA CON DOS DADOS.
            puntosJugador = 0;
            lanzamientosExitosos = 0;
            cout << endl;
            if (numDados == 3) {
                cout << "  ¡Sacaste el número prohibido en dos dados! Perdes todos los puntos de la partida y solo podrás lanzar con dos dados en la próxima ronda.\n";
                soloDosDados[jugadorActual] = true;
            } else if (numDados == 2) {
                cout << "  ¡Sacaste el número prohibido en los dos dados! Perdes todos los puntos de la partida, pero podrás volver a lanzar con tres dados en la próxima ronda.\n";
            }
            if (seQuitara) {
                seQuitara = false;
                cout << "  Perdes la ventaja obtenida por el ¡Bonzo Ve A Dormir! Tu oponente podrá usar sus tres dados.\n";
            }
            break;
        } else if (cuentaProhibidos == 3) {     // 3NP. SE PIERDE AUTOMÁTICAMENTE CON "juegoAcabado = true".
            cout << endl;
            cout << "  ¡Sacaste el número prohibido en los tres dados! Perdés automáticamente el juego.\n";
            puntosJugador = 0;
            lanzamientosExitosos = 0;
            juegoAcabado = true;
            break;
        }
        cout << endl;

        // PASO 4.9. SI NO SE PERDIO, SE SUMA UNO A LA RACHA DE LANZAMIENTOS EXITOSOS, Y SE LO COMPARA CON EL MAXIMO. SI SUPERA EL MAXIMO, SE ACTUALIZA EL MÁXIMO.
        lanzamientosExitosos++;
        if (lanzamientosExitosos >= maximosLanzamientos) {
            maximosLanzamientos = lanzamientosExitosos;
        }

        //PASO 4.10. BONZO VE A DORMIR (BVAD): SI LOS TRES DADOS SON IGUALES, Y NO SON EL NP.
        if (dados[0] == dados[1] && dados[1] == dados[2] && cuentaProhibidos == 0) {
            cout << "  ¡Bonzo, Ve A Dormir! Lanzaste 3 dados iguales: " << dados[0] << ", " << dados[1] << ", " << dados[2] << "\n";
            bonzosTotales++;
            cout << endl;

            // PASO 4.10.1. SE CHEQUEA SI SE LE HA QUITADO UN DADO AL OPONENTE EN UNA RONDA ANTERIOR. SI YA PERDIO UN DADO, NO SE PUEDE SACARLE OTRO.
            if (soloDosDados[oponente] || seQuitara) {
                cout << "  Tu oponente ya tiene 2 dados. No podés sacarle otro, se duplicarán tus puntos. \n";
                duplicar = true;
                // PASO 4.10.2. SI TIENE LOS TRES DADOS, PODEMOS ELEGIR ENTRE SACARLE UN DADO O DUPLICAR LOS PUNTOS.
            } else {
                cout << "  Elegí una de las siguientes opciones:" << endl;
                cout << "  Quitar un dado al oponente (Q), o duplicar los puntos obtenidos en la tirada actual (D): ";
                cin >> opcion;
                cout << endl;
                while (toupper(opcion) != 'Q' && toupper(opcion) != 'D') {
                    cout << "  Opción erronea, debés elegir entre quitar un dado al oponente (Q), o duplicar los puntos obtenidos en la tirada actual (D): ";
                    cin >> opcion;
                    cout << endl;
                }
                if(toupper(opcion) == 'Q') {
                    cout << "  ¡Le sacaste un dado a tu oponente para su siguiente turno!" << endl;
                    cout << endl;
                    seQuitara = true;
                } else if (toupper(opcion) == 'D') {
                    cout << "  ¡Duplicaste tus puntos en esta ronda!" << endl;
                    cout << endl;
                    duplicar = true;
                }
            }
        }

        // PASO 4.11. SE SUMAN LOS PUNTOS DE LA TIRADA. SI SE DECIDIÓ DUPLICAR LOS PUNTOS MEDIANTE UN BVAD, SE SUMAN LOS DADOS * 2.
        for (int i = 0; i < numDados; i++) {
            if (duplicar) {
                puntosTirada += dados[i] * 2;
            } else {
                puntosTirada += dados[i];
            }
        }

        cout << "  ¡Sumaste " << puntosTirada << " puntos!" << endl;

        // PASO 4.12. SI NO SE PERDIO, Y SE HAYA OBTENIDO UN BVAD O NO, SE LLEGA A ESTE PASO. SE SUMAN LOS PUNTOS OBTENIDOS, Y SE PREGUNTA SI SE JUEGA DE NUEVO O NO.
        puntosRonda += puntosTirada;
        cout << "  Puntos acumulados en la ronda: " << puntosRonda << endl;

        cout << endl;
        cout << "  ¿Deseas lanzar de nuevo? (S/N): ";
        cin >> decision;
        // SE VALIDA, PARA QUE NO PUEDA ENVIARSE UNA OPCIÓN INCORRECTA.
        while (toupper(decision) != 'N' && toupper(decision) != 'S') {
            cout << "  Opción erronea, debés elegir entre lanzar de nuevo (S), o pasar el turno(N): ";
            cin >> decision;
        }
        // SI SE ELIGE NO SEGUIR (N), SE ROMPE EL WHILE TRUE. SI SE ELIGE SEGUIR, EL SIGUIENTE IF ES IGNORADO Y SIGUE EL WHILE TRUE, HASTA EVENTUALMENTE PERDER O PASAR EL TURNO.
        if (toupper(decision) == 'N') {
            puntosJugador += puntosRonda;
            if (seQuitara) soloDosDados[oponente] = true;
            break;
        }
    }
}

//5) Funcion p. graficar los dados
void graficarDado(int dados[], int numDados, bool mostrarNumDado) {

    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );                // Función para color consola

    // ESTE FOR ITERA POR LA CANTIDAD DE DADOS Y MUESTRA EL NÚMERO DE DADO SI NO ESTA EN EL MENU DE INICIO
    if (mostrarNumDado) {
        cout << endl;
        for (int i = 0; i < numDados; i++) {
            cout << "     DADO  " << i+1 << " ";
        }
    }

    cout << endl << endl;

    // ESTE FOR ITERA POR LA CANTIDAD DE DADOS, DIBUJA LA PARTE SUPERIOR
    for (int i = 0; i < numDados; i++) {
        color(hConsole, 11);
        cout << "    ";
        color(hConsole, 240);
        cout << "         ";
    }

    cout << endl;

    // ESTE FOR ITERA 3 VECES, PORQUE ES LA CANTIDAD DE FILAS DEL DADO
    for (int fila = 1; fila <= 3; fila++) {
        // ESTE FOR ITERA POR LA CANTIDAD DE DADOS
        for (int i = 0; i < numDados; i++) {
            color(hConsole, 11);
            switch(dados[i]) {
            case 1:
                if (fila == 1) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "         ";
                }
                if (fila == 2) {
                    cout << "    ";
                    color(hConsole, 244);
                    cout << "    ■    ";
                }
                if (fila == 3) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "         ";
                };
                break;
            case 2:
                if (fila == 1) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "      ■  ";
                }
                if (fila == 2) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "         ";
                }
                if (fila == 3) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■      ";
                }
                break;
            case 3:
                if (fila == 1) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "      ■  ";
                }
                if (fila == 2) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "    ■    ";
                }
                if (fila == 3) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■      ";
                }
                break;
            case 4:
                if (fila == 1) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■   ■  ";
                }
                if (fila == 2) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "         ";
                }
                if (fila == 3) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■   ■  ";
                }
                break;
            case 5:
                if (fila == 1) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■   ■  ";
                }
                if (fila == 2) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "    ■    ";
                }
                if (fila == 3) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■   ■  ";
                }
                break;
            case 6:
                if (fila == 1) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■   ■  ";
                }
                if (fila == 2) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■   ■  ";
                }
                if (fila == 3) {
                    cout << "    ";
                    color(hConsole, 240);
                    cout << "  ■   ■  ";
                }
                break;
            }
        }
        cout << endl;
    }

    // ESTE FOR ITERA POR LA CANTIDAD DE DADOS, DIBUJA LA PARTE INFERIOR
    for (int i = 0; i < numDados; i++) {
        color(hConsole, 11);
        cout << "    ";
        color(hConsole, 240);
        cout << "         ";
    }
    cout << endl << endl;
    color(hConsole, 11);
}

//7) Func. mostrar Hitos
void mostrarHitos(string nombresJugadores[], int puntosPorJugador[], int bonzoPorJugador[],
                  int maximosLanzamientosExitososPorJugador[], bool juegoAcabado, int jugadorActual) {

    int puntosExtraMayorLanzamiento[2] = {};

    system("cls");
    cout << "          =================================================          " << endl;
	cout << "                             BONZO  GAME!                            " << endl;
	cout << "          =================================================          " << endl;
	cout << endl;
	cout << endl;

    cout << endl << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << "  "
        << left << setw(25) << "HITO"
        << right << setw(15) << nombresJugadores[0]
        << " "
        << left << setw(5) << ""
        << right << setw(12) << nombresJugadores[1]
        << " "
        << left << setw(5) << "   ";
    cout << endl << "—————————————————————————————————————————————————————————————————————" << endl;

    //cout << setw(70) << '\n';
    cout << "  "
        << left << setw(25) << "PUNTOS"
        << right << setw(10) << puntosPorJugador[0]
        << " "
        << left << setw(5) << "PTS"
        << right << setw(12) << puntosPorJugador[1]
        << " "
        << left << setw(5) << "PTS"
        << endl;

    //cout << setw(70) << '\n';
    cout << "  "
        << left << setw(25) << "Extra cada 50 puntos"
        << right << setw(10) << (puntosPorJugador[0] / 50) * 3
        << left << setw(5) << " PTS (" << (puntosPorJugador[0] / 50) << ")"
        << right << setw(10) << (puntosPorJugador[1] / 50) * 3
        << left << setw(5) << " PTS (" << (puntosPorJugador[1] / 50) << ")"
        << endl;

    //cout << setw(70) << '\n';
    cout << "  "
        << left << setw(25) << "Bonzo, Ve a dormir"
        << right << setw(10) << bonzoPorJugador[0] * 5
        << left << setw(5) << " PTS (" << bonzoPorJugador[0] << ")"
        << right << setw(10) << bonzoPorJugador[1] * 5
        << left << setw(5) << " PTS (" << bonzoPorJugador[1] << ")"
        << endl;

    // PASO 7.1: Sumar los puntos al total del jugador
	for (int jugador = 0; jugador <= 1; jugador++) {
		puntosPorJugador[jugador] += (puntosPorJugador[jugador] / 50) * 3; // Extra cada 50 puntos
		//cout << endl << puntosPorJugador[jugador];
		puntosPorJugador[jugador] += bonzoPorJugador[jugador] * 5;         // Bonzo, ve a dormir
	}

	if (maximosLanzamientosExitososPorJugador[0] > maximosLanzamientosExitososPorJugador[1]) {
        puntosExtraMayorLanzamiento[0] = 5;
		puntosPorJugador[0] += puntosExtraMayorLanzamiento[0];
	} else if (maximosLanzamientosExitososPorJugador[1] > maximosLanzamientosExitososPorJugador[0]) {
	    puntosExtraMayorLanzamiento[1] = 5;
		puntosPorJugador[1] += puntosExtraMayorLanzamiento[1];
	} else {
        puntosExtraMayorLanzamiento[0] = 5;
        puntosExtraMayorLanzamiento[1] = 5;
		puntosPorJugador[0] += puntosExtraMayorLanzamiento[0];
		puntosPorJugador[1] += puntosExtraMayorLanzamiento[1];
	}

    //cout << setw(70) << '\n';
    cout << "  "
        << left << setw(25) << "Mayor lanzamientos"
        << right << setw(10) << puntosExtraMayorLanzamiento[0]
        << left << setw(5) << " PTS (" << maximosLanzamientosExitososPorJugador[0] << ")"
        << right << setw(10) << puntosExtraMayorLanzamiento[1]
        << left << setw(5) << " PTS (" << maximosLanzamientosExitososPorJugador[1] << ")";
    cout << endl << "—————————————————————————————————————————————————————————————————————" << endl;

	//cout << setw(70) << '\n';
    cout << "  "
        << left << setw(25) << "TOTAL"
        << right << setw(10) << puntosPorJugador[0]
        << left << setw(5) << " PTS"
        << right << setw(13) << puntosPorJugador[1]
        << left << setw(5) << " PTS";
    cout << endl << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << endl;

	// PASO 7.2: Verificar si el juego terminó prematuramente
	if (juegoAcabado) {
		cout << "\n  " << nombresJugadores[jugadorActual] << " Perdió prematuramente tras obtener 3 números prohibidos. Pierde todos los puntos.\n";
		puntosPorJugador[jugadorActual] = 0;
	}
}

//8) Resultados Finales
void mostrarResultadosFinales(string nombresJugadores[], int puntosPorJugador[], int bonzoPorJugador[]) {
    cout << endl;
	cout << "=========================  RESULTADO FINAL  =========================" << endl;
	cout << endl;

	if (puntosPorJugador[0] > puntosPorJugador[1]) {
		cout << "  GANADOR: " << nombresJugadores[0] << " con " << puntosPorJugador[0] << " puntos." << endl;
	} else if (puntosPorJugador[1] > puntosPorJugador[0]) {
		cout << "  GANADOR: " << nombresJugadores[1] << " con " << puntosPorJugador[1] << " puntos." << endl;
	} else {
		if (bonzoPorJugador[0] > bonzoPorJugador[1]) {
			cout << "  ¡" << nombresJugadores[0] << " ganó por desempate, ya que obtuvo más veces el Bonzo Ve A Dormir!\n";
		} else if (bonzoPorJugador[1] > bonzoPorJugador[0]) {
			cout << "  ¡" << nombresJugadores[1] << " ganó por desempate, ya que obtuvo más veces el Bonzo Ve A Dormir!\n";
		} else {
			cout << "  ¡Es un empate! ¡Ambos jugadores obtuvieron la misma cantidad de puntos, y la misma cantidad de Bonzo Ve A Dormir!\n";
		}
	}

	string ingreseBonzo;

	cout << endl;
	cout << "  Ingrese BONZO para continuar: ";
	cin >> ingreseBonzo;
	// SE VALIDA, PARA QUE NO PUEDA ENVIARSE UNA OPCIÓN INCORRECTA.
    while (ingreseBonzo != "BONZO") {
        cout << "  Ingrese BONZO para continuar: ";
        cin >> ingreseBonzo;
    }
}

