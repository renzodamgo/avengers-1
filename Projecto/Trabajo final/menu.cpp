#include "Dataframe.h"
#include <string>
#include <vector>
#include <iostream>
int main() {
	/* string archivo;
	int ncol;
	cout << "Numero de columnas: ";
	cin >> ncol;
	cout << "Nombre del archivo: ";
	cin >> archivo; */
	Dataframe* dat = new Dataframe();
	dat->cargarArchivo("data.csv", 4);
	string nombredecol;
	cin >> nombredecol;
	dat->mostrarcolumna(nombredecol);
	system("pause");
}