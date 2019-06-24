#pragma once
#include "Fila.h"
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "Columna.h"
using namespace std;
class Dataframe {
private:
	map<string, Columna*> colmap;
	vector<Fila*> filas;
	vector<string> colnames;
	int ncol;

public:
	Dataframe() {};
	~Dataframe();
	void cargarArchivo(string nombre, int ncol) {
		this->ncol = ncol;
		ifstream data;
		data.open(nombre);
		string line;
		getline(data, line);
		stringstream ss(line);
		for (int j = 0; j < ncol; ++j) {
			getline(ss, line, ',');
			colmap.insert(pair<string, Columna*>(line, new Columna()));
			colnames.push_back(line);
		};
		int i=0;
		while (getline(data, line)) {
			filas.push_back(new Fila(i));
			stringstream ss(line);
			for (int j = 0; j < ncol; ++j) {
				getline(ss, line, ',');
				/* cout << line << " \\ "; */
				colmap[colnames[j]]->inputData(line);
			}
			i++;
		}
	}
	void mostrarcolumnas() {
		map<string, Columna*>::iterator itr;
		for (itr = colmap.begin(); itr != colmap.end(); ++itr) {
			cout << itr->first << '\t';
		}
	}
	void mostrarcolumna(string nombreCol) { if (colmap[nombreCol] != nullptr)colmap[nombreCol]->showcol();
	}
	void guardarDataframe(string nombre) {
		ofstream data;
		data.open(nombre);
		for (auto fil : filas) {
			for (auto col : colmap) {
				data << col.second->getData(fil->getIdx()) << ",";
			}
			data << endl;
		}
		
	}
};