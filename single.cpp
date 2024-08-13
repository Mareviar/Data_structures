#include<iostream>
#include<string>

using namespace std;

class elementSingleList {
public:
	int value;
	elementSingleList* next;
};

class singleList {
public:
	elementSingleList* begin;
	int size=0;
};

void createSingleList(singleList& obj) {
	obj.size = 0;
	obj.begin = new elementSingleList;
}

void add_to_begin_1_list(singleList& obj, int elem) {
	if (obj.size == 0) {
		elementSingleList* node = new elementSingleList;
		(*node).value = elem;
		obj.begin = node;
		obj.size++;
	}
	else {
		elementSingleList* newPointer = new elementSingleList;
		(*newPointer).value = elem;
		(*newPointer).next = obj.begin;
		obj.begin = newPointer;
		obj.size++;
	}
}

void addToSingleList(singleList& obj, int element) {
		elementSingleList* nextPointer = obj.begin;
		for (auto i = 0; i < obj.size; i++) {
			nextPointer = (*nextPointer).next;
		}
		elementSingleList* newPointer = new elementSingleList;
		(*newPointer).value = element;
		(*newPointer).next = (*nextPointer).next;
		(*nextPointer).next = newPointer;
		obj.size = obj.size + 1;
	
}

void getelem(singleList& obj, int value) {
	elementSingleList* getdata = obj.begin;
	for (int i = 0; i < obj.size; i++) {
		if ((*getdata).value == value) {
			cout << "элемент есть" << endl;
			break;
		}
		getdata = (*getdata).next;
		if (i == obj.size -1 ) {
			cout <<"элемента " << value << " нет";
		}
	}
}

void del_from_begin(singleList& obj) {
		elementSingleList* nextPointer = obj.begin;
		obj.begin = (*nextPointer).next;
		delete nextPointer;
		obj.size = obj.size - 1;
		return;
}

void del_from_end(singleList& obj) {
	elementSingleList* nextPointer = obj.begin;
	for (auto i = 0; i < obj.size-1; i++) {
		nextPointer = (*nextPointer).next;
	}
	elementSingleList* wasPointer = (*nextPointer).next;
	(*nextPointer).next = (*wasPointer).next;
	delete wasPointer;
	obj.size = obj.size - 1;
}

void delFromSingleList(singleList& obj, int value) { // удаление по значению
	elementSingleList* nextPointer = obj.begin;
	for (int i = 0; i < obj.size; i++) {
		if ((*nextPointer).next->value == value) {
			elementSingleList* delpoint = (*nextPointer).next;
			(*nextPointer).next = (*delpoint).next;
			delete delpoint;
		}
		else {
			nextPointer = (*nextPointer).next;
		}
	}
}

void delFromSingleList_index(singleList& obj, int index) {

	if (obj.size > index) {

		elementSingleList* nextPointer = obj.begin;
		for (auto i = 0; i < index - 1; i++) {
			nextPointer = (*nextPointer).next;
		}
		elementSingleList* wasPointer = (*nextPointer).next;
		(*nextPointer).next = (*wasPointer).next;
		delete wasPointer;
		obj.size = obj.size - 1;
	}
}

void printLinkedList(singleList& obj) {
	elementSingleList* tmp = obj.begin;
	for (int i = 0; i < obj.size; i++) {
		cout << (*tmp).value << " ";
		tmp = obj.begin->next;
		obj.begin = obj.begin->next;
	}
	printf("\n");
}
