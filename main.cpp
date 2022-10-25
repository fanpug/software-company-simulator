/***********************************************
 * Hecho por:
 * Humberto Alejandro Navarro Andujo - 320669
 * Martín Francisco Ortiz Guerrero - 329783
 * Raúl Alejandro Díaz Gutiérrez - 329782
 * Lesly Alejandra Santarriaga Olivas - 345525
 ***********************************************/
// Librerias
#include <iostream>
#include <windows.h>

// Definiciones
#define PREGUNTA1POSX 10
#define PREGUNTA2POSX 60
#define PREGUNTAPOSY 18

int contador = 0;

using namespace std;

// Declaración de funciones
void gotoXY(int, int); // declaring the goto function which is set up below
void marco();
void pantallaInicio();
void introduccion();
int control();
void test();
void ejemploPregunta();
void preguntaFacil1();
void preguntaFacil2();
void preguntaIntermedia1();

// Función main
int main()
{
    pantallaInicio();
    system("pause>nul");
    system("CLS");

    introduccion();
    system("pause>nul");
    system("CLS");

    ejemploPregunta();
    system("pause>nul");
    system("CLS");

    preguntaFacil1();
    system("pause>nul");
    system("CLS");

    preguntaFacil2();
    system("pause>nul");
    system("CLS");

    preguntaIntermedia1();
    system("pause>nul");
    system("CLS");

    return 0;
}

// Función gotoXY, nos permite escribir en partes especificas de la consola dandole coordenadas
void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función marco, imprime el marco que "delimita" el programa (100x25)
void marco()
{
    gotoXY(0, 0);
    for (int i = 0; i < 100; i++)
    {
        cout << "#";
    }

    for (int i = 0; i < 25; i++)
    {
        gotoXY(0, i);
        cout << "#";
    }

    for (int i = 0; i < 25; i++)
    {
        gotoXY(100, i);
        cout << "#";
    }

    gotoXY(0, 25);
    for (int i = 0; i < 101; i++)
    {
        cout << "#";
    }
}

// Función pantallaInicio, aqui se imprime la pantalla de inicio del programa
void pantallaInicio()
{
    marco();
    gotoXY(28, 8);
    cout << "Bienvenido a Software Company Simulator 2022";

    gotoXY(22, 10);
    cout << "En este juego tú eres el lider de una empresa de software";
    gotoXY(22, 11);
    cout << "y, como lider, tú tomas las decisiones de la compañia.";

    gotoXY(32, 19);
    cout << "Presiona enter para continuar...";
}

// Función introduccion, aqui se imprime una descripcion de la empresa que manejas como jugador y que decisiones tendras que tomar
void introduccion()
{
    marco();
    gotoXY(28, 8);
    cout << "En esta pantalla da una pequeña introduccion";
    gotoXY(28, 9);
    cout << "a como se juega el juego y que tipo de decisiones";
    gotoXY(28, 9);
    cout << "debera tomar el jugador como \"lider\" de la empresa";
    gotoXY(28, 15);
    cout << "... o esa es la idea...";
}

// Función control, esta función retorna la posicion en X de la flecha que representa la eleccion de una opcion. Si retorna 1 entonces escogió la opción de la izquierda, si retorna 2 entonces escogió la opción de la derecha
int control()
{
    // opcion = 1 es la opcion de la izquierda y dos es la opcion de la derecha
    int opcion = 1;
    gotoXY(PREGUNTA1POSX - 3, PREGUNTAPOSY);
    cout << "->";
    while (true)
    {
        system("pause>nul");
        if (GetAsyncKeyState(VK_LEFT))
        {
            opcion = 1;
            gotoXY(PREGUNTA2POSX - 3, PREGUNTAPOSY);
            cout << "  ";
            gotoXY(PREGUNTA1POSX - 3, PREGUNTAPOSY);
            cout << "->";
            continue;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            opcion = 2;
            gotoXY(PREGUNTA1POSX - 3, PREGUNTAPOSY);
            cout << "  ";
            gotoXY(PREGUNTA2POSX - 3, PREGUNTAPOSY);
            cout << "->";
            continue;
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            break;
        }
    }
    return opcion;
}

// funcion test, para probar los controles del jugador
void test()
{
    marco();
    bool choose = true;
    gotoXY(3, 13);
    cout << "->";
    while (choose == true)
    {
        system("pause>nul");
        if (GetAsyncKeyState(VK_LEFT))
        {
            gotoXY(6, 13);
            cout << "  ";
            gotoXY(3, 13);
            cout << "->";
            continue;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            gotoXY(3, 13);
            cout << "  ";
            gotoXY(6, 13);
            cout << "->";
            continue;
        }
    }
}

/************************************************
 * SECCION DE FUNCIONES DE PREGUNTAS
 * Cada funcion es una pregunta
 * La funcion de control esta escrita para que, en cada pantalla, las opciones que el jugador puede escoger deben empezar a ser escritas en las coordenadas (10,18) y (60,18) para que se alinien con las flechas
 ************************************************/

void ejemploPregunta()
{
    marco();

    // Pregunta
    gotoXY(15, 8);
    cout << "Si hubiera una disputa entre dos trabajadores sobre como resolver";
    gotoXY(15, 9);
    cout << "un problema del programa principal, como la resolverias?";

    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "Correrlos a los dos";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    cout << "Hacer que peleen a muerte";

    // Control
    int o = control();
    if (o == 2)
    {
        contador++;
        gotoXY(15, 21);
        cout << "Excelente, los trabajadores deben resolver sus diferencias!";
    }
    else
    {
        gotoXY(15, 21);
        cout << "Incorrecto, y ahora te esperan dos demandas...";
    }
}

void preguntaFacil1()
{
    marco();

    // Pregunta
    gotoXY(15, 8);
    cout << "Por cada practica, tanto generica como especifica, debemos";
    gotoXY(15, 9);
    cout << "evaluar el nivel de implementacion que existe en la organizacion";

    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "Verdadero";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    cout << "Falso";

    // Control
    int o = control();
    if (o == 2)
    {
        contador++;
        gotoXY(15, 21);
        cout << "Incorrecto";
    }
    else
    {
        gotoXY(15, 21);
        cout << "Correcto";
    }
}

void preguntaFacil2()
{
    marco();

    // Pregunta
    gotoXY(15, 8);
    cout << "Alcance del estandar CMMI pertenece a:";

    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "Gestion TI";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    cout << "Desarrollo SW";

    // Control
    int o = control();
    if (o == 2)
    {
        contador++;
        gotoXY(15, 21);
        cout << "Correcto";
    }
    else
    {
        gotoXY(15, 21);
        cout << "Incorrecto";
    }
}

void preguntaIntermedia1()
{
    marco();

    // Pregunta
    gotoXY(15, 8);
    cout << "Cuantas areas de proceso existen?";

    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "22";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    cout << "27";

    // Control
    int o = control();
    if (o == 2)
    {
        contador++;
        gotoXY(15, 21);
        cout << "Incorrecto";
    }
    else
    {
        gotoXY(15, 21);
        cout << "Correcto";
    }
}