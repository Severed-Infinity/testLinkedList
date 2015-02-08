#ifndef CLOTHESLIST_H
#define CLOTHESLIST_H
#include "CLOTHESNode.h"

class CLOTHESList {
public:
	CLOTHESList();
	~CLOTHESList();
	CLOTHESList(const CLOTHESList &l);
	void operator=(const CLOTHESList &l);
	void addClothes(int id, int size, string name, string type);
	void displayType(string tyepeToFind);
	bool findName(string nameToFind, int &itOfCLOTHES);
	bool deleteClothes(int idToDelete);
private:
	clothesPtr head;
};

#endif