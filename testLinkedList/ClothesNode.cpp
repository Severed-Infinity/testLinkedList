#include "CLOTHESNode.h"

CLOTHESNode::CLOTHESNode(int id1, int size1, string name1, string type1) {
	item.setId(id1);
	item.setSize(size1);
	item.setName(name1);
	item.setType(type1);
	next = NULL;
}

CLOTHESNode::~CLOTHESNode() {
	//delete next;
}

CLOTHESNode::CLOTHESNode(CLOTHESNode &n) {
	clothesPtr temp = new CLOTHESNode(n.item.getId(), n.item.getSize(), n.item.getName(), n.item.getType());
}

void CLOTHESNode::operator=(CLOTHESNode &n) {
	clothesPtr temp = new CLOTHESNode(n.item.getId(), n.item.getSize(), n.item.getName(), n.item.getType());
}