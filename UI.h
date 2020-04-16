#pragma once
#include "Service.h"

class UI {
private:
	Service servicePraji;
public:
	void display();
	void meniu();
	void handleAdd();
	void handleShow();
	void handleDelete();
	void handleUpdate();
	void handleMedie();
	UI();
	~UI();
	UI(const Service& s);

};
