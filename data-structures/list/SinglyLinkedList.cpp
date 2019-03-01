#include <cstdio>
#include <windows.h>

struct Node {
	int data;
	Node* next;
	
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	
	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}
};

class LinkedList {
	Node* head;
	Node* tail;
	int length;
	
	bool isValidIndex(int index) {
		return 0 <= index && index < length;
	}
	
	bool isValidIndexPlusOne(int index) {
		return 0 <= index && index <= length;
	}
	
	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			length = 0;
		}
		
		bool addItem(int item) {
			Node* newNode = new Node(item);
			if (head == NULL) {
				head = newNode;
				tail = newNode;
			} else {
				tail->next = newNode;
				tail = newNode;
			}
			length++;
			return true;
		}
		
		bool insertItem(int index, int item) {
			if (!isValidIndexPlusOne(index)) throw "Invalid index!";
			Node* newNode = new Node(item);
			if (index == 0) {
				newNode->next = head;
				head = newNode;
			} else if (index == length) {
				addItem(item);
			} else {
				Node* ptr = head;
				for (int i = 1; i < index; i++) {
					ptr = ptr->next;
				}
				newNode->next = ptr->next;
				ptr->next = newNode;
			}
			length++;
		}
		
		bool setItem(int index, int item) {
			if (!isValidIndex(index)) throw "Invalid index!";
			Node* ptr = head;
			while (index--) {
				ptr = ptr->next;
			}
			ptr->data = item;
			return true;
		}
		
		int getItem(int index) {
			if (!isValidIndex(index)) throw "Invalid index!";
			Node* ptr = head;
			while (index--) {
				ptr = ptr->next;
			}
			return ptr->data;
		}
		
		int getLength() {
			return length;
		}
		
		int findItemIndex(int item) {
			Node* ptr = head;
			for (int i = 0; i < length; i++) {
				if (ptr->data == item) return i;
				ptr = ptr->next;
			}
			return -1;
		}
		
		bool removeItemAtIndex(int index) {
			if (!isValidIndex(index)) throw "Invalid index!";
			if (length == 1) {
				delete head;
				head = NULL;
				tail = NULL;
			} else if (index == 0) {
				Node* newHead = head->next;
				delete head;
				head = newHead;
			} else {
				Node* ptr = head;
				for (int i = 1; i < index; i++) ptr = ptr->next;
				
				Node* newNeighbor = ptr->next->next;
				delete ptr->next;
				ptr->next = newNeighbor;
				
				if (newNeighbor == NULL) {
					tail = ptr;
				}
			}
			length--;
			return true;
		}
		
		bool removeItemsByValue(int value) {
			if (head == NULL) return true;
			
			Node* pseudoNode = new Node(-1, head);
			Node* ptr = pseudoNode;
			while (ptr->next != NULL) {
				if (ptr->next->data == value) {
					if (ptr->next == head) head = ptr->next->next;
					else if (ptr->next == tail) tail = ptr;
					
					Node* newNeighbor = ptr->next->next;
					delete ptr->next;
					ptr->next = newNeighbor;
					length--;
				} else {
					ptr = ptr->next;
				}
			}
			delete pseudoNode;
			
			if (length == 0) {
				head = NULL; 
				tail = NULL;
			}
			
			return true;
		}
		
		void clear() {
			Node* ptr = head;
			while (ptr != NULL) {
				Node* nextPtr = ptr->next;
				delete ptr;
				ptr = nextPtr;
			}
			head = NULL;
			tail = NULL;
			length = 0;
		}
		
		void display() {
			if (length == 0) {
				printf("<empty>\n");
			} else {
				Node* ptr = head;
				for (int i = 0; i < length; i++) {
					if (i > 0) printf(", ");
					printf("%d", ptr->data);
					ptr = ptr->next;
				}
			}
			printf("\n");
		}
};

int main() {
	LinkedList list;
	int choice = -1;
	while (choice != 0) {
		system("cls");
		printf("Singly Linked List\n");
		printf("------------------\n");
		list.display();
		printf("\n");
		printf("1. Add Item\n");
		printf("2. Insert Item\n");
		printf("3. Set Item\n");
		printf("4. Get Item\n");
		printf("5. Get Length\n");
		printf("6. Find Item Index\n");
		printf("7. Remove Item At Index\n");
		printf("8. Remove All Items By Value\n");
		printf("9. Clear\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		int item, index;
		switch (choice) {
			case 1:
				printf("--> Add Item\n");
				printf("Item: ");
				scanf("%d", &item);
				list.addItem(item);
				break;
			case 2:
				printf("--> Insert Item\n");
				printf("Index: ");
				scanf("%d", &index);
				printf("Item: ");
				scanf("%d", &item);
				list.insertItem(index, item);
				break;
			case 3:
				printf("--> Set Item\n");
				printf("Index: ");
				scanf("%d", &index);
				printf("Item: ");
				scanf("%d", &item);
				list.setItem(index, item);
				break;
			case 4:
				printf("--> Get Item\n");
				printf("Index: ");
				scanf("%d", &index);
				printf("Item at index %d: %d\n", index, list.getItem(index));
				system("pause");
				break;
			case 5:
				printf("--> Get Length\n");
				printf("Length: %d\n", list.getLength());
				system("pause");
				break;
			case 6:
				printf("--> Find Item Index\n");
				printf("Item: ");
				scanf("%d", &item);
				index = list.findItemIndex(item);
				if (index != -1) {
					printf("Found %d at index %d\n", item, list.findItemIndex(item));	
				} else {
					printf("Item not found!");
				}
				system("pause");
				break;
			case 7:
				printf("--> Remove Item At Index\n");
				printf("Index: ");
				scanf("%d", &index);
				list.removeItemAtIndex(index);
				break;
			case 8:
				printf("--> Remove All Items By Value\n");
				printf("Item: ");
				scanf("%d", &index);
				list.removeItemsByValue(index);
				break;
			case 9:
				printf("--> Clear\n");
				list.clear();
				break;
			case 0:
				printf("Exiting..\n");
				break;
			default:
				printf("Invalid choice!");
				system("pause");
				break;
		}
	}
	return 0;	
}
