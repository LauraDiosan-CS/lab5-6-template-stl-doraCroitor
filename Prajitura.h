#pragma once
#include <iostream>

using namespace std;

class Prajitura {
private:
	int id;
	char* nume;
	char* ingrediente;
	double pret;
public:
	Prajitura();
	Prajitura(int id, char* nume, char* ingrediente, double pret);
	Prajitura(const Prajitura& p);
	~Prajitura();


	int getId();
	char* getNume();
	char* getIngrediente();
	double getPret();
	void setId(int id);
	void setNume(char* nume);
	void setIngrediente(char* ingrediente);
	void setPret(double pret);

	bool operator==(const Prajitura& p);
	Prajitura& operator=(const Prajitura& p);
	friend ostream& operator<<(ostream& os, const Prajitura& p);
	friend istream& operator>>(istream& os, Prajitura& p);
};