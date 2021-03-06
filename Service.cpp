#include "Service.h"

// Constructor
Service::Service() 
{

}

//Constructor cu param
Service::Service(const RepoSTL<Prajitura>& repoPrajituri) 
{
	this->repoPrajituri = repoPrajituri;
}

//Constructor de copiere
Service::Service(const Service& s) 
{
	this->repoPrajituri = s.repoPrajituri;
}

//Destructor
Service::~Service() {

}


void Service::setRepo(RepoSTL<Prajitura>& repoPrajituri) {
	this->repoPrajituri = repoPrajituri;
}


// Lungimea 
int Service::getSize() {
	return this->repoPrajituri.getSize();
}


/*
	Desc: Adauga o prajitura
	In: id - id-ul prajiturii, int
		nume - numele prajiturii, char
		ingrediente - ingredientele prajiturii, char
		pret - pretul, double
	Out:
*/
void Service::addPrajitura(int id, char* nume, char* ingrediente, double pret) {
	Prajitura praji(id, nume, ingrediente, pret);
	this->repoPrajituri.addElem(praji);
	this->repoPrajituri.saveToFile();
}


/*
	Desc: Sterge o prajitura dupa id
	In: id - id-ul prajiturii care o sa fie stearsa, int
	Out:
*/
void Service::deletePrajituraByID(int id) {
	vector<Prajitura> prajituri= this->repoPrajituri.getAll();
	for (int i = 0; i < this->repoPrajituri.getSize(); i++) {
		if (prajituri[i].getId() == id) {
			Prajitura prajiDeSters(id, prajituri[i].getNume(), prajituri[i].getIngrediente(), prajituri[i].getPret());
			this->repoPrajituri.stergere(prajiDeSters);
			this->repoPrajituri.saveToFile();
			return;
		}
	}
}


/*
	Desc: Modifica o prajitura dupa id
	In: id - id-ul prajiturii care urmeaza sa fie modificata, int
		newId - noul id, int
		nume - noul nume, char
		ingrediente - noile ingrediente, char
		pret - noul pret, double
	Out:
*/
void Service::updatePrajituraByID(int id, int newId , char* nume,  char* ingrediente, double pret) {
	vector<Prajitura> prajituri = this->repoPrajituri.getAll();
	Prajitura newPraji(newId, nume, ingrediente, pret);
	for (int i = 0; i < this->repoPrajituri.getSize(); i++) {
		if (prajituri[i].getId() == id) {
			Prajitura oldPraji(id, prajituri[i].getNume(), prajituri[i].getIngrediente(), prajituri[i].getPret());
			this->repoPrajituri.update(oldPraji, newPraji);
			this->repoPrajituri.saveToFile();
			return;
		}
	}

}


// toate prajiturile
vector<Prajitura> Service::getAll() {
	return repoPrajituri.getAll();
}

/*
	Desc: Adauga ingredientele din fiecare prejitura
	In: 
	Out: 
*/
void Service::newIngrediente() {
	if (this->repoPrajituri.getAll().size() == 0)
		return;
	vector<Prajitura> prajituri = this->repoPrajituri.getAll();
	for(int j=0;j<prajituri.size();j++)
	{	int count = 0;
		string ingrediente = string(prajituri[j].getIngrediente());
		for (int i = 0; i < ingrediente.length(); i++) {
			if (ingrediente[i] == '_') {
				i++;
				this->ingrediente.insert(ingrediente.substr(count, i - count - 1));
				count = i;
			}

		}
		this->ingrediente.insert(ingrediente.substr(count, ingrediente.length() - count));
		//this->ingrediente.insert(ingrediente.substr(count, ingrediente.length() - count));
	}
}


/*
	Desc: Calculeaza medie ingredientelor
	In:
	Out: medie pentru fiecare ingredient
*/
map<string, double> Service::medieIngrediente() {
	map<string, double> rez;
	map<string, int> cnt;
	this->newIngrediente();
	for (auto iter = begin(this->ingrediente); iter != end(this->ingrediente); ++iter) 
	{
		rez[*iter] = 0;
		cnt[*iter] = 0;
		for (Prajitura praji : this->repoPrajituri.getAll()) {
			if (string(praji.getIngrediente()).find(*iter) != string::npos) {
				rez[*iter] += praji.getPret();
				cnt[*iter]++;
			}
		}
		rez[*iter] /= cnt[*iter];
	}
	return rez;
}



