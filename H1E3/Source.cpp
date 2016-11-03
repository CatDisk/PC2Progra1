#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
using namespace System;

void ImprimirMenu(int *opt)
{
	Console::Clear();
	cout << " 1 | Imprimir Arreglo" << endl;
	cout << " 2 | Mostrar valor y posicion de la menor edad" << endl;
	cout << " 3 | Mostrar el numero de personas entre 30 y 50" << endl;
	cout << " 4 | Buscar edad" << endl;
	cout << " 5 | Salir del programa" << endl << endl;
	do
	{
		cout << "     Ingrese su opcion: ";
		cin >> *opt;
	} while (*opt < 1 || *opt > 5);
}

int* GenerarArreglo(int *cap)
{
	int *aux = new int[*cap];
	srand(time_t());
	for (int i = 0; i < *cap; i++)
	{
		aux[i] = rand() % 101;
	}
	return aux;
}

void IngresoCapacidad(int *cap)
{
	do
	{
		cout << "Ingrese la cantidad de elementos del arreglo a generar (max: 100): ";
		cin >> *cap;
	} while (*cap < 1 || *cap > 100);
}

void ImprimirArreglo(int *arreglo, int *cap)
{
	for (int i = 0; i < *cap; i++)
	{
		cout << "Arreglo[" << i << "]: " << arreglo[i] << endl;
	}
}

void EncontrarMenor(int *arreglo, int *cap)
{
	int pos;
	int menor = 100;
	
	for (int i = 0; i < *cap; i++)
	{
		if (menor > arreglo[i])
		{
			pos = i;
			menor = arreglo[i];
		}
	}
	cout << "La menor edad es " << menor << " en la posicion " << pos << " del arreglo.";
}

void Calcularentre30y50(int *arreglo, int *cap)
{
	int counter = 0;

	for (int i = 0; i < *cap; i++)
	{
		if (arreglo[i] > 30 && arreglo[i] < 50)
			counter += 1;
	}
	cout << counter << " personas se encuentran entre los 30 y 50.";
}

void BuscarEdad(int *arreglo, int *cap)
{
	int edad;
	int i = 0;
	bool encontrado = false;
	do
	{
		cout << "Ingrese la edad que quiere buscar: ";
		cin >> edad;
	} while (edad < 0 && edad > 100);
	
	while (!encontrado || i == *cap - 1)
	{
		if (arreglo[i] == edad)
			encontrado = true;
		i++;
	}
	cout << boolalpha << endl;
	cout << "La edad ingresada se encuentra en el arreglo: " << encontrado;
}

int main()
{
	int *cap, *arreglo, *opt;
	cap = new int;
	opt = new int;

	IngresoCapacidad(cap);
	arreglo = GenerarArreglo(cap);

	do
	{
		ImprimirMenu(opt);
		cout << endl;
		switch (*opt)
		{
		case 1:
			ImprimirArreglo(arreglo, cap);
			break;
		case 2:
			EncontrarMenor(arreglo, cap);
			break;
		case 3:
			Calcularentre30y50(arreglo, cap);
			break;
		case 4:
			BuscarEdad(arreglo, cap);
			break;
		case 5:
			cout << "Press the any key to exit.";
			break;
		}
		_getch();
	} while (*opt != 5);
	delete[] arreglo;
	delete cap, opt;
	return 0;
}