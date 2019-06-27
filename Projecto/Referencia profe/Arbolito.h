

#pragma once

#include <iostream>
#include <conio.h>
#include <functional>

using namespace std;

class Tree {
private:
	struct Node {
		float elem;
		Node* left;
		Node* right;

		Node(float elem, Node* left = nullptr, Node* right = nullptr) : elem(elem), left(left), right(right) {}
	};
	Node* root; //raiz
	int length;
	void destroy(Node* node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
	void add(Node*& node, float elem) {
		if (node == nullptr)
			node = new Node(elem);
		else if (elem < node->elem)
			add(node->left, elem);
		else
			add(node->right, elem);
	}
	void InOrder(Node* node, function<void(float)> Bob_DoSomething) {
		if (node != nullptr) {
			InOrder(node->left, Bob_DoSomething);
			Bob_DoSomething(node->elem);
			InOrder(node->right, Bob_DoSomething);
		}
	}
	Node*& max(Node*& node) {
		if (node->right == nullptr)
			return node;
		return max(node->right);
	}
	Node*& min(Node*& node) {
		if (node->left == nullptr)
			return node;
		return min(node->left);
	}
public:
	Tree() :root(nullptr), length(0) {}
	~Tree() { destroy(root); }
	int Length() { return length; }
	void Add(float elem) {
		add(root, elem);
		++length;
	}
	void InOrder(function<void(float)> Bob_DoSomething) {
		InOrder(root, Bob_DoSomething);
	}

	float Max() {
		if (root != nullptr) {
			return max(root)->elem;
		}
		return -.1;
	}
	float Min() {
		if (root != nullptr) {
			return min(root)->elem;
		}
		return -.1;
	}
	//Cuando queramos eliminar, buscamos el maximo hijo de la izquierda o el minimo de la derecha

	void Remove(float elem) {
		Node* parent;
		Node* aux = root;
		bool left;
		while (aux != nullptr && elem != aux->elem) {
			parent = aux;
			if (elem < aux->elem) {
				left = true;
				aux = aux->left;
			}
			else {
				left = false;
				aux = aux->right;
			}
		}
		if (aux == nullptr) return;

		Node* aux2;
		if (aux->left != nullptr) {
			Node*& cand = max(aux->left);
			aux2 = cand;
			cand = cand->right;
		}
		else if (aux->right != nullptr) {
			Node*& cand = min(aux->right);
			aux2 = cand;
			cand = cand->right;
		}
		else if (aux = root) {
			delete root;
			root = nullptr;
			return;
		}
		else {
			if (left) {
				delete parent->left;
				parent->left = nullptr;
			}
			else {
				delete parent->right;
				parent->right = nullptr;
			}
		}
	};
};

 int main(){
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