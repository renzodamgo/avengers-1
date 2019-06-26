#pragma once
#include "Fila.h"
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
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
	void mostrarTodo() {
		for (auto col : colmap) {
			cout << col.first << "\t\t";
		}
		cout << endl;
		for (auto fil : filas) {
			for (auto col : colmap) {
				cout << col.second->getData(fil->getIdx()) << "\t\t";
			}
			cout << endl;
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
		for (auto col : colmap) {
			data << col.first << ",";
		}
		data << endl;
		for (auto fil : filas) {
			for (auto col : colmap) {
				data << col.second->getData(fil->getIdx()) << ",";
			}
			data << endl;
		}
		
	}

	
	void Filtrar_Empieza(string nCol, char C) {

		vector<string> temp;

		for (auto fil : filas)
			if(colmap[nCol]->fron(fil->getIdx(), C) == true)
			{ 
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
			}
	}

	void Filtrar_Termino(string nCol, char C) {
		vector<string> temp;
		for (auto fil : filas)
			if (colmap[nCol]->back(fil->getIdx(), C) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
			}
	}






};