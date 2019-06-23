#include "Columnas.h"}

typedef map<string, Col*> colmap;
class Filas
{
private:

	int idx;
	colmap* cols;

public:

	Filas(colmap* cols) : cols(cols) { }

	string getData(string name) {
		return(*cols)[name][idx];
	}
};