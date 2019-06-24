#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Columna {
private:
	string nombre;
	bool numero;
	vector<string> data;
	int filas;
	map<string, int> dat;

public:
	Columna(bool numero = false, int filas = 0) : numero(numero),filas(filas) {};
	~Columna() {};
	void inputData(string datadelCSV) {
		data.push_back(datadelCSV);
		filas++;
		dat.insert(pair<string, int>(datadelCSV, 1));
	}
	void showcol() {
		for (auto dat : data) {
			cout << dat << endl;
		}
	}
	string getData(int idx){
		return data[idx];
	}
};
