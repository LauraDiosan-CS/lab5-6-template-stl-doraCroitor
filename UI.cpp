#include "UI.h"
#include "Prajitura.h"
#include <iostream>
using namespace std;

UI::UI() {

}


UI::UI(const Service& s) {
	this->servicePraji = s;
}

void UI:: display() {
	cout << "Prajituri \n";
	cout << "1. Adauga prajitura \n";
	cout << "2. Afisare prajituri \n";
	cout << "3. Sterge prajitura \n";
	cout << "4. Modifica prajitura \n";
	cout << "5. Media ingrediente/pret \n";
	cout << "6. Iesire \n";
	cout << endl;
}


void UI::handleAdd() {
	int id;
	double pret;
	char* nume = NULL;
	char* ingrediente = NULL;
	nume = new char[20];
	ingrediente = new char[30];
	cout << "  Id:  ";
	cin >> id;
	cout << "  Nume: ";
	cin >> nume;
	cout << " Ingrediente (sub_aceasta_forma): ";
	cin >> ingrediente;
	cout << " Pret: ";
	cin >> pret;
	this->servicePraji.addPrajitura(id, nume, ingrediente, pret);
	delete[] nume;
	delete[] ingrediente;
}


void UI::handleShow() {
	vector<Prajitura> p = this->servicePraji.getAll();
	int n = p.size();
	for (int i = 0; i < n; i++)
		cout << "Prajitura cu id-ul " << p[i].getId() << " , numele: " << p[i].getNume() << " ,ingrediente: " << p[i].getIngrediente() << " , pret: " << p[i].getPret() << endl;
}


void UI::handleDelete() {
	int id;
	cout << " Ce id are prajitura pe care vrei sa o stergi? ";
	cin >> id;
	this->servicePraji.deletePrajituraByID(id);

}


void UI::handleUpdate() {
	int id, newId;
	double newPret;
	char* newNume = NULL;
	char* newIngrediente = NULL;
	newNume = new char[20];
	newIngrediente = new char[30];
	cout << "  Id:  ";
	cin >> id;
	cout << " Noul id: ";
	cin >> newId;
	cout << "  Noul nume: ";
	cin >> newNume;
	cout << " Noile Ingrediente (subAceastaForma): ";
	cin >> newIngrediente;
	cout << " Noul pret: ";
	cin >> newPret;
	this->servicePraji.updatePrajituraByID(id, newId, newNume, newIngrediente, newPret);

	delete[] newNume;
	delete[] newIngrediente;
}

void UI::handleMedie() {
	map<string, double> rez = this->servicePraji.medieIngrediente();
	for (map<string, double>::iterator it = rez.begin(); it != rez.end(); ++it) {
		cout << it->first << ":" << rez[it->first] << endl;
	}
}

void UI::meniu() {
	int op;
	while (true) {
		this->display();
		cin >> op;
		if (op == 1) {
			this->handleAdd();
		}
		else if (op == 2) {
			this->handleShow();
		}
		else if (op == 3) {
			this->handleDelete();
		}
		else if (op == 4) {
			this->handleUpdate();
		}
		else if (op == 5) {
			this->handleMedie();
		}
		else if (op == 6) {
			break;
		}
		else
			cout << " Nu e ok ce ai ales! ";
	}
}


UI::~UI() {

}
