/*
    7. Defina una estructura que indique el tiempo empleado por un ciclista en una etapa. La estructura debe tener tres
       campos: 
          • Horas
          • Minutos
          • Segundos.
       Escriba un programa que dado n etapas calcule el tiempo total empleado en correr todas las etapas.
*/ 

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

struct tiempoEtapas
{
    int horas;
    int minutos;
    int segundos;
} etapas[10];

void pedirDatos(tiempoEtapas[]);
void calcularTiempoTotal(tiempoEtapas[], int&, int&, int&);
void mostrarResultados(int, int, int);

int main()
{
    setlocale(LC_ALL, "es_ES");

    int horasTotales{ 0 }, minutosTotales{ 0 }, segundosTotales{ 0 };

    pedirDatos(etapas);
    calcularTiempoTotal(etapas, horasTotales, minutosTotales, segundosTotales);
    mostrarResultados(horasTotales, minutosTotales, segundosTotales);

    return 0;
}

void pedirDatos(tiempoEtapas etapas[])
{
    cout << "---------------------- Información de las etapas ----------------------" << "\n";
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "------------- Etapa n. " << i + 1 << " -------------" << "\n";
        cout << "Horas: "; cin >> etapas[i].horas;
        cout << "Minutos: "; cin >> etapas[i].minutos;
        cout << "Segundos: "; cin >> etapas[i].segundos;
        cout << "\n";
    }
}

void calcularTiempoTotal(tiempoEtapas etapas[], int& horasTotales, int& minutosTotales, int& segundosTotales)
{
    for (int i = 0; i < 10; i++)
    {
        horasTotales += etapas[i].horas;

        minutosTotales += etapas[i].minutos;
        if (minutosTotales >= 60)
        {
            minutosTotales -= 60;
            horasTotales++;
        }

        segundosTotales += etapas[i].segundos;
        if (segundosTotales >= 60)
        {
            segundosTotales -= 60;
            minutosTotales++;
        }
    }
}

void mostrarResultados(int horasTotales, int minutosTotales, int segundosTotales)
{
    cout << "------ Tiempo total empleado en correr todas las etapas ------" << "\n";
    cout << "Horas: " << horasTotales << "\n";
    cout << "Minutos: " << minutosTotales << "\n";
    cout << "Segundos: " << segundosTotales << "\n";
    cout << "--------------------------------------------------------------" << "\n";
}