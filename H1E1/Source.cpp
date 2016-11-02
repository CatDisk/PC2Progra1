#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace System;

void Ingreso(int *arreglo, int *cap)
{
	for (int i = 0; i < *cap; i++)
	{
		do
		{
			cout << "Ingrese la nota No. " << i + 1 << " del alumno: ";
			cin >> arreglo[i];
		} while (arreglo[i] < 0 || arreglo[i] > 20);
	}
}

void HallarMenorElemento(int *arreglo, int *cap, int *pos, int *menor)
{
	for (int i = 0; i < *cap; i++)
	{
		if (arreglo[i] <= *menor)
		{
			*menor = arreglo[i];
			*pos = i;
		}
	}
}

int* EliminarPos(int *arreglo, int *cap, int *pos)
{
	int *aux = new int[*cap - 1];
	int j = 0;
	
	for (int i = 0; i < *cap; i++)
	{
		if (i != *pos)
		{
			aux[j] = arreglo[i];
			j++;
		}
	}
	*cap -= 1;
	return aux;
}

void CalcularPromedio(int *arreglo, int *cap, float *promedio)
{
	*promedio = 0;

	for (int i = 0; i < *cap; i++)
	{
		*promedio = *promedio + arreglo[i];
		// ... es lo mismo que:
		//*promedio += arreglo[i];
	}
	*promedio = *promedio / *cap;
	// ... lo mismo que:
	//*promedio /= *cap;
}

void Imprimir(int *arreglo, int *cap, float *promedio, int *menor)
{
	cout << endl << endl;
	cout << "Notas que se consideran en el promedio: ";
	for (int i = 0; i < *cap; i++)
	{
		cout << arreglo[i] << ' ';
	}
	cout << endl << "Promedio: " << *promedio << endl;
	cout << "Nota no considerada en el promedio: " << *menor;
}

int main()
{
	int *arreglo, *cap, *pos, *menor;
	float *promedio;
	cap = new int; *cap = 6;
	arreglo = new int[*cap];
	pos = new int;
	menor = new int; *menor = 20;
	promedio = new float;

	Ingreso(arreglo, cap);
	HallarMenorElemento(arreglo, cap, pos, menor);
	arreglo = EliminarPos(arreglo, cap, pos);
	CalcularPromedio(arreglo, cap, promedio);
	Imprimir(arreglo, cap, promedio, menor);

	_getch();
	return 0;
}