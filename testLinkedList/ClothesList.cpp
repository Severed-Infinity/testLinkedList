#include "CLOTHESList.h"
#include <iostream>
using namespace std;

CLOTHESList::CLOTHESList() {
	head = NULL;
}


CLOTHESList::~CLOTHESList() {
	while (head != NULL) {
		clothesPtr temp = head;
		head = head->next;
		delete temp;
	}
}


void CLOTHESList::addClothes(int id, int size, string name, string type) {
	clothesPtr temp = new CLOTHESNode(id, size, name, type);
	temp->next = head;
	head = temp;
}

void CLOTHESList::displayType(string typeToFind) {
	clothesPtr temp = head;
	while (temp != NULL) {
		if (temp->item.getType() == typeToFind) {
			cout << "\nName: " << temp->item.getName() << endl;
		}
		// iterate
		temp = temp->next;
	}
	delete temp;
}
bool CLOTHESList::findName(string nameToFind, int &idOfCLOTHES) {
	clothesPtr temp = head;
	//If head is key
	if (head != NULL && head->item.getName() == nameToFind) {
		idOfCLOTHES = head->item.getId();
		return 1;
	}
	else {
		//Traverse list
		while (temp != NULL && temp->item.getName() != nameToFind) {
			temp = temp->next;
		}
	}

	if (temp == NULL) {
		return 0;
	}
	else {
		idOfCLOTHES = temp->item.getId();
		return 1;
	}
	delete temp;
}

bool CLOTHESList::deleteClothes(int idToDelete) {
	clothesPtr lead = head;
	clothesPtr trail = NULL;
	//If head is key
	if (head != NULL && head->item.getId() == idToDelete) {
		head = head->next;
		delete lead;
		return 1;
	}
	else {
		//Traverse list
		while (lead != NULL && lead->item.getId() != idToDelete) {
			trail = lead;
			lead = lead->next;
		}
	}

	if (lead == NULL) {
		return 0;
	}
	else {
		trail->next = lead->next;
		delete lead;
		return 1;
	}
	delete trail;
}

// Copy Constructor
CLOTHESList::CLOTHESList(const CLOTHESList &l) {
	clothesPtr source = l.head;
	clothesPtr temp = NULL;
	while (source != NULL) {
		// copy over
		temp = new CLOTHESNode(source->item.getId(), source->item.getSize(), source->item.getName(), source->item.getType());
		temp->next = head;
		head = temp;
		// iterate source to next node
		source = source->next;
	}
}

void CLOTHESList::operator=(const CLOTHESList &l) {
	clothesPtr source = l.head;
	clothesPtr temp = NULL;
	while (source != NULL) {
		// copy over
		temp = new CLOTHESNode(source->item.getId(), source->item.getSize(), source->item.getName(), source->item.getType());
		temp->next = head;
		head = temp;
		// iterate source to next node
		source = source->next;
	}
}
