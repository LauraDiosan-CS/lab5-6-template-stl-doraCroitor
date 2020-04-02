#pragma once
#include <vector>
using namespace std;

template<class T>
class Repo {
private:
	vector<T> elemente;
	
public:
	// Adauga o prajitura
	void addElem(T e) {
		this->elemente.push_back(e);
	}

	// Toate elementele
	vector<T> getAll() {
		return this->elemente;
	}

	// Lungimea
	int getSize() {
		return this->elemente.size();
	};

	Repo() {};
	~Repo() {
		this->elemente.clear();
	}

	// sterge
	void stergere(T c) {
		typename vector<T>::iterator it;
		it= find(this->elemente.begin(), this->elemente.end(), c);
		if (!(it == this->end())) {

			this->elemente.erase(it);
		}
	}

	// modifica c1 cu c2
	void update(T& c1, T& c2) {
		typename vector<T>::iterator it;

		it = find(this->elemente.begin(), this->elemente.end(), c1);
		if (!(it == this->end())) {

			*it = c2;
		}
	};

	void clear() {
		this->elemente.clear();
	}


	void setNumar(int pos, int newNumar) {

		this->elemente[pos].setNumar(newNumar);

	}


	T getElem(int i) {

		return this->elemente[i];

	}

};
/*

void Repo<T>::saveToFile() {
	ofstream fout("prajituri.txt");
	for (unsigned i = 0; i < elemente.size(); i++)
		fout << elemente[i].getId() << " " << elemente[i].getNume() << " " << elemente[i].getIngrediente() << " " << elemente[i].getPret() << endl;
	fout.close();
}

template<class T>

void Repo<T>::loadToFile() {
	ifstream fin("prajituri.txt");
	int id;
	char nume[20];
	char ingrediente[30];
	double pret;
	while (fin >> id >> nume >> ingrediente >> pret) {
		elemente.push_back(Prajitura(id, nume, ingrediente, pret));
	}
}*/