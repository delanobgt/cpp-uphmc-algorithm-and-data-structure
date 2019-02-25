#include <stdio.h>

struct Node {
	int data;
	Node* prev;
	Node* next;
};

struct LinkedList {
	Node* head;
	Node* tail;
	int count;	
};

LinkedList* CreateLinkedList() {
	LinkedList* list = new LinkedList;
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
	return list;
}

int CountListItems(LinkedList* list) {
	if (list != NULL) 
		return list->count;
	return 0;
}

void AddItem(LinkedList* list, int item) {
	if (list == NULL) {
		printf("List doesn't exist!\n");
		return;
	}
	
	Node* newNode = new Node;
	newNode->data = item;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (list->count == 0) {
		list->head = newNode;
		list->tail = newNode;
	} else {
		list->tail->next = newNode;
		newNode->prev = list->tail;
		list->tail = newNode;
	}
	list->count++;
	printf("item %i added to list.\n", item);
}

bool IndexIsValid(LinkedList *list, int index) {
	if (list != NULL) {
		return index >= 0 && index <= list->count;
	}
	return false;
}

void InsertItem(LinkedList *list, int item, int index) {
	if (list == NULL) {
		printf("List doesn't exist!\n");
		return;
	}
	if (!IndexIsValid(list, index)) {
		printf("Index out of bound!\n");
		return;
	}
	
	if (list->count == 0) { // empty list
		AddItem(list, item);
	} else if (index == 0) { // head
		Node* newNode = new Node;
		newNode->data = item;
		newNode->prev = NULL;
		newNode->next = list->head;
		list->head = newNode;
	} else if (index == list->count) { // tail
		AddItem(list, item);
	} else {
		Node* curNode = list->head;
		for (int i = 0; i < index; i++) curNode = curNode->next;
		
		Node* newNode = new Node;
		newNode->data = item;
		newNode->prev = curNode->prev;
		newNode->next = curNode;
		
		curNode->prev->next = newNode;
		curNode->prev = newNode;
	}
	list->count++;
	printf("insert item %i to list at position %i\n", item, index);
}

int FindItem(LinkedList *list, int item) {
	if (list == NULL) {
		printf("List doesn't exist!\n");
		return -1;
	}
	Node* curNode = list->head;
	for (int idx = 0; idx < list->count; idx++) {
		if (curNode->data == item) return idx;
		curNode = curNode->next;
	}
	return -1; // tidak ditemukan
}

void DeleteItem(LinkedList* list, int item) {
	if (list == NULL) {
		printf("List doesn't exist!\n");
		return;
	}
	Node* curNode = list->head;
	while (curNode->data != item) {
		if (curNode->next == NULL) {
			printf("Item not found!\n");
			return;	
		}
		curNode = curNode->next;
	}
	if (curNode == list->head) {
		list->head = curNode->next;
		list->head->prev = NULL;
	} else if (curNode == list->tail) {
		list->tail = curNode->prev;
		list->tail->next = NULL;
	} else {
		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;
	}
	delete curNode;	
	list->count--;
	printf("item %d deleted from list.\n", item);
}

void DeleteItemAt(LinkedList *list, int index) {
	if (list == NULL) {
		printf("List doesn't exist!\n");
		return;
	}
	if (!IndexIsValid(list, index)) {
		printf("Index out of bound!\n");
		return;
	}
	Node* curNode = list->head;
	for (int idx = 0; idx < index; idx++) curNode = curNode->next;
	if (curNode == list->head) {
		list->head = curNode->next;
		list->head->prev = NULL;
	} else if (curNode == list->tail) {
		list->tail = curNode->prev;
		list->tail->next = NULL;
	} else {
		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;
	}
	delete curNode;
	list->count--;
	printf("item at index %i deleted from list.\n", index);
}

void DisplayListForward(LinkedList *list) {
	if (list == NULL) {
		printf("List doesn't exist!\n");
		return;
	}
	if (list->count == 0) {
		printf("List is empty!\n");
		return;
	}
	Node* curNode = list->head;
	printf("List item : ");
	for (int i = 0; i < list->count; i++) {
		if (i > 0) printf(" - ");
		printf("%d", curNode->data);
		curNode = curNode->next;
	}
	printf("\n");
}

void DisplayListBackward(LinkedList *list) {
	if (list == NULL) {
		printf("List doesn't exist!\n");
		return;
	}
	if (list->count == 0) {
		printf("List is empty!\n");
		return;
	}
	Node* curNode = list->tail;
	printf("List item : ");
	for (int i = 0; i < list->count; i++) {
		if (i > 0) printf(" - ");
		printf("%d", curNode->data);
		curNode = curNode->prev;
	}
	printf("\n");
}

void ClearList(LinkedList *list) {
	if (list == NULL) {
		printf("List doesn't exist!\n");
		return;
	}
	Node* curNode = list->head;
	for (int i = 0; i < list->count; i++) {
		Node* tmpNode = curNode->next;
		delete curNode;
		curNode = tmpNode;
	}
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
}

void DeleteList(LinkedList** list) {
	ClearList(*list);
	delete *list;
	*list = NULL;
}

int main() {
	printf("Working With Double Linked List.\n");
	printf("================================\n");
	
	LinkedList *list = NULL; 
	
	printf("List is null ? %s\n", (list == NULL ? "Ya": "Tidak"));
	
	list = CreateLinkedList();
	
	AddItem(list, 0);
	DisplayListForward(list);
	AddItem(list, 1);
	DisplayListForward(list);
	AddItem(list, 2);
	DisplayListForward(list);
	AddItem(list, 3);
	DisplayListForward(list);
	AddItem(list, 4);
	DisplayListForward(list);

//	InsertItem(list, 10, 1000);
	InsertItem(list, 100, 1);
//	InsertItem(list, 500, 5);
	
	DisplayListForward(list);
	printf("%d\n", FindItem(list, 2));
	
	bool item2ditemukan = FindItem(list, 2);
	if (item2ditemukan < 0)
		printf("item %i ditemukan.\n", 2);
	else
		printf("item %i tidak ditemukan.\n", 2);
	
	bool item99ditemukan = FindItem(list, 99);
	if (item99ditemukan < 0)
		printf("item %i ditemukan.\n", 99);
	else
		printf("item %i tidak ditemukan.\n", 99);
		
	DeleteItem(list, 100);
	DisplayListForward(list);
	DeleteItemAt(list, 1);
	DisplayListForward(list);
	DeleteItemAt(list, 0);
	DisplayListForward(list);
	DeleteItemAt(list, 0);
	DisplayListForward(list);
	
	DisplayListBackward(list);
	
	printf("Clear list.\n");
	ClearList(list);
	DisplayListForward(list);
	
	printf("Delete list.\n");
	DeleteList(&list);
	DisplayListForward(list);
	
	printf("List is null ? %s\n", (list == NULL ? "Ya": "Tidak"));
	
	return 0;	
}
