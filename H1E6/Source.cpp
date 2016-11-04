#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace System;

void Ingreso(int *cap)
{
	cout << "Bienvienido al programa de prueba de ENCUESTAFA S.A." << endl;
	
	do
	{
		cout << "Por favor ingrese el numero de montos a generar (max. 200): ";
		cin >> *cap;
	} while (*cap < 1 || *cap > 200);
}

int GenerarMontoAleatorio()
{
	return (rand() % 476) + 25;
}

int* GenerarArreglo(int *cap)
{
	int *aux = new int[*cap];

	for (int i = 0; i < *cap; i++)
	{
		aux[i] = GenerarMontoAleatorio();
	}
	return aux;
}

int* GenerarOrdenarArreglo(int *arreglo, int *cap)
{
	int *aux = arreglo;

	int buffer;
	int cambio;

	do
	{
		cambio = 0;
		for (int i = 1; i < *cap; i++)
		{
			if (aux[i - 1] > aux[i])
			{
				buffer = aux[i - 1];
				aux[i - 1] = aux[i];
				aux[i] = buffer;
				cambio++;
			}
		}
	} while (cambio != 0);
	return aux;
}

void ImprimirArreglo(int *arreglo, int *cap)
{
		cout << "Clientes  |  Monto" << endl;
		cout << "----------+-------" << endl;
	for (int i = 0; i < *cap; i++)
	{
		if (i < 10)
			cout << "  ";
		else if (i < 100)
			cout << " ";
		cout << i + 1 << "       |  " << arreglo[i] << endl;
	}
}

int main()
{
	int *arreglo, *arreglo_ordenado, *cap;
	cap = new int;
	srand(time_t());
	Ingreso(cap);
	arreglo = GenerarArreglo(cap);
	ImprimirArreglo(arreglo, cap);
	arreglo_ordenado = GenerarOrdenarArreglo(arreglo, cap);
	ImprimirArreglo(arreglo_ordenado, cap);
	_getch();

	return 0;
}