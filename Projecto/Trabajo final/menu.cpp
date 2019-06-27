#include "Dataframe.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void menu() {
	cout << "(1) Importar Datos" << endl
		<< "(2) Indexado por Columnas" << endl
		<< "(3) Seleccion por columnas" << endl
		<< "(4) Exportar Datos" << endl
		<< "(5) Crear DataFrame" << endl
		<< "(6) Mostrar DataFrame" << endl
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

/*
void listarDFs(vector<DF*>& dfs) {
	int i = 0;
	for (auto df : dfs) {
		cout << ++i << "]" << endl; // Todo imprimir alguna otra inf del DF
	}
}
*/

Dataframe* seleccionar(Dataframe* df) {
	vector<string> cols;
	string col;
	do {
		cout << "Ingrese columna: ";
		cin.get();
		getline(cin, col);
		if (col != "") {
			cols.push_back(col);
		}
	} while (col != "");
	if (cols.size() > 0) {
	//q	df->seleccionar(cols);
		return df;
	}
	return nullptr;
}

void filtrar(Dataframe*& data) {
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
//DF* ordenar(DF* df) { return nullptr; }

void Crear_DF(vector<Dataframe*>& dfs) {
	int i;
	string name;
	do {
		cout << "Seleecione un DF [del 1 al " << dfs.size() << "]: ";
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
			//nuevo.seleccionar(dfs[i]);
			break;
		case '2':			
			filtrar(nuevo);			
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
			//Indexado_Por_Columnas(dfs);
			break;
		case '3':
			//Seleccion_Por_Columnas(dfs);
			break;
		case '4':
			Exportar_Datos(dfs);
			break;
		case '5':
			Crear_DF(dfs);
			break;
		case '6':
			Mostrar_DF(dfs);
			break;
		}
	} while (op != '0');
	return 0;
};