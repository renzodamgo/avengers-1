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
	vector<int> vfila;

public:
	Columna(bool numero = false, int filas = 0) : numero(numero), filas(filas) {};
	~Columna() {};

	void inputData(string datadelCSV) {
		data.push_back(datadelCSV);			
	}
	void showcol() {
		for (auto dat : data) {
			cout << dat << endl;
		}
	}
	string getData(int idx){
		return data[idx];
	}

	vector<int> Ordenar()
	{	
		vector<string> datatmp = data;
		quicksort(datatmp, datatmp[0], datatmp[datatmp.size() - 1]);
		for (int i=0; i < datatmp.size() ; i++) {
			for (int j=0; j < data.size() ; j++) {
				if (datatmp[i] == data[j]) {
					vfila.push_back(j);
				}
			}
		}
		for (auto vf : vfila) {
			cout << vf <<" " ;
		}
		
		//data = datatmp;
		
		return vfila;
	}
	void quicksort(vector<string>& names, string min, string max) {
		vector<string> tempData;
		int temp = 0, i = 0;
		string lowMin = max,
			lowMax = min,
			highMin = max,
			highMax = min,
			pivot;
		vector<string>  below, above;
		if (min != max) {
			pivot = (max[i] + min[i]) / 2;
			while (temp < names.size()) {
				if (names[temp] <= pivot) {
					if (lowMax.compare(names[temp]) < 0) {
						lowMax = names[temp];
					}
					if (lowMin.compare(names[temp]) > 0) {
						lowMin = names[temp];
					}
					below.push_back(names[temp]);
				}
				else {
					if (highMax.compare(names[temp]) < 0) {
						highMax = names[temp];
					}
					if (highMin.compare(names[temp]) > 0) {
						highMin = names[temp];
					}
					above.push_back(names[temp]);
				}
				temp++;
			}
			if ((below.size() > 1) && (names.size() != below.size())) {
				quicksort(below, lowMin, lowMax);
			}
			if ((above.size() > 1) && (names.size() != above.size())) {
				quicksort(above, highMin, highMax);
			}
			for (size_t i = 0; i < below.size(); i++) {
				names[i] = below[i];
			}
			for (size_t i = below.size(); i < names.size(); i++) {
				names[i] = above[i - below.size()];
			}

		}

	}

	bool front(int dx, char C){
		if (data[dx].front() == C)
			return true;
		else
			return false;
	}
	bool back(int dx, char C) {
		if (data[dx].back() == C)
			return true;
		else
			return false;

	}
	bool same_string(string str, int dx) {
		if (data[dx] == str)
			return true;
		else
			return false;
	}
	bool getMayor(string str, int dx) {
		if (data[dx].compare(str)> 0)
			return true;
		else
			return false;
	}
	bool getMenor(string str, int dx) {
		if (data[dx].compare(str) < 0)
			return true;
		else
			return false;
	}
	bool getIn(string str, int dx) {
		if (data[dx].find(str) != string::npos)
			return true;
		else
			return false;
	}
	bool getnoIn(string str, int dx) {
		if (data[dx].find(str) != string::npos)
			return false;
		else
			return true;
	}
};
