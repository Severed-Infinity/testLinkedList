#ifndef CLOTHESNODE_H
#define CLOTHESNODE_H

#include "Clothes.h"

class CLOTHESNode {
	friend class CLOTHESList;
public:
	CLOTHESNode(int id, int size, string name, string type);
	CLOTHESNode(CLOTHESNode &n);
	void operator=(CLOTHESNode &n);
	~CLOTHESNode();
private:
	Clothes item;
	CLOTHESNode* next;
};

typedef CLOTHESNode* clothesPtr;

#endif