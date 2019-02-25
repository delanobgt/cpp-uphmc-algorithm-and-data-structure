#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct aNode {
	int data;
	aNode *next;
} Node;

typedef struct aList {
	Node *head;
	Node *tail;
	int count;
} LinkedList;

LinkedList* NewLinkedList() {
	LinkedList *list = new LinkedList;
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
}

void AddItem(LinkedList *list, int item) {
	Node *newNode = new Node;
	newNode->data = item;
	newNode->next = NULL;
	if (list->head == NULL) {
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		list->tail->next = newNode;
		list->tail = newNode;		
	}
	list->count++;
}

void DisplayData(LinkedList *list) {
	printf("List Item :\n");
	Node *ptr = list->head;
	while (ptr != NULL) {
		printf("%5i ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int Count(LinkedList *list) {
	if (list != NULL) 
		return list->count;
	return 0;
}

bool FindItem(LinkedList *list, int item) {
	if (list != NULL && list->head != NULL) {
		Node *ptr = list->head;
		while (ptr != NULL) {
			if (ptr->data == item) return true;
			ptr = ptr->next;
		}
	}
	return false;
}

void InsertItem(LinkedList *list, int index, int item) {
	if (Count(list) > 0 && index >= 0 && index <= Count(list)) { // index valid ?
		if (index == 0) { // sisip depan
			Node *newNode = new Node;
			newNode->data = item;
			newNode->next = list->head;
			list->head = newNode;
			list->count++;
		}
		else if (index == Count(list)) // sisip belakang
			AddItem(list, item);	
		else { // sisip tengah
			Node *ptr = list->head;
			int idx = 0;
			while (idx < index-1) {
				ptr = ptr->next;
				idx++;
			}
			Node *newNode = new Node;
			newNode->data = item;
			newNode->next = ptr->next;
			ptr->next = newNode;
			list->count++;
		}
	}
}

int main() {
	LinkedList *list = NULL;
	list = NewLinkedList();
	srand(time(0));
	for (int i = 1; i <= 10; i++) {
		int item = rand() % 100 + 1;
		printf("Add item %2i ke dalam list\n", item);
		AddItem(list, item);
	}
	DisplayData(list);
	printf("Banyak elemen data dalam list : %i\n", Count(list));
	printf("Elemen data 2 ada dalam list ? %s\n", (FindItem(list, 2) ? "Ya" : "Tidak"));
	printf("Elemen data 20 ada dalam list ? %s\n", (FindItem(list, 20) ? "Ya" : "Tidak"));
	printf("sisip elemen data 1000 ke index 0\n");
	InsertItem(list, 0, 1000);
	DisplayData(list);
	printf("sisip elemen data 500 ke index terakhir\n");
	InsertItem(list, Count(list), 500);
	DisplayData(list);	
	printf("sisip elemen data 700 ke index 2\n");
	InsertItem(list, 2, 700);
	DisplayData(list);
	return 0;	
}
