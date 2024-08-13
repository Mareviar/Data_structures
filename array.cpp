#include <string.h>
#include<iostream>

using namespace std;

class Array {
public:
	int* array;
	int size = 0;
	int max;
};

void createArray(Array& arr) {
    arr.size = 0;
    arr.max = 5;
    arr.array = new int[5];
}


void setValue(Array& array, int index, int value) {
    if (index >= 0 && index < array.size) {
        *(array.array+index) = value;
    }
    else {
        printf("Index out of bounds.\n");
    }
}

int getValue(Array& array, int index) {
    return *(array.array + index);
}

int getSize(Array& array) {
    return array.size;
}

void insertValue(Array& arr, int index, int value) {
    arr.size++;
    if (arr.size > arr.max) {

        int* newarr = new int[arr.max + 5];
        arr.max = arr.max + 5;
        for (int i = 0; i < arr.size - 1; i++) {
            *(newarr + i) = *(arr.array + i);
        }
        delete[] arr.array;
        arr.array = newarr;
    }
    else {

        for (auto i = index + 1; i < arr.max; i++) {
            *(arr.array + i) = *(arr.array + i - 1);
        }
    }
    *(arr.array + index) = value;
}

void append(Array& arr, int value) {
    int* newarr = new int[arr.max + 5];
    arr.max = arr.max + 5;
    for (int i = 0; i < arr.size - 1; i++) {
        *(newarr + i) = *(arr.array + i);
       
    }
    delete[] arr.array;
    arr.array = newarr;
    *(arr.array) = value;
}


void removeValue(Array& arr, int index) {
    arr.size--;
    for (auto i = index; i < arr.size; i++) {
        *(arr.array + i) = *(arr.array + i + 1);
    }
}

void print(Array& arr) {
    for (int i = 0; i < arr.size; i++) {
        cout << *(arr.array + i) << " ";
    }
}
