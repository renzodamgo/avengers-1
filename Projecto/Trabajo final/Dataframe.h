#pragma once
#include "Fila.h"
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include "Columna.h"
#include "AVL.h"

using namespace std;
class Dataframe {
private:
	map<string, AVLTree<Fila*,string>*> tree;
	map<string, Columna*> colmap;
	vector<Fila*> filas;
	vector<string> colnames;
	int ncol;

public:
	Dataframe() {};
	~Dataframe() {};
	bool colesnum(string colname)
	{
		colmap[colname]->isNum();
		return colmap[colname]->getNum();
	}


	vector<Fila*> getFilas() {
		return filas;
	};
	map<string, Columna*> getColmap() {
		return colmap;
	};


	void copy(map<string, Columna*> col, vector<Fila*> fil) {
		colmap = col;
		filas = fil;
	}
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
	void mostrarcolumna(string nombreCol) { 
		if (colmap[nombreCol] != nullptr)  
			colmap[nombreCol]->showcol();
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

	void InOrder(string colname) {
		vector<Fila*> filastemp;
		auto prt = [&](Fila* a) {filastemp.push_back(new Fila(a->getIdx())); };
	
		tree[colname]->InOrder(prt);
		filas = filastemp;
		
	}
	void index(string colname) {
		AVLTree <Fila*, string >* t = new AVLTree<Fila*, string>([=](Fila* r) {return colmap[colname]->getData(r->getIdx());
	});
		for (auto row : this->filas) {
			t->Add(row);
		}
		tree[colname] = t;
	}
	void seleccionar(vector<string> coln) {
		map<string, Columna*> colmaptemp;
		for (auto col : colmap) {
			for (auto colname : coln) {
				if (col.first == colname) {
					colmaptemp.insert(pair<string, Columna*>(col.first, col.second));
				}
			}
			
		}
		colmap = colmaptemp;
		
	};

	void Ordenar(string colname) {
		vector<int> filastmp;
		filastmp = colmap[colname]->Ordenar();
		
		for (int j = 0; j < filas.size() ; j++) {
			filas[j]->setIdx(filastmp[j]);

		};
	}
	
	void Filtrar_Mayor_num(string nCol, int n) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->getMayornum(n, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_Menor_num(string nCol, int C) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->getMenornum(C, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_Igual_num(string nCol, int C) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->getIgualnum(C, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_Mayor(string nCol, string C) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->getMayor(C, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_Menor(string nCol, string C) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->getMenor(C, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_Igual(string nCol, string C) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->same_string(C, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_Empieza(string nCol, char C) {
		vector<Fila*> filtemp;
		vector<string> temp;

		for (auto fil : filas) {
			if (colmap[nCol]->front(fil->getIdx(), C) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_Termino(string nCol, char C) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->back(fil->getIdx(), C) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_In(string nCol, string C) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->getIn(C, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtrar_NoIn(string nCol, string C) {
		vector<string> temp;
		vector<Fila*> filtemp;
		for (auto fil : filas) {
			if (colmap[nCol]->getnoIn(C, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	//congratulation!!!! confie
};