#include "Test.h"
#include <cassert>
#include "Prajitura.h"
#include "Repo.h"
#include "Service.h"


void TestRepo::testRepo() {
	this->repoPrajituri.setFileName("testPrajituri.txt");
	this->repoPrajituri.loadFromFile();
	int n = this->repoPrajituri.getAll().size();
	vector<Prajitura> prajituri = this->repoPrajituri.getAll();
	for (int i = 0; i <n; i++)
		assert(prajituri[i] == this->prajituriTest[i]);
}


void TestRepo::testAdd() {
	this->repoPrajituri.setFileName("testPrajituri.txt");
	this->repoPrajituri.loadFromFile();
	int n = this->repoPrajituri.getAll().size();

	char* nume1 = new char[strlen("Tiramisu") + 1];
	strcpy_s(nume1, strlen("Tiramisu") + 1, "Tiramisu");
	char* ingredinte1 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji1(1, nume1, ingredinte1, 5.5);

	this->repoPrajituri.addElem(praji1);
	assert(this->repoPrajituri.getAll().size() == n + 1);
	assert(this->repoPrajituri.getAll()[n] == praji1);

	delete[] nume1;
	delete[] ingredinte1;
}


void TestRepo::testDelete() {
	this->repoPrajituri.setFileName("testPrajituri.txt");
	this->repoPrajituri.loadFromFile();
	int n = this->repoPrajituri.getAll().size();

	char* nume1 = new char[strlen("Tiramisu") + 1];
	strcpy_s(nume1, strlen("Tiramisu") + 1, "Tiramisu");
	char* ingredinte1 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji1(1, nume1, ingredinte1, 5.5);

	this->repoPrajituri.stergere(praji1);
	assert(this->repoPrajituri.getAll().size() == n-1);

	delete[] nume1;
	delete[] ingredinte1;
}


void TestRepo::testUpdate() {
	this->repoPrajituri.setFileName("testPrajituri.txt");
	this->repoPrajituri.loadFromFile();
	int n = this->repoPrajituri.getAll().size();

	char* nume1 = new char[strlen("Tiramisu") + 1];
	strcpy_s(nume1, strlen("Tiramisu") + 1, "Tiramisu");
	char* ingredinte1 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji1(1, nume1, ingredinte1, 5.5);

	this->repoPrajituri.addElem(praji1);

	char* nume2 = new char[strlen("Amandina") + 1];
	strcpy_s(nume2, strlen("Amandina") + 1, "Amandina");
	char* ingredinte2 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte2, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji2(2, nume2, ingredinte2, 6.5);

	this->repoPrajituri.update(praji1, praji2);
	assert(this->repoPrajituri.getAll()[0].getId() == 2);

	
}

TestRepo::TestRepo() {

	char* nume1 = new char[strlen("Tiramisu") + 1];
	strcpy_s(nume1, strlen("Tiramisu") + 1, "Tiramisu");
	char* ingredinte1 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji1(1, nume1, ingredinte1, 5.5);

	char* nume2 = new char[strlen("Amandina") + 1];
	strcpy_s(nume2, strlen("Amandina") + 1, "Amandina");
	char* ingredinte2 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte2, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji2(2, nume2, ingredinte2, 4.5);

	char* nume3 = new char[strlen("Cremes") + 1];
	strcpy_s(nume3, strlen("Cremes") + 1, "Cremes");
	char* ingredinte3 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte3, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji3(3, nume3, ingredinte3, 5.5);

	this->prajituriTest.push_back(praji1);
	this->prajituriTest.push_back(praji2);
	this->prajituriTest.push_back(praji3);

	delete[] nume1;
	delete[] nume2;
	delete[] nume3;
	delete[] ingredinte1;
	delete[] ingredinte2;
	delete[] ingredinte3;

}

void TestRepo::mainTest() {
	this->testRepo();
	this->testAdd();
	this->testDelete();

}


void testPrajitura() {
	char* nume1 = new char[strlen("Tiramisu") + 1];
	strcpy_s(nume1, strlen("Tiramisu") + 1, "Tiramisu");
	char* ingredinte1 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji1(1, nume1, ingredinte1, 5.5);

	assert(praji1.getId() == 1);
	assert(praji1.getPret() == 5.5);
	assert(strcmp(praji1.getNume(), "Tiramisu") == 0);
	praji1.setPret(6.6);
	assert(praji1.getPret() == 6.6);

	delete[] nume1;
	delete[] ingredinte1;
}

void testRepoPrajitura() {
	char* nume1 = new char[strlen("Tiramisu") + 1];
	strcpy_s(nume1, strlen("Tiramisu") + 1, "Tiramisu");
	char* ingredinte1 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji1(1, nume1, ingredinte1, 5.5);

	char* nume2 = new char[strlen("Amandina") + 1];
	strcpy_s(nume2, strlen("Amandina") + 1, "Amandina");
	char* ingredinte2 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte2, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji2(2, nume2, ingredinte2, 4.5);

	char* nume3 = new char[strlen("Cremes") + 1];
	strcpy_s(nume3, strlen("Cremes") + 1, "Cremes");
	char* ingredinte3 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte3, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");
	Prajitura praji3(3, nume3, ingredinte3, 5.5);

	Repo<Prajitura> repoPrajitura;
	repoPrajitura.addElem(praji1);
	repoPrajitura.addElem(praji2);
	repoPrajitura.addElem(praji3);

	assert(repoPrajitura.getAll()[0] == praji1);
	assert(repoPrajitura.getAll()[1] == praji2);
	assert(repoPrajitura.getAll()[2] == praji3);

	delete[] nume1;
	delete[] nume2;
	delete[] nume3;
	delete[] ingredinte1;
	delete[] ingredinte2;
	delete[] ingredinte3;
}


void TestService::testAllService() {
	char* nume1 = new char[strlen("Tiramisu") + 1];
	strcpy_s(nume1, strlen("Tiramisu") + 1, "Tiramisu");
	char* ingredinte1 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");

	char* nume2 = new char[strlen("Amandina") + 1];
	strcpy_s(nume2, strlen("Amandina") + 1, "Amandina");
	char* ingredinte2 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte2, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");

	char* nume3 = new char[strlen("Cremes") + 1];
	strcpy_s(nume3, strlen("Cremes") + 1, "Cremes");
	char* ingredinte3 = new char[strlen("cafea_piscoturi") + 1];
	strcpy_s(ingredinte3, strlen("cafea_piscoturi") + 1, "cafea_piscoturi");

	Service servicePrajituri;
	servicePrajituri.addPrajitura(1, nume1, ingredinte1, 5.5);
	servicePrajituri.addPrajitura(2, nume2, ingredinte2, 4.5);
	servicePrajituri.addPrajitura(3, nume3, ingredinte3, 5.5);
	assert(servicePrajituri.getSize() == 3);

	servicePrajituri.deletePrajituraByID(1);
	assert(servicePrajituri.getSize() == 2);

	servicePrajituri.updatePrajituraByID(2, 1, nume1, ingredinte1, 4.5);
	assert(servicePrajituri.getAll()[0].getId() == 1);

	std::map<std::string, double> rez = servicePrajituri.medieIngrediente();
	float result = float(abs(rez["cafea"] - 5.0));
	assert(0.00001 > result);

	delete[] nume1;
	delete[] nume2;
	delete[] nume3;
	delete[] ingredinte1;
	delete[] ingredinte2;
	delete[] ingredinte3;

}