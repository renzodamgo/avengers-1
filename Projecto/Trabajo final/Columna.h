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

public:
	Columna(bool numero = false) : numero(numero) {};
	~Columna();
	void inputData(string datadelCSV) { data.push_back(datadelCSV); }
	void showcol() {
		for (auto dat : data) {
			cout << dat << endl;
		}
		cout << "fin";
	}
};
