/*
    5: Hacer 2 estructuras una llamada promedio que tendrá los siguientes campos:
          • Nota1
          • Nota2
          • Nota3
       Luego, hacer otra estructura llamada alumno que tendrá los siguientes miembros:
          • Nombre
          • Sexo
          • Edad
       Posteriormente, hacer que la estructura promedio este anidada en la estructura alumno, luego pedir todos los 
       datos para un alumno, luego calcular su promedio, y por ultimo imprimir todos sus datos incluidos el promedio.
*/

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

} alumno;

void pedirDatosAlumno(infoAlumnos&);
void mostrarResultados(infoAlumnos);

int main()
{
    setlocale(LC_ALL, "es_Es");

    float promedio;

    pedirDatosAlumno(alumno);

    alumno.promedioFinal = (alumno.notas.nota1 + alumno.notas.nota2 + alumno.notas.nota3) / 3;

    mostrarResultados(alumno);

    return 0;
}

void pedirDatosAlumno(infoAlumnos& alumno)
{
    cout << "------ Información del alumno ------" << "\n";
    cout << "Nombre: "; cin.getline(alumno.nombre, 30, '\n');
    cout << "Edad: "; cin >> alumno.edad; cin.ignore();
    cout << "Género: "; cin.getline(alumno.genero, 10, '\n');
    cout << "Primera nota: "; cin >> alumno.notas.nota1;
    cout << "Segunda nota: "; cin >> alumno.notas.nota2;
    cout << "Tercera nota: "; cin >> alumno.notas.nota3; cin.ignore();
    cout << "\n";
}

void mostrarResultados(infoAlumnos alumno)
{
    cout << "------ Información final del alumno ------" << "\n";
    cout << "Nombre: " << alumno.nombre << "\n";
    cout << "Edad: " << alumno.edad << "\n";
    cout << "Género: " << alumno.genero << "\n";
    cout.precision(2);
    cout << "Promedio final: " << alumno.promedioFinal << "\n";
    cout << "------------------------------------------" << "\n";
}