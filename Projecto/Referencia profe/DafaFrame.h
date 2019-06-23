#include "Filas.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <conio.h>
#include <functional>
#include "Arbolito.h"

using namespace std;

class DF {
	colmap columnas;
	vector <Filas*> filas;

public:
	bool compare(string nc, string op, string val, Filas* r) {

		if (op == ">")
			return r->getData(nc) > val;
		else if (op == "<")
			return r->getData(nc) < val;
		else if (op == "contains")
			return r->getData(nc).find(val);



	}


	DF* seleccion(vector <string> colNames) {
		colmap* nCols = new colmap();
		for (string cn : colNames) {
			nCols[cn] = columnas[cn];
		}
		DF* nDF(nCols);
		nDF->filas = this->filas;
		return nDF;
	}
	DF* filtro(string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") {
		colmap* nCols = new colmap();
		*nCols = this->columnas;
		DF* nDF = new DF();
		for (auto r : this->filas) {
			if (compare(nc1, op1, val1, r) && compare(nc2, op2, val2, r))
			{
				nDF->filas.push_back(r);
			}

		}


	}

	void quicksort(int* array, int start, int end)
	{
		int pivot;

		if (start < end) {
			pivot = divide(array, start, end);

			// Ordeno la lista de los menores
			quicksort(array, start, pivot - 1);

			// Ordeno la lista de los mayores
			quicksort(array, pivot + 1, end);
		}
	}

	DF* sort(string colname) {
		colmap* nCols = new colmap();
		*nCols = this->columnas;
		DF* nDF = new DF(nCols);
		nDF->filas = this->filas;
		quicksort<Filas*, string>(nDF->filas, [=](Filas* r) {return r->getData(Colname); });
		return nDF;
	}


	void index(string colname) {
		AVLTree <Filas, string >* t = new AVLTree<filas*, string>([=](filas* r) {return r->getData(colname)});
		for (auto filas : this->filas) {
			t->Add(row);
		}
		tree[colname] = t;
	}





};

