#include <iostream>
#include "Prajitura.h"
#include "Test.h"
#include "Repo.h"
#include "UI.h"
#include "Service.h"
#include "RepoSTL.h"

using namespace std;

int main() {

	TestRepo t;
	t.mainTest();
	RepoSTL<Prajitura> repoPrajitura("prajituri.txt");
	//Repo<Prajitura> repoPrajitura;
	Service s (repoPrajitura);
	UI u (s);
	u.meniu();
	cout << "Programul s-a sfarsit ! ";
	return 0;
}

