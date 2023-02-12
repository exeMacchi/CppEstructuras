// 6. Utilizar las 2 estructuras del problema 5, pero ahora pedir los datos para N alumnos, y calcular cuál de todos 
//    tiene el mejor promedio, e imprimir sus datos.

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

struct Calificaciones
{
    float nota1;
    float nota2;
    float nota3;
};
struct infoAlumnos
{
    char nombre[30];
    char genero[10];
    int edad;
    struct Calificaciones notas;
    float promedioFinal;

} alumnos[5];

void pedirDatosAlumnos(infoAlumnos[]);
void promediosAlumnos(infoAlumnos[], int&);
void mostrarResultados(infoAlumnos[], int);


int main()
{
    setlocale(LC_ALL, "es_ES");

    int iAlumno{};

    pedirDatosAlumnos(alumnos);
    promediosAlumnos(alumnos, iAlumno);
    mostrarResultados(alumnos, iAlumno);

    return 0;
}

void pedirDatosAlumnos(infoAlumnos alumnos[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "------ Información del alumno " << i + 1 << " ------" << "\n";
        cout << "Nombre: "; cin.getline(alumnos[i].nombre, 30, '\n');
        cout << "Edad: "; cin >> alumnos[i].edad; cin.ignore();
        cout << "Género: "; cin.getline(alumnos[i].genero, 10, '\n');
        cout << "Primera nota: "; cin >> alumnos[i].notas.nota1;
        cout << "Segunda nota: "; cin >> alumnos[i].notas.nota2;
        cout << "Tercera nota: "; cin >> alumnos[i].notas.nota3; cin.ignore();
        cout << "\n";
    }
}

void promediosAlumnos(infoAlumnos alumnos[], int& iAlumno)
{
    float maxPromedio{};

    for (int i = 0; i < 5; i++)
    {
        alumnos[i].promedioFinal = (alumnos[i].notas.nota1 + alumnos[i].notas.nota2 + alumnos[i].notas.nota3) / 3;
    }

    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            maxPromedio = alumnos[i].promedioFinal;
            iAlumno = i;
        }
        else if (alumnos[i].promedioFinal > maxPromedio)
        {
            maxPromedio = alumnos[i].promedioFinal;
            iAlumno = i;
        }
    }
}

void mostrarResultados(infoAlumnos alumnos[], int iAlumno)
{
    cout << "------ Información del alumno con mayor promedio ------" << "\n";
    cout << "Nombre: " << alumnos[iAlumno].nombre << "\n";
    cout << "Edad: " << alumnos[iAlumno].edad << "\n";
    cout << "Género: " << alumnos[iAlumno].genero << "\n";
    cout.precision(2);
    cout << "Promedio final: " << alumnos[iAlumno].promedioFinal << "\n";
    cout << "-------------------------------------------------------" << "\n";
}