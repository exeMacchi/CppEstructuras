/*
    4. Hacer un arreglo de estructura llamada atleta para N atletas que contenga los siguientes campos:
          • Nombre
          • País
          • Numero de medallas
       Luego, hacer un programa que devuelva los datos del atleta que ha ganado el mayor número de medallas.
*/

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

struct datosAtletas
{
    char nombre[20];
    char pais[30];
    int medallas{};
} atletas[10];

void pedirDatosAtletas(datosAtletas[]);
void buscarMaxMedallas(datosAtletas[], int&);
void mostrarResultados(datosAtletas[], int);

int main()
{
    setlocale(LC_ALL, "es_ES");

    int iAtleta{};

    pedirDatosAtletas(atletas);
    buscarMaxMedallas(atletas, iAtleta);
    mostrarResultados(atletas, iAtleta);

    return 0;
}

void pedirDatosAtletas(datosAtletas atletas[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "------ Información del atleta " << i + 1 << " ------\n";
        cout << "Nombre: "; cin.getline(atletas[i].nombre, 20, '\n');
        cout << "País: "; cin.getline(atletas[i].pais, 30, '\n');
        cout << "Cantidad de medallas: "; cin >> atletas[i].medallas;
        cout << "\n";
        cin.ignore();
    }
}

void buscarMaxMedallas(datosAtletas atletas[], int& iAtleta)
{
    int maxMedallas{0};

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            maxMedallas = atletas[i].medallas;
            iAtleta = i;
        }
        else if (atletas[i].medallas > maxMedallas)
        {
            maxMedallas = atletas[i].medallas;
            iAtleta = i;
        }
    }
}

void mostrarResultados(datosAtletas atletas[], int iAtleta)
{
    cout << "------ Atleta con mayor cantidad de medallas ------" << "\n";
    cout << "Nombre: " << atletas[iAtleta].nombre << "\n";
    cout << "País: " << atletas[iAtleta].pais << "\n";
    cout << "Cantidad de medallas: " << atletas[iAtleta].medallas << "\n";
    cout << "---------------------------------------------------" << "\n";
}