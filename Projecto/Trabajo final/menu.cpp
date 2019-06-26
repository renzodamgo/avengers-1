#include "Dataframe.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;

void menu() {
	cout << "(1) Cargar archivo" << endl
		<< "(2) Guardar archivo" << endl
		<< "(3) Listar archivo" << endl
		<< "(4) Crear DataFrame" << endl
		<< "(5) Mostrar DataFframe" << endl
		<< "(0) Salir" << endl;
}
void cargarDF(vector<Dataframe*>& dfs) {
	string name;
	int ncol;
	cout << "Nombre del archivo: ";
	cin >> name;
	cout << "Numero de columnas: ";
	cin >> ncol;
	Dataframe* dat = new Dataframe();
	dat->cargarArchivo(name, ncol);
	dfs.push_back(dat);
	dfs[1]->mostrarcolumnas();
}

void guardarDF(vector<Dataframe*>& dfs) {
	int i;
	string name;
	do {
		cout << "Seleccionar un DF [del 1 al " << dfs.size() << "]";
		cin >> i;
		--i;
	} while (i < 0 || i >= dfs.size());
	cout << "Nombre del archivo: ";
	cin >> name;
	dfs[i]->guardarDataframe(name);

	// TODO Guardar Dataframe en archivo
}


/*
void listarDFs(vector<DF*>& dfs) {
	int i = 0;
	for (auto df : dfs) {
		cout << ++i << "]" << endl; // Todo imprimir alguna otra inf del DF
	}
}

DF* seleccionar(DF* df) {
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
		return df.seleccionar(cols);
	}
	return nullptr;
}
DF* filtrar(DF* df) { return nullptr; }
DF* ordenar(DF* df) { return nullptr; }

void crearDF(vector<DF*>& dfs) {
	int i;
	string name;
	do {
		cout << "Seleecione un DF [del 1 al " << dfs.size() << "] ";
		cin >> i;
		--i;
	} while (i < 0 || i >= dfs.size());

	char op;
	do {
		cout << "[1] Seleccionar" << endl
			<< "[2] Filtrar" << endl
			<< "[3] Ordenar" << endl
			<< "[4] Cancelar" << endl
			<< "[0] Ingrese una opcion [0...3]" << endl;
		cin >> op;
		DF* nuevo;
		switch (op) {
		case '1':
			nuevo = seleccionar(dfs[i]);
			break;
		case '2':
			nuevo = filtrar(dfs[i]);
			break;
		case '3':
			nuevo = ordenar(dfs[i]);
			break;
		}
		if (nuevo != nullptr) {
			dfs.push_back(nuevo);
		}
	} while (op != '0');
}

void mostrarDF(vector<DF*>& dfs) {}
*/
int main() {
	char op;
	vector<Dataframe*> dfs;
	do {
		menu();
		cin >> op;
		switch (op) {
		case '1':
			cargarDF(dfs);
			break;
		case '2':
			guardarDF(dfs);
			break;
		case '3':
			cout << "Bye Bye" << endl;
			break;
		case '4':
			cout << "Bye Bye" << endl;
			break;
		}

	} while (op != '0');
	return 0;
};