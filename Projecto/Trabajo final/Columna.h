#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Columna {
private:
	string nombre;
	bool numero;
	vector<string> data;
	int filas;

public:
	Columna(bool numero = false, int filas = 0) : numero(numero),filas(filas) {};
	~Columna();
	void inputData(string datadelCSV) {
		data.push_back(datadelCSV);
		filas++;
	}
	void showcol() {
		for (auto dat : data) {
			cout << dat << endl;
		}
		cout << "nro de filas: ";
		cout << filas;
	}
	string getData(int idx){
		return data[idx];
	}
};
