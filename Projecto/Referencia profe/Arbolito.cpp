#include "Arbolito.h"

void main() {
	int n;
	float e;
	Tree* t = new Tree();
	auto prt = [](float a) {cout << a << " "; };
	cout << "Ingrese la cantidad de datos que desea leer ordenadamente: ";
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> e;
		t->Add(e);
	}
	t->InOrder(prt);

	_getch();
	delete t;
}