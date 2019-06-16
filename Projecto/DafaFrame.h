#pragma once
#include "Filas.h"
#include "Columnas.h"
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
class Dataframe {
private:
	vector<Filas*>* filas;
	vector<Columnas*>* columna;
	//  T dato;


public:
	void CargarDF();
	void ImprimirDF();
	void setVal();

	//void DatosColumnas(vector<Filas>& filas);


};
