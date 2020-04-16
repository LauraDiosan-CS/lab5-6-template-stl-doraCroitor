#pragma once
#include <vector>
#include "RepoSTL.h"
#include "Prajitura.h"


class TestRepo {
private:
	RepoSTL<Prajitura> repoPrajituri;
	vector<Prajitura> prajituriTest;
	void testRepo();
	void testAdd();
	void testDelete();
	void testUpdate();
public:
	TestRepo();
	void mainTest();
};

class TestService
{
public:
	void testAllService();


};