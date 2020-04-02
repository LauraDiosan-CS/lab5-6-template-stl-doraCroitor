#include "Test.h"
#include <cassert>
#include "Prajitura.h"
#include "Repo.h"

void testPrajitura() {
	char* nume1 = new char[strlen("Tiramisu") + 1];
	strcpy_s(nume1, strlen("Tiramisu") + 1, "Tiramisu");
	char* ingredinte1 = new char[strlen("cafeaPiscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafeaPiscoturi") + 1, "cafeaPiscoturi");
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
	char* ingredinte1 = new char[strlen("cafeaPiscoturi") + 1];
	strcpy_s(ingredinte1, strlen("cafeaPiscoturi") + 1, "cafeaPiscoturi");
	Prajitura praji1(1, nume1, ingredinte1, 5.5);

	char* nume2 = new char[strlen("Amandina") + 1];
	strcpy_s(nume2, strlen("Amandina") + 1, "Amandina");
	char* ingredinte2 = new char[strlen("cafeaPiscoturi") + 1];
	strcpy_s(ingredinte2, strlen("cafeaPiscoturi") + 1, "cafeaPiscoturi");
	Prajitura praji2(2, nume2, ingredinte2, 4.5);

	char* nume3 = new char[strlen("Cremes") + 1];
	strcpy_s(nume3, strlen("Cremes") + 1, "Cremes");
	char* ingredinte3 = new char[strlen("cafeaPiscoturi") + 1];
	strcpy_s(ingredinte3, strlen("cafeaPiscoturi") + 1, "cafeaPiscoturi");
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