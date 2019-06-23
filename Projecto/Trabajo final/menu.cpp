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
	dat->cargarArchivo("annual-enterprise-survey-2017-financial-year-provisional-size-bands-csv (1).csv", 7);
	string nombredecol;
	//cin >> nombredecol;
	//dat->mostrarcolumnas();
	dat->mostrarcolumna("industry_name_ANZSIC");
	system("pause");
}