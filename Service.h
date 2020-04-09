#pragma once
#include "Prajitura.h"
#include "Repo.h"
#include "RepoSTL.h"

class Service {
private:
	RepoSTL<Prajitura> repoPrajituri;
public:
	Service();
	Service(const Service& s);
	~Service();
	Service(const RepoSTL<Prajitura>& repoPrajituri);

	void setRepo(RepoSTL<Prajitura>& repoPrajituri);
	int getSize();

	void addPrajitura(int id,char* nume, char* ingrediente, double pret);
	void deletePrajituraByID(int id);
	void updatePrajituraByID(int id, int newId,  char* nume,  char* ingrediente, double pret);
	vector<Prajitura> getAll();
};