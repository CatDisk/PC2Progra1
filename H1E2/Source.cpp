#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace System;

void Ingreso(int *arreglo, int *cap)
{
	cout << "Bienvenio al sistema de registro de" << endl;
	cout << " _____ _ _                      _____           " << endl;
	cout << "|   __|_| |_ ___ ___ ___ ___   |   __|_ _ _____ " << endl;
	cout << "|   __| |  _|   | -_|_ -|_ -|  |  |  | | |     |" << endl;
	cout << "|__|  |_|_| |_|_|___|___|___|  |_____|_  |_|_|_|" << endl;
	cout << "                                     |___|      " << endl << endl;

	for (int i = 0; i < *cap; i++)
	{
		cout << "Ingrese el peso del cliente No." << i + 1 << ": ";
		cin >> arreglo[i];
	}
}

int MayorElemento(int *arreglo, int *cap)
{
	int mayor = 0;

	for (int i = 0; i < *cap; i++)
	{
		if (arreglo[i] > mayor)
			mayor = arreglo[i];
	}
	return mayor;
}

void CalcularPromedio(int *arreglo, int *cap, float *promedio)
{
	for (int i = 0; i < *cap; i++)
	{
		*promedio += arreglo[i];
	}
	*promedio /= *cap;
}

void CalcularCategorias(int *arreglo, int *cap, int *delgados, int *medios, int *gruesos)
{
	for (int i = 0; i < *cap; i++)
	{
		if (arreglo[i] < 53)
			*delgados += 1;
		else if (arreglo[i] >= 53 && arreglo[i] <= 60)
			*medios += 1;
		else
			*gruesos += 1;
		/*
		===NOTA===

		if (bla)
		{}
		else if(bla bla)
		{}

		puede reemplazar:

		if(bla)
		{}
		else
		{
			if(bla bla)
			{}
		}
		*/
	}
}

void Imprimir(int *arreglo, int *cap, float *promedio, int *delgados, int *medios, int *gruesos)
{
	cout << endl;
	cout << "El peso promedio es de " << *promedio << "kg." << endl;
	cout << "El cliente con mayor peso, pesa " << MayorElemento(arreglo, cap) << "kg." << endl;
	cout << "La cantidad de clientes de contextura delgada (peso < 53) es: " << *delgados << endl;
	cout << "La cantidad de clientes de contextura media (52 < peso < 61) es: " << *medios << endl;
	cout << "La cantidad de clientes de contextura gruesa (peso > 60) es: " << *gruesos;
}

int main()
{
	int *arreglo, *cap, *delgados, *medios, *gruesos;
	float *promedio;
	cap = new int; *cap = 10;
	delgados = new int; *delgados = 0;
	medios = new int; *medios = 0;
	gruesos = new int; *gruesos = 0;
	promedio = new float; *promedio = 0;
	arreglo = new int[*cap];
	
	Ingreso(arreglo, cap);
	CalcularCategorias(arreglo, cap, delgados, medios, gruesos);
	CalcularPromedio(arreglo, cap, promedio);
	Imprimir(arreglo, cap, promedio, delgados, medios, gruesos);

	_getch();
	delete[] arreglo;
	delete cap, delgados, medios, gruesos, promedio;
	return 0;
}
