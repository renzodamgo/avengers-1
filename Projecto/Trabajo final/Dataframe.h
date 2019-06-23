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

public:
	Dataframe() {};
	~Dataframe();
	void cargarArchivo(string nombre, int ncol) {
		vector<string> colnames;
		ifstream data;
		data.open(nombre);
		string line;
		int i = 0;
		getline(data, line);
		stringstream ss(line);
		for (int j = 0; j < ncol; ++j) {
			getline(ss, line, ',');
			colmap.insert(pair<string, Columna*>(line, new Columna()));
			colnames.push_back(line);
		};

		while (getline(data, line)) {
			stringstream ss(line);
			for (int j = 0; j < ncol; ++j) {
				getline(ss, line, ',');
				/* cout << line << " \\ "; */
				colmap[colnames[j]]->inputData(line);
			}
		}
	}
	/*void mostrarcolumnas() {
		map<string, Columna*>::iterator itr;
		for (itr = colmap.begin(); itr != colmap.end(); ++itr) {
			cout << itr->first << '\t';
		}
	}*/
	void mostrarcolumna(string nombreCol) { colmap[nombreCol]->showcol(); }
};