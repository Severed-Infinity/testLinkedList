#include "Clothes.h"


#include <iostream> 
using namespace std;

int Clothes::getId() {
	return id;
}

int Clothes::getSize() {
	return size;
}

string Clothes::getName() {
	return name;
}

string Clothes::getType() {
	return type;
}


void Clothes::setId(int id1) {
	id = id1;
}

void Clothes::setSize(int size1) {
	size = size1;
}

void Clothes::setName(string name1) {
	name = name1;
}

void Clothes::setType(string type1) {
	type = type1;
}

void Clothes::operator<<(Clothes c) {
	cout << "\nID: " << c.getId() << endl;
	cout << "Size: " << c.getSize() << endl;
	cout << "Name: " << c.getName() << endl;
	cout << "Type: " << c.getType() << endl;
}