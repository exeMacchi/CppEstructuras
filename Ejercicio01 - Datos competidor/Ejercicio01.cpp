/*
    1. Hacer una estructura llamada "corredor", en la cual se tendrán los siguientes campos: 
          • Nombre
          • Edad
          • Sexo
          • Club
       Pedir datos al usuario para un corredor, y asignarle una categoría de competición:
          • Juvenil: <= 18 años
          • Señor: <= 40 años
          • Veterano: > 40 años.
       Posteriormente, imprimir todos los datos del corredor, incluida su categoría de competición.
*/ 

#include <iostream>
#include <locale.h>
#include <string.h>

using std::cout;
using std::cin;

struct corredor
{
    char nombre[20];
    int edad;
    char genero[20];
    char club[20];
    char categoria[10];
};

void pedirDatosCompetidor(corredor&);
void asignarCategoria(corredor&);
void mostrarResultados(corredor);

int main()
{
    setlocale(LC_ALL, "es_ES");

    corredor competidor;

    pedirDatosCompetidor(competidor);
    asignarCategoria(competidor);
    mostrarResultados(competidor);

    return 0;
}

void pedirDatosCompetidor(corredor& c)
{
    cout << "Nombre del competidor: "; cin.getline(c.nombre, 20, '\n');
    cout << "Edad del competidor: "; cin >> c.edad;
    cin.ignore();
    cout << "Género del competidor: "; cin.getline(c.genero, 20, '\n');
    cout << "Club del competidor: "; cin.getline(c.club, 20, '\n');
}

void asignarCategoria(corredor& c)
{
    if (c.edad > 40)
    {
        strcpy_s(c.categoria, "Veterano");
    }
    else if (c.edad <= 18)
    {
        strcpy_s(c.categoria, "Juvenil");
    }
    else
    {
        strcpy_s(c.categoria, "Señor");
    }
}

void mostrarResultados(corredor c)
{
    cout << "\n";
    cout << "--------- Datos del competidor ---------" << "\n";
    cout << "Nombre: " << c.nombre << "\n";
    cout << "Edad: " << c.edad << "\n";
    cout << "Género: " << c.genero << "\n";
    cout << "Club: " << c.club << "\n";
    cout << "Categoria: " << c.categoria << "\n";
}