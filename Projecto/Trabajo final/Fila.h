#pragma once
class Fila
{
private:
	int idx;
public:
	Fila(int idx) :idx(idx) {};
	~Fila();
	int getIdx() { return idx; }
};

