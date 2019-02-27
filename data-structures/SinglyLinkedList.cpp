#define INF 1000000007
#include <cstdio>
#include <windows.h>

struct Node {
	int data;
	Node *next;
};

class LinkedList {
	Node *head;
	Node *tail;
	int length;
	
	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			length = 0;
		}
		
		void addItem(int item) {
			Node *newNode = new Node;
			newNode->data = item;
			newNode->next = NULL;
			if (head == NULL) {
				head = newNode;
				tail = newNode;
			} else {
				tail->next = newNode;
				tail = newNode;
			}
			length++;
		}
		
		void display() {
			printf("Display:\n");
			Node* ptr = head;
			for (int i = 0; i < length; i++) {
				if (i > 0) printf(", ");
				printf("%d", ptr->data);	
				ptr = ptr->next;
			}
			while (ptr != NULL) {
				printf("%5i ", ptr->data);
				ptr = ptr->next;
			}
			printf("\n");
		}
		
		int getLength() {
			return length;
		}
		
		bool findItem(int item) {
			if (list != NULL && list->head != NULL) {
				Node *ptr = list->head;
				while (ptr != NULL) {
					if (ptr->data == item) return true;
					ptr = ptr->next;
				}
			}
			return false;
		}
		
		void insertItem(LinkedList *list, int index, int item) {
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
};

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
