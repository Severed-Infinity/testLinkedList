#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string>

template <typename T>

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList &list);
	void operator=(const LinkedList &list);
	void addItem(const T &data);
	void displayItem(std::string typeToFind);
	bool findName(std::string nameToFind, int &itemID);
	bool deleteItem(int idToDelete);

private:
	Node<T> *head;
	Node<T> *tail;
	template <typename T>
	class Node {
	public:
		Node();
		Node(const T data, Node *next = nullptr) : data(data), next(next){};
		Node(int id, int size, std::string name, std::string type) : data(new T(id, size, name, type)), next(nullptr){};
		Node(Node &node) : data(n);
		~Node();
		void operator=(Node &node);

	private:
		T data;
		Node *next;
	};
	
};

template <typename T>
void LinkedList<T>::Node<T>::operator=(Node &node){
	Node<T> *tmp = node;
}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &list){
	Node<T> *iter = list.head;
	Node<T> *tmp = nullptr;
	while (iter != tail){
		tmp = new Node<T>(iter);
		tmp->next = head;
		head = tmp;

		iter = iter->next;
	}
}

template <typename T>
LinkedList<T>::~LinkedList(){
	Node<T> *current = head;
	while (head){
		current = head;
		head = head->next;
		delete current;
	}

	head = nullptr;
	tail = nullptr;
}

template <typename T>
void LinkedList<T>::operator=(const LinkedList &list){
	Node<T> *iter = list.head;
	Node<T> *tmp = nullptr;
	while (iter != tail){
		tmp = new Node<T>(iter);
		tmp->next = head;
		head = tmp;

		iter = iter->next;
	}
}

template <typename T>
void LinkedList<T>::addItem(const T &data){
	head = new Node<T>(data, head);

	if (!tail){
		tail = head;
	}
}

template <typename T>
void LinkedList<T>::displayItem(std::string typeToFind){
	Node<T> *iter = head;
	while (iter != nullptr){
		if (iter->data.getType() == typeToFind){
			std::cout << "Name: " << iter->data.getName() << endl;
		}
		iter = iter->next;
	}

	delete iter;
}

template <typename T>
bool LinkedList<T>::findName(std::string nameToFind, int &itemID){
	Node<T>* iter = head;

	if (iter == nullptr){
		return false;
	}

	if (iter->data.getName() == nameToFind) {
		itemID = iter->data.getID();
		return true;
	}
	while (iter->data.getName() != nameToFind){
		if (iter->data.getName() == nameToFind){
			return true;
		}
		else {
			iter->next;
		}
	}
	return false
}

template <typename T>
bool LinkedList<T>::deleteItem(int idToDelete){
	

	if (iter == nullptr){
		return false;
	}

	if (iter->data.getID() == idToDelete) {
		return true;
	}
	while (iter->data.getID() != idToDelete){
		if (iter->data.getid() == idToDelete){
			return true;
		}
		else {
			iter->next;
		}
	}
	return false;
}

#endif