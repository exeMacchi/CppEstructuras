/*
    2. Hacer una estructura llamada "alumno", en la cual se tendrán los siguientes campos:
          • Nombre
          • Edad
          • Promedio
       Luego, pedir datos al usuario para 3 alumnos, comprobar cuál de los 3 tiene el mejor promedio y, posteriormente,
       imprimir los datos del alumno.
*/

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

struct alumno
{
    char nombre[20];
    int edad;
    float promedio;
} alumnos[3];

void pedirDatosAlumnos(alumno[]);
void comprobarPromedio(alumno[], int&);
void mostrarResultados(alumno[], int);

int main()
{
    setlocale(LC_ALL, "es_ES");
    
    int iAlumno{};

    pedirDatosAlumnos(alumnos);
    comprobarPromedio(alumnos, iAlumno);
    mostrarResultados(alumnos, iAlumno);

    return 0;
}

void pedirDatosAlumnos(alumno alumnos[])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "------ Información del estudiante " << i + 1 << " ------" << "\n";
        cout << "Nombre: "; cin.getline(alumnos[i].nombre, 20, '\n');
        cout << "Edad: "; cin >> alumnos[i].edad;
        cout << "Promedio: "; cin >> alumnos[i].promedio;
        cout << "\n";
        cin.ignore();
    }
}

void comprobarPromedio(alumno alumnos[], int& iAlumno)
{
    float promedio{ 0 };

    for (int i = 0; i < 3; i++)
    {
        if (alumnos[i].promedio > promedio)
        {
            promedio = alumnos[i].promedio;
            iAlumno = i;
        }
    }
}

void mostrarResultados(alumno alumnos[], int iAlumno)
{
    cout << "------ Datos del estudiante con mejor promedio ------" << "\n";
    cout << "Nombre: " << alumnos[iAlumno].nombre << "\n";
    cout << "Edad: " << alumnos[iAlumno].edad << "\n";
    cout << "Promedio: " << alumnos[iAlumno].promedio << "\n";
}