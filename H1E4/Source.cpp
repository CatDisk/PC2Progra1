#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace System;

int* GenerarArreglo(int *cap)
{
	do
	{
		cout << "Ingrese la cantidad de alumnos: ";
		cin >> *cap;
	} while (*cap < 1 || *cap > 40);
	int *aux = new int[*cap];

	for (int i = 0; i < *cap; i++)
	{
		do
		{
			cout << "Ingrese la nota del alumno No." << i + 1 << ": ";
			cin >> aux[i];
		} while (aux[i] < 0 || aux[i] > 20);
	}
	return aux;
}

float CalcularPromedio(int *arreglo, int *cap)
{
	float prom = 0;

	for (int i = 0; i < *cap; i++)
	{
		prom += arreglo[i];
	}
	prom /= *cap;
	return prom;
}

int CalcularModa(int *arreglo, int *cap)
{
	int moda;
	int cant;
	int aux[21];

	for (int i = 0; i < 21; i++)
	{
		aux[i] = 0;
	}

	for (int i = 0; i < *cap; i++)
	{
		aux[arreglo[i]] += 1;
	}

	for (int i = 0; i < 21; i++)
	{
		if (aux[i] > cant)
		{
			cant = aux[i];
			moda = i;
		}
	}
	return moda;
}

int CalcularMaximo(int *arreglo, int *cap)
{
	int max = 0;
	for (int i = 0; i < *cap; i++)
	{
		if (arreglo[i] > max)
			max = arreglo[i];
	}
	return max;
}

int CalcularMminimo(int *arreglo, int *cap)
{
	int min = 20;
	for (int i = 0; i < *cap; i++)
	{
		if (arreglo[i] < min)
			min = arreglo[i];
	}
	return min;
}

int main()
{
	int *arreglo, *cap;
	cap = new int;

	arreglo = GenerarArreglo(cap);
	cout << endl << endl;
	cout << "El promedio es: " << CalcularPromedio(arreglo, cap) << endl;
	cout << "La moda es: " << CalcularModa(arreglo, cap) << endl;
	cout << "La nota maxima es: " << CalcularMaximo(arreglo, cap) << endl;
	cout << "La nota minima es: " << CalcularMminimo(arreglo, cap);

	_getch();
	return 0;
}