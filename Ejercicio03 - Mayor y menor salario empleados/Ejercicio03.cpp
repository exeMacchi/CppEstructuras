// 3. Realizar un programa que lea un arreglo de estructuras los datos de N empleados de la empresa y que imprima los
//    datos del empleado con mayor y menor salario.

#include <iostream>
#include <locale.h>

using std::cout;
using std::cin;

struct datosEmpleados
{
    char nombre[40];
    float salario;
} empleados[10];

void pedirDatosEmpleados(datosEmpleados[]);
void buscarMaximoMinimoSalario(datosEmpleados[], float&, float&, int&, int&);
void mostrarResultados(datosEmpleados[], int, int);

int main()
{
    setlocale(LC_ALL, "es_ES");

    float salarioMaximo{0}, salarioMinimo{0};
    int iEmpleadoMaximo{0}, iEmpleadoMinimo{0};

    pedirDatosEmpleados(empleados);
    
    buscarMaximoMinimoSalario(empleados, salarioMaximo, salarioMinimo, iEmpleadoMinimo, iEmpleadoMaximo);

    mostrarResultados(empleados, iEmpleadoMaximo, iEmpleadoMinimo);

    return 0;
}

void pedirDatosEmpleados(datosEmpleados empleados[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "------ Datos empleado " << i + 1 << " ------" << "\n";
        cout << "Nombre: "; cin.getline(empleados[i].nombre, 40, '\n');
        cout << "Salario: $"; cin >> empleados[i].salario;
        cout << "\n";
        cin.ignore();
    }
}

void buscarMaximoMinimoSalario(datosEmpleados empleados[], float& salMax, float& salMin, 
                               int& iEmpMin, int& iEmpMax)
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            salMax = empleados[i].salario;
            iEmpMax = i;

            salMin = empleados[i].salario;
            iEmpMin = i;
        }
        else
        {
            if (empleados[i].salario > salMax)
            {
                salMax = empleados[i].salario;
                iEmpMax = i;
            }

            if (empleados[i].salario < salMin)
            {
                salMin = empleados[i].salario;
                iEmpMin = i;
            }
        }
    }
}

void mostrarResultados(datosEmpleados empleados[], int iEmpMax, int iEmpMin)
{
    cout << "-------------------------------------------" << "\n";
    cout << "Empleado con mayor salario: " << "\n";
    cout << "Nombre: " << empleados[iEmpMax].nombre << "\n";
    cout << "Salario: $" << empleados[iEmpMax].salario << "\n";

    cout << "\nEmpleado con menor salario: " << "\n";
    cout << "Nombre: " << empleados[iEmpMin].nombre << "\n";
    cout << "Salario: $" << empleados[iEmpMin].salario << "\n";
    cout << "-------------------------------------------" << "\n";
}