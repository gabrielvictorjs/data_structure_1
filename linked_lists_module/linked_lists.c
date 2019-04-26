#include<stdio.h>
#include<stdlib.h>

/*
 * Algoritimo de lista encadeada que adiciona no top e imprime */

struct node {
	int info;
	struct node* next;
};

typedef struct node Node;

Node* createNode() {
	Node* headNode = (Node*) malloc(sizeof(Node));
	return headNode;
}

Node* insertNodeAtStart(Node* list, int number) {
	Node* newNode = createNode();
	newNode->info = number;
	
	if(list == NULL) {
		list = newNode;
		newNode->next = NULL;
	} else {
		newNode->next = list;
		list = newNode;
	}
	
	return list;
}

/* função recursiva que itera todos os itens 
 * para descobrir qual o ultimo nó */
 
Node* lastNodeFromList(Node* aux) {	
	if(aux->next == NULL) return aux;
	return lastNodeFromList(aux->next);
}

Node* insertNodeAtEnd(Node* list, int number) {
	Node* newNode = createNode();
	newNode->info = number;
	
	if(list == NULL) {
		newNode->next = NULL;
		list = newNode;
	} else {
		Node* aux = lastNodeFromList(list);
		newNode->next = NULL;
		aux->next = newNode;
	}
	
	return list;
}

void printList(Node* list) {
	if(list != NULL) {
		printf("number: %d \n", list->info);
		printList(list->next);
	}
}


int main(int argc, char* argv[]) {
	printf("LINKED LIST \n\n");
	
	Node* list = NULL;
	
	list = insertNodeAtStart(list, 2);
	list = insertNodeAtEnd(list, 3);
	list = insertNodeAtStart(list, 1);
	
	
	
	printList(list);
	
	
	return 0;
}
