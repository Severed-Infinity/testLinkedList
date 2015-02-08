#ifndef CLOTHES_H
#define CLOTHES_H
#include <string>
using namespace std;

class Clothes {
public:
	int getId();
	int getSize();
	string getName();
	string getType();
	void setId(int id);
	void setSize(int id);
	void setName(string name);
	void setType(string type);
	void operator<<(Clothes c);
private:
	int id;
	int size;
	string name;
	string type;
};
#endif