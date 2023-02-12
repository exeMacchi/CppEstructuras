/*
    8. Defina una estructura que sirva para representar a una persona. La estructura debe contener dos campos: 
          • El nombre de la persona.
          • Un valor de tipo lógico que indica si la persona tiene algún tipo de discapacidad. 
       Realice un programa que dado un vector de personas rellene dos nuevos vectores: 
          1) Uno que contenga las personas que no tienen ninguna discapacidad.
          2) Otro que contenga las personas con discapacidad.
*/

#include <iostream>
#include <locale.h>
#include <string.h>

using std::cout;
using std::cin;

struct infoPersona
{
    char nombre[30];
    bool discapacidad;
} personas[10], personasConDiscapacidad[10], personasSinDiscapacidad[10];

void pedirDatos(infoPersona[], int&, int&);
void rellenarVectores(infoPersona[], infoPersona[], infoPersona[]);
void mostrarResultados(infoPersona[], infoPersona[], int, int);

int main()
{
    setlocale(LC_ALL, "es_ES");

    int discapacitados{ 0 }, noDiscapacitados{ 0 };

    pedirDatos(personas, discapacitados, noDiscapacitados);

    rellenarVectores(personas, personasConDiscapacidad, personasSinDiscapacidad);

    mostrarResultados(personasConDiscapacidad, personasSinDiscapacidad, discapacitados, noDiscapacitados);

    return 0;
}

void pedirDatos(infoPersona personas[], int& discapacitados, int& noDiscapacitados)
{
    for (int i = 0; i < 10; i++)
    {
        short x{};
        cout << "------ Persona n. " << i + 1 << " ------" << "\n";
        cout << "Nombre: "; cin.getline(personas[i].nombre, 30, '\n');
        cout << "Tiene alguna discapacidad? (Sí = 1 / No = 0): "; cin >> x;

        if (x == 1)
        {
            personas[i].discapacidad = true;
        }
        else 
        {
            personas[i].discapacidad = false;
        }
            

        if (personas[i].discapacidad)
        {
            discapacitados++;
        }
        else
        {
            noDiscapacitados++;
        }
        cout << "\n";
        cin.ignore();
    }
}

void rellenarVectores(infoPersona personas[], infoPersona personasConDiscapacidad[], 
                      infoPersona personasSinDiscapacidad[])
{
    int x{ 0 }, y{ 0 };

    for (int i = 0; i < 10; i++)
    {
        if (personas[i].discapacidad)
        {
            strcpy_s(personasConDiscapacidad[x].nombre, personas[i].nombre);
            x++;
        }
        else
        {
            strcpy_s(personasSinDiscapacidad[y].nombre, personas[i].nombre);
            y++;
        }
    }
}

void mostrarResultados(infoPersona personasConDiscapacidad[], infoPersona personasSinDiscapacidad[],
                       int discapacitados, int noDiscapacitados)
{
    cout << "\nPersonas con discapacidad: " << "\n";
    for (int x = 0; x < discapacitados; x++)
    {
        cout << personasConDiscapacidad[x].nombre << "\n";
    }

    cout << "\nPersonas sin discapacidad: " << "\n";
    for (int y = 0; y < noDiscapacitados; y++)
    {
        cout << personasSinDiscapacidad[y].nombre << "\n";
    }
}