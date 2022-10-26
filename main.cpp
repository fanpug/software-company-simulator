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
void preguntaFacil3();
void preguntaFacil4();
void preguntaIntermedia1();
void preguntaIntermedia2();
void preguntaIntermedia3();
void preguntaIntermedia4();

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
    
    preguntaFacil4();
    system("pause>nul");
    system("CLS");
    
    preguntaFacil3();
    system("pause>nul");
    system("CLS");
    
    preguntaIntermedia2();
    system("pause>nul");
    system("CLS");
    
    preguntaIntermedia3();
    system("pause>nul");
    system("CLS");
    
    preguntaIntermedia4();
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
    cout << "En este juego t\243 eres el lider de una empresa de software";
    gotoXY(22, 11);
    cout << "y, como lider, t\243 tomas las decisiones de la compañia.";

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

void preguntaFacil4()
{
    marco();

    // Pregunta Nivel 2
    gotoXY(15, 8);
    cout << "Que reconoce el nivel de gestionado?";
    
    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "Reconoce el proyecto gestionado \n\t y controlado durante el desarrollo del mismo \t definida, est\240 establecida y documentada";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    // Respuesta Nivel 3
    cout << "La forma de desarrollar proyectos est\240";

    // Control
    int o = control();
    if (o == 2)
    {
        contador++;
        gotoXY(15, 16);
        cout << "Incorrecto";
    }
    else
    {
        gotoXY(15, 16);
        cout << "Correcto";
    }
}
void preguntaFacil3()
{
    marco();

    // Pregunta Nivel 2
    gotoXY(15, 8);
    cout << "Que procesos hay que implantar para alcanzar";
    gotoXY(15, 9);
    cout << "el nivel de gestionado?";
    
    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "Gesti\242n de requisitos \n\t Planificaci\242n de proyectos \t\t\t  An\240lisis y resoluci\242n de las causas \n\t Seguimiento y control de proyectos \n\t Gesti\242n de proveedores";
	cout << "\n\t Aseguramiento de la calidad \n\t Gesti\242n de la configuraci\242n";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    cout << "Innovaci\242n organizacional";

    // Control
    int o = control();
    if (o == 2)
    {
        contador++;
        gotoXY(15, 16);
        cout << "Incorrecto";
    }
    else
    {
        gotoXY(15, 16);
        cout << "Correcto";
    }
}

void preguntaIntermedia2()
{
    marco();
    // Pregunta Nivel 2
    gotoXY(15, 8);
    cout << "Selecciona la opci\242n que contiene las areas que conforman el nivel gestionado";
    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "Gestionar los requisitos \n\t Planificaci\242n del proyecto \t\t\t    Gesti\242n de proyectos cuantitativa \n\t Supervisi\242n y control del proyecto";
	cout << "\n\t Gesti\242n de los acuerdos con proveedor \n\t Medici\242n y an\240lisis \n\t Asegurar la calidad del proceso y producto \n\t Gesti\242n de la configuraci\242n";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    cout << "Proceso organizacional del desarrollo";

    // Control
    int o = control();
    if (o == 2)
    {
        contador++;
        gotoXY(15, 16);
        cout << "Incorrecto";
    }
    else
    {
        gotoXY(15, 16);
        cout << "Correcto";
    }
}

void preguntaIntermedia3()
{
    marco();

    // Pregunta Nivel 3
    gotoXY(15, 8);
    cout << "Selecciona la opci\242n que contiene las areas que conforman el nivel definido";

    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "Performance de los procesos organizacionales \n\t Administraci\242n cuantitativa de proyectos\t    Administraci\242n de proceso";
    cout << "\n\t\t\t\t\t\t\t    Administraci\242n de proyecto \n\t\t\t\t\t\t\t    Administraci\242n de soporte";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    cout << "Administraci\242n de ingenier\241a";

    // Control
    int o = control();
    if (o == 2)
    {
        contador++;
        gotoXY(15, 16);
        cout << "Correcto";
    }
    else
    {
        gotoXY(15, 16);
        cout << "Incorrecto";
    }
}

void preguntaIntermedia4()
{
    marco();

    // Pregunta Nivel 4
    gotoXY(15, 8);
    cout << "Que procesos hay que implantar para alcanzar";
    gotoXY(15, 9);
    cout << "el nivel de gestionado de forma cuantitativa?";

    // Opciones
    gotoXY(PREGUNTA1POSX, PREGUNTAPOSY);
    cout << "Gesti\242n cuantitativa de proyectos \n\t Mejora de los procesos de la organizaci\242n \t\tSoluci\242n T\202cnica";
    gotoXY(PREGUNTA2POSX, PREGUNTAPOSY);
    cout << "Desarrollo de requisitos";

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
