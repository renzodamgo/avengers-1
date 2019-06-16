#pragma once
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void pausa()
{
	cout << "Pulsa una tecla para continuar...";
	_getch();
}

void Menu() {
	bool bandera = false;
	char tecla;

	do
	{
		system("cls");
		cin.clear();
		cout << "DataFrames" << endl;
		cout << "-----------" << endl << endl;
		cout << "Elije una opcion: " << endl;
		cout << "\t1 .- Importacion de datos" << endl;
		cout << "\t2 .- Indexado de datos por columnas" << endl;
		cout << "\t3 .- Seleccion de datos por columnas" << endl;
		cout << "\t4 .- Filtrado de datos por columnas" << endl;
		cout << "\t5 .- Ordenamiento de datos por columnas" << endl;
		cout << "\t6 .- Exportacion de datos a archivos planos con diferente formato" << endl << endl;


		cin >> tecla;

		switch (tecla)
		{
		case '1':
			system("cls");
			cout << "Has elejido Importacion de datos.\n";
			pausa();
			break;

		case '2':
			system("cls");
			cout << "Has elejido Indexado de datos por columnas.\n";
			pausa();
			break;

		case '3':
			system("cls");
			cout << "Has elejido Seleccion de datos por columnas.\n";
			pausa();
			break;

		case '4':
			system("cls");
			cout << "Has elejido Filtrado de datos por columnas.\n";
			pausa();
			break;

		case '5':
			system("cls");
			cout << "Has elejido Ordenamiento de datos por columnas.\n";
			pausa();
			break;


		case '6':
			system("cls");
			cout << "Has elejido Exportacion de datos a archivos planos con diferente formato.\n";
			pausa();
			break;
		
		case '0':
			bandera = true;
			//salida
			break;

		default:
			system("cls");
			cout << "Opcion no valida.\a\n";
			pausa();
			break;
		}
	} while (bandera != true);
}
