#include<stdio.h>
#include<iostream>

using namespace std;

typedef struct nodet {
	int data; 
	struct nodet* left; 
	struct nodet* right; 
} NodeT;


NodeT* createNode(int data) {
	NodeT* newNode = (NodeT*)malloc(sizeof(NodeT)); 
	newNode->data = data; 
	newNode->left = NULL;
	newNode->right = NULL; 
	return newNode; 
}

NodeT* insertT(NodeT* root, int data) {
	if (root == NULL) {
		return createNode(data); // Если дерево пусто, создаем новый узел и возвращаем его
	}
	if (data < root->data) {
		root->left = insertT(root->left, data); // Рекурсивная вставка в левое поддерево
	}
	else if (data > root->data) {
		root->right = insertT(root->right, data); // Рекурсивная вставка в правое поддерево
	}
	return root; // Возвращаем указатель на корень дерева
}

void searchT(NodeT* root, int data) {
	if (root == NULL) {
		cout << "элемента " << data << " нет";
	}
		else if ( root->data == data) {
			cout << "элемент " << data << " есть"; // Если дерево пусто или найдено соответствие, возвращаем текущий узел

		}
		else if (data < root->data) {
			searchT(root->left, data); // Рекурсивный поиск в левом поддереве
		}
		else {
			searchT(root->right, data); // Рекурсивный поиск в правом поддереве
		}
}

// Функция для удаления узла из дерева
NodeT* deleteT(NodeT* root, int data) {
	if (root == NULL) {
		return root; // Если дерево пусто, возвращаем NULL
	}
	if (data < root->data) {
		root->left = deleteT(root->left, data); // Рекурсивное удаление из левого поддерева
	}
	else if (data > root->data) {
		root->right = deleteT(root->right, data); // Рекурсивное удаление из правого поддерева
	}
	else {
		if (root->left == NULL) {
			NodeT* temp = root->right;
			free(root);
			return temp; // Узел без левого поддерева, возвращаем правое поддерево
		}
		else if (root->right == NULL) {
			NodeT* temp = root->left;
			free(root);
			return temp; // Узел без правого поддерева, возвращаем левое поддерево
		}
		NodeT* temp = root->right;
		while (temp && temp->left != NULL) {
			temp = temp->left;
		}
		root->data = temp->data;
		root->right = deleteT(root->right, temp->data); // Заменяем удаляемый узел на наименьший узел правого поддерева
	}
	return root; 
}

void outputT(NodeT* node, int level) {
	if (node == NULL) return;
	outputT(node->right, level + 1);	// right
	for (int i = 0; i < level; i++) { printf("\t"); }
	printf(" % d\n", node->data);
	outputT(node->left, level + 1); // левое
}


int main() {
	setlocale(LC_ALL, "Rus");
	NodeT* node = new NodeT;
	node = createNode(13);
	node = insertT(node, 245);
	node = insertT(node, 2);
	node = insertT(node, 1235);
	node = insertT(node, 43);
	insertT(node, 8);
	insertT(node, 11);
	insertT(node, 7);
	insertT(node, 1);
	outputT(node, 0);
	searchT(node, 7); cout << endl;
	searchT(node, 54675);
}
