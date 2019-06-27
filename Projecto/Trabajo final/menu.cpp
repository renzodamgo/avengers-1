#include "Dataframe.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void menu() {
	cout << "(1) Importar Datos" << endl
		<< "(2) Indexado por Columnas" << endl		
		<< "(3) Exportar Datos" << endl
		<< "(4) Crear DataFrame" << endl
		<< "(5) Mostrar DataFrame" << endl
		<< "(0) Salir" << endl
		<< "Elige una opcion: " ;
}

void Importar_Datos(vector<Dataframe*>& dfs) {
	string name;
	int ncol;
	cout << "Nombre del archivo: ";
	cin >> name;
	cout << "Numero de columnas: ";
	cin >> ncol;
	Dataframe* dat = new Dataframe();
	dat->cargarArchivo(name, ncol);
	dfs.push_back(dat);	
}

void Seleccionar(Dataframe*& df) {
	int i;
	string col;
	vector<string>cols;
	int n;
	
	cout << "Cuantas columna desea seleccionar: ";
	cin >> n;
	for (int j = 0; j < n; j++) {
		cout << "Ingrese columna: ";
		cin >> col;
		cols.push_back(col);
	}
	for (auto c : cols) {
		cout << c << "";
	}
	df->seleccionar(cols);
	
}
void Exportar_Datos(vector<Dataframe*>& dfs) {
	int i;
	string name;
	do {
		cout << "Seleccionar un DF [del 1 al " << dfs.size() << "]: ";
		cin >> i;
		--i;
	} while (i < 0 || i >= dfs.size());
	cout << "Nombre del archivo: ";
	cin >> name;
	dfs[i]->guardarDataframe(name);
}
void Indexado_Por_Columnas(vector<Dataframe*>& dfs) {
	int i;
	string name;
	do {
		cout << "Seleccionar un DF [del 1 al " << dfs.size() << "]: ";
		cin >> i;
		--i;
	} while (i < 0 || i >= dfs.size());
	cout << "Nombre de columna a indexar: ";
	cin >> name;
	dfs[i]->index(name);
	dfs[i]->InOrder(name);
}
void Mostrar_DF(vector<Dataframe*>& dfs) {
	int i;
	string name;
	do {
		cout << "Seleccionar un DF [del 1 al " << dfs.size() << "]: ";
		cin >> i;
		--i;
	} while (i < 0 || i >= dfs.size());
	dfs[i]->mostrarTodo();
}
void Filtrar(Dataframe*& data) {
	string nombre, palabra;	
	char c;
	char op;
	cout << "[1] mayor:" << endl
		<< "[2] menor: " << endl
		<< "[3] igual a: " << endl
		<< "[4] inicia con: " << endl
		<< "[5] finaliza con: " << endl
		<< "[6] incluido en: " << endl
		<< "[7] no incluido en: " << endl
		<< "Ingrese un numero [1 ... 7]: ";
	
	cin >> op;
	cout << "Elegir columna: ";
	cin.get();
	getline(cin, nombre);	
	switch (op) {

	case '1':
		cout << "Elegir palabra: ";
		cin >> palabra;
		data->Filtrar_Mayor(nombre, palabra);
		break;
	case '2':
		cout << "Elegir palabra: ";
		cin >> palabra;
		data->Filtrar_Menor(nombre, palabra);
	case '3':		
		cout << "Elegir palabra: ";
		cin >> palabra;
		data->Filtrar_Igual(nombre, palabra);		
		break;
	case '4':		
		cout << "Elegir el caracter: ";
		cin >> c;
		data->Filtrar_Empieza(nombre, c);
		break;
	case '5':		
		cout << "Elegir el caracter: ";
		cin >> c;
		data->Filtrar_Termino(nombre, c);
		break;
	case '6':
		
		break;
	case '7':
		
		break;
	}
}
void ordenar(Dataframe *& data) { 

}
void Crear_DF(vector<Dataframe*>& dfs) {
	int i;
	string name;
	do {
		cout << "Seleccione un DF [del 1 al " << dfs.size() << "]: ";
		cin >> i;
		--i;
	} while (i < 0 || i >= dfs.size());

	char op;
	string nombre;
	char c;
	do {
		cout << "[1] Seleccionar" << endl
			<< "[2] Filtrar" << endl
			<< "[3] Ordenar" << endl
			<< "[0] Salir" << endl
			<< "Ingrese una opcion [0...3]: ";
		cin >> op;

		Dataframe* nuevo = dfs[i];
		switch (op) {
		case '1':
			Seleccionar(nuevo);
			break;
		case '2':
			Filtrar(nuevo);
			break;
		case '3':
			//nuevo = ordenar(dfs[i]);
			break;
		}
		if (nuevo != nullptr)
			if (op != '0') dfs.push_back(nuevo);
	} while (op != '0');
}

int main() {
	char op;
	vector<Dataframe*> dfs;
	do {
		menu();
		cin >> op;
		switch (op) {
		case '1':
			Importar_Datos(dfs);
			break;
		case '2':
			Indexado_Por_Columnas(dfs);
			break;
		case '3':
			Exportar_Datos(dfs);
			break;
		case '4':
			Crear_DF(dfs);
			break;
		case '5':
			Mostrar_DF(dfs);
			break;
		}
	} while (op != '0');
	return 0;
};