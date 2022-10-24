/***********************************************
 * Hecho por:
 * Humberto Alejandro Navarro Andujo - 320669
 * Martín Francisco Ortiz Guerrero - 329783
 * Raúl Alejandro Díaz Gutiérrez - 329782
 * Lesly Alejandra Santarriaga Olivas - 345525
***********************************************/

// Librerias
#include<iostream>
#include<windows.h>

using namespace std;

// Declaración de funciones
void gotoXY(int, int); // declaring the goto function which is set up below
void marco();
void pantallaInicio();
void menuPrincipal();
void test();

// Función main
int main()
{
    pantallaInicio();
    system("pause>nul");
    system("CLS");

    menuPrincipal();
    system("pause>nul");
    system("CLS");

    test();

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
    gotoXY(0,0);
    for (int i = 0; i < 100; i++)
    {
        cout << "#";
    }

    for (int i = 0; i < 25; i++)
    {
        gotoXY(0,i);
        cout << "#";
    }

    for (int i = 0; i < 25; i++)
    {
        gotoXY(100,i);
        cout << "#";
    }

    gotoXY(0,25);
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
    cout << "Bienvenido a software company simulator 2022";
    gotoXY(32, 18);
    cout << "Presiona enter para continuar...";
}

// Función menuPrincipal, aqui se imprime el menu principal del juego
void menuPrincipal()
{
    marco();
    gotoXY(28, 8);
    cout << "En esta pantalla hay un menu de opciones para";
    gotoXY(28, 9);
    cout << "los creditos y para iniciar el juego.";
    gotoXY(28, 15);
    cout << "... o esa es la idea...";
    /*
    * podemos poner varias cosas en una pantalla o
    * tener varias pantallas y tener separado todo
    * con una variable global para el contador de
    * la puntuacion y cosas asi
    */

}

// funcion test, para probar los controles del jugador
void test()
{
    bool choose = true;
    gotoXY(3, 13);
    cout << "->";
    while(choose == true)
    {
        system("pause>nul");
        system("CLS");
        if(GetAsyncKeyState(VK_LEFT))
        {
            gotoXY(3, 13);
            cout << "->";
            continue;
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            gotoXY(6, 13);
            cout << "->";
            continue;
        }

    }
}
