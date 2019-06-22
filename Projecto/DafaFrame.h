#include <Filas.h>

using namespace std;

struct Columna {};
struct Filas {};

class DF {
	colmap columnas;
	vector < Filas*> filas;

public:


	DF* seleccion(vector <string> colNames) {
		colmap* nCols = new colmap();
		for (auto cn = colNames) {
			nCols[cn] = columnas[cn];
		}
		DF* nDF(nCols);
		nDF->filas = this->filas;
		return nDf;
	}
	DF* filtro(string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") {
		colmap* nCols = new colmap();
		*nCols = this->columnas;
		DF* nDF = new Df(nCols);
		for (auto r : this->filas) {
			if (compare(nc1, op1, val1, r) && campare(nc2, op2, val2, r))
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
		DF* nDF = new nDF(nCols);
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

//void menu() {
//	cout << "(1) Cargar archivo" << endl
//		<< "(2) Guardar archivo" << endl
//		<< "(3) Listar archivo" << endl
//		<< "(4) Crear DataFrame" << endl
//		<< "(5) Mostrar DataFframe" << endl
//		<< "(0) Salir" << endl;
//}
//void cargarDF(vector<DF*>& dfs) {
//	string name;
//	cout << "Nombre del archivo";
//	cin.get();
//	getline(cin, name);
//	//TODO cargar arhivo!
//	//dfs.pushback(cargaDeArchivo(name));
//	//lere la data y retorna un DataFrame
//	dfs.push_back(new DF());
//}
//
//void guardarDF(vector<DF*>& dfs) {
//	int i;
//	string name;
//	do {
//		cout << "Seleccionar un DF [del 1 al " << dfs.size() << "]";
//		cin >> i; --i;
//	} while (i < 0 || i >= dfs.size());
//	cout << "Nombre del archivo: ";
//	cin.get();
//	getline(cin, name);
//	//TODO Guardar Dataframe en archivo
//}
//
//void listarDFs(vector<DF*>& dfs) {
//	int i = 0;
//	for (auto df : dfs) {
//		cout << ++i << "]" << endl; //Todo imprimir alguna otra inf del DF
//	}
//}
//
//DF* seleccionar(DF* df) {
//	vector<string> cols;
//	string col;
//	do {
//		cout << "Ingrese columna: ";
//		cin.get();
//		getline(cin, col);
//		if (col != "") {
//			cols.push_back(col);
//		}
//	} while (col != "");
//	if (cols.size() > 0) {
//		return df.seleccionar(cols);
//	}
//	return nullptr;
//}
//DF* filtrar(DF* df) { return nullptr; }
//DF* ordenar(DF* df) { return nullptr; }
//
//void crearDF(vector<DF*>& dfs) {
//	int i;
//	string name;
//	do {
//		cout << "Seleecione un DF [del 1 al " << dfs.size() << "] ";
//		cin >> i; --i;
//	} while (i < 0 || i >= dfs.size());
//
//	char op;
//	do {
//		cout << "[1] Seleccionar" << endl
//			<< "[2] Filtrar" << endl
//			<< "[3] Ordenar" << endl
//			<< "[4] Cancelar" << endl
//			<< "[0] Ingrese una opcion [0...3]" << endl;
//		cin >> op;
//		DF* nuevo;
//		switch (op) {
//		case '1': nuevo = seleccionar(dfs[i]); break;
//		case '2': nuevo = filtrar(dfs[i]); break;
//		case '3': nuevo = ordenar(dfs[i]); break;
//
//		}
//		if (nuevo != nullptr)
//		{
//			dfs.push_back(nuevo);
//		}
//	} while (op != '0');
//}
//
//void mostrarDF(vector<DF*>& dfs) {}
//
//
//int main() {
//	char op;
//	vector <DF*> dfs;
//	do {
//		menu();
//		cin >> op;
//		switch (op) {
//		case '0': cout << "Bye Bye" << endl; break;
//		case '1': cout << "Bye Bye" << endl; break;
//		case '2': cout << "Bye Bye" << endl; break;
//		case '3': cout << "Bye Bye" << endl; break;
//
//		}
//
//	} while (op != '0');
//	return 0;
//}