#include<iostream>
#include<string>

using namespace std;

class Node_2list {
public:
	int data;
	Node_2list* next;
	Node_2list* prev;
};

class doublelist {
public:
	int size;
	Node_2list* head;
	Node_2list* tail;
};

void create2List(doublelist& obj) {
	obj.size = 0;
	obj.head = new Node_2list;
	obj.tail = obj.head;
	obj.head->next = obj.tail;
	obj.tail->prev = obj.head;
}

void add_to_begin(doublelist& obj, int elem) {
	if (obj.size == 0) {
		Node_2list* node = new Node_2list;
		(*node).data = elem;
		obj.head = node;
		obj.tail = obj.head;
		obj.size++;
	}
	else {
		Node_2list* newPointer = new Node_2list;
		(*newPointer).data = elem;
		(*newPointer).next = obj.head;
		obj.head->prev = newPointer;
		obj.head = newPointer;
		obj.size++;
	}
}

void addback(doublelist& obj, int elem) {
	if (obj.size == 0) {
		Node_2list* node = new Node_2list;
		(*node).data = elem;
		obj.tail = node;
		obj.head = obj.tail;
		obj.size++;
	}
	else {
		Node_2list* newPointer = new Node_2list;
		(*newPointer).data = elem;
		newPointer->prev = obj.tail;
		obj.tail->next = newPointer;
		obj.tail = newPointer;
		obj.size++;
	}
}

void del_begin_2_list(doublelist& obj) {
	Node_2list* nextpointer = obj.head;
	obj.head = (*nextpointer).next;
	delete nextpointer;
	obj.head->prev = obj.head;
	obj.size--;
}

void del_from_tail_2_list(doublelist& obj) {
	Node_2list* nextpointer = obj.tail;
	obj.tail = (*nextpointer).prev;
	delete nextpointer;
	obj.tail->prev->next = obj.tail;
	obj.size--;
}

void deldouble(doublelist& obj, int value) {
	Node_2list* nextpoint = obj.head;
	for (int i = 0; i < obj.size; i++) {
		if ((*nextpoint).data == value) {
			(*nextpoint).prev->next = (*nextpoint).next;
			(*nextpoint).next->prev = (*nextpoint).prev;
			obj.size--;
		}
		else {
			nextpoint = (*nextpoint).next;
		}
	}
}

void getelem(doublelist& obj, int value) {
	Node_2list* getdata = obj.head;
	for (int i = 0; i < obj.size; i++) {
		if ((*getdata).data == value) {
			cout << endl << "элемент " << value <<" есть" << endl;
			break;
		}
		getdata = (*getdata).next;
		if (i == obj.size - 1) {
			cout << "элемента " << value << " нет";
		}
	}
}

void printDblLinkedList(doublelist& obj) {
	Node_2list* tmp = obj.head;
	for (int i = 0; i < obj.size; i++) {
		cout << (*tmp).data << " ";
		tmp = obj.head->next;
		obj.head = obj.head->next;
	}
	printf("\n");
}
