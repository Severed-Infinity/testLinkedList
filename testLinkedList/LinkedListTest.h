#include <iostream>

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void PushBack(const T &data);
	void PushFront(const T &data);
	void PopBack();
	void PopFront();
	void Clear();
	bool IsEmpty() const;
	unsigned int Size() const;
	T& Front() const;
	T& Back() const;

private:
	template <typename T>
	struct Node {
		Node(const T &data, struct Node *next = nullptr) : data(data), next(next){}
		T data;
		Node *next;
	};
	Node<T> *head;
	Node<T> *tail;

};

template <typename T>
LinkedList<T>::LinkedList() :head(nullptr), tail(nullptr){}

template <typename T>
LinkedList<T>::~LinkedList(){
	Clear();
}

template <typename T>
void LinkedList<T>::PushBack(const T &data){
	if (!head){
		head = new Node<T>(data);
		tail = head;
		return;
	}
	tail->next = new Node<T>(data);
	tail = tail->next;
}

template <typename T>
void LinkedList<T>::PushFront(const T &data) {
	head = new Node<T>(data, head);

	if (!tail){
		tail = head;
	}
}

template <typename T>
void LinkedList<T>::PopBack() {
	if (!head){
		std::cout << "cannot pop from empty list" << endl;
	}

	if (head == tail){
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	Node<T> *current = head;
	while (current->next != tail){
		current = current->next;
	}

	delete tail;
	tail = current;
	tail->next = nullptr;
}


template <typename T>
void LinkedList<T>::PopFront() {
	if (!head){
		std::cout << "cannot pop from empty list" << endl;
		return;
	}
	if (head == tail){
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	Node<T> *tmp = head->next;
	delete head;
	head = tmp;
}

template <typename T>
void LinkedList<T>::Clear(){
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
bool LinkedList<T>::IsEmpty() const{
	return head == nullptr;
}

template <typename T>
unsigned int LinkedList<T>::Size() const {
	unsigned int size = 0;
	for (Node<T> *current = head; current; current = current->next){
		++size;
	}
	return size;
}

template <typename T>
T& LinkedList<T>::Front() const {
	if (!head){
		std::cout << "cannot return value from empty list" << endl;
	}

	return head->data;
}

template <typename T>
T& LinkedList<T>::Back() const{
	if (!head){
		std::cout << "cannot return value from empty list" << endl;
	}

	return tail->data;
}