#include <cstdio>
#include <windows.h>

struct Node {
	int data;
	Node* prev;
	Node* next;
	
	Node(int data) {
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
	
	Node(int data, Node* prev, Node* next) {
		this->data = data;
		this->prev = prev;
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
				newNode->prev = tail;
				tail = newNode;
			}
			length++;
			return true;
		}
		
		bool insertItem(int index, int item) {
			if (!isValidIndexPlusOne(index)) throw "Invalid index!";
			
			if (length == 0 || index == length) {
				return addItem(item);
			}
			
			Node* newNode = new Node(item);
			if (index == 0) {
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			} else {
				Node* ptr = head;
				for (int i = 0; i < index; i++) ptr = ptr->next;
				newNode->prev = ptr->prev;
				newNode->next = ptr;
				ptr->prev->next = newNode;
				ptr->prev = newNode;
			}
			length++;
			return true;
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
			} else if (index == length-1) {
				Node* newTail = tail->prev;
				delete tail;
				tail = newTail;
			} else {
				Node* ptr = head;
				for (int i = 0; i < index; i++) ptr = ptr->next;
				
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				delete ptr;
			}
			length--;
			return true;
		}
		
		bool removeItemsByValue(int value) {
			if (head == NULL) return true;
			
			Node* ptr = head;
			while (ptr != NULL) {
				if (ptr->data == value) {
					if (ptr == head) {
						head = head->next;
						delete ptr;
						ptr = head;
					} else if (ptr == tail) {
						tail = tail->prev;
						delete ptr;
						ptr = NULL;
					} else {
						Node* newPtr = ptr->next;
						ptr->prev->next = ptr->next;
						ptr->next->prev = ptr->prev;
						delete ptr;
						ptr = newPtr;
					}
					length--;
				} else {
					ptr = ptr->next;
				}
			}
			
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
		
		void displayReversed() {
			if (length == 0) {
				printf("<empty>\n");
			} else {
				Node* ptr = tail;
				for (int i = 0; i < length; i++) {
					if (i > 0) printf(", ");
					printf("%d", ptr->data);
					ptr = ptr->prev;
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
		printf("Doubly Linked List\n");
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
		printf("9. Display Reversed\n");
		printf("10. Clear\n");
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
				printf("--> Display Reversed\n");
				list.displayReversed();
				system("pause");
				break;
			case 10:
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
