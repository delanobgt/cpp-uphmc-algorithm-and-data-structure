#include <cstdio>
#include <windows.h>

struct Node {
	int data;
	Node* prev;
	
	Node(int data) {
		this->data = data;
		this->prev = NULL;
	}
	
	Node(int data, Node* prev) {
		this->data = data;
		this->prev = prev;
	}
};

class LinkedStack {
	Node* top;
	int length;
	
	public:
		LinkedStack() {
			top = NULL;
			length = 0;
		}
	
		bool isEmpty() {
			return length == 0;	
		}
		
		int getLength() {
			return length;
		}
		
		void push(int item) {
			Node* newNode = new Node(item, top);
			top = newNode;
			length++;
		}
		
		int pop() {
			int value = top->data;
			Node* newTop = top->prev;
			delete top;
			top = newTop;
			length--;
			return value;
		}
		
		int peek() {
			return top->data;
		}
		
		void display() {
			if (length == 0) {
				printf("<empty>\n");
			} else {
				printf("[TOP]\n");
				Node* ptr = top;
				while (ptr != NULL) {
					printf("%d\n", ptr->data);
					ptr = ptr->prev;
				}
				printf("[BOTTOM]\n");
			}
		}
		
		void clear() {
			Node* ptr = top;
			while (ptr != NULL) {
				Node* nextPtr = ptr->prev;
				delete ptr;
				ptr = nextPtr;
			}
			top = NULL;
			length = 0;
		}
};

int main() {
	LinkedStack stack;
	int choice = -1;
	while (choice != 0) {
		system("cls");
		printf("Linked Stack\n");
		printf("------------\n");
		stack.display();
		printf("\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Get Length\n");
		printf("4. Clear\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		int item, index;
		switch (choice) {
			case 1:
				printf("--> Push\n");
				printf("Item: ");
				scanf("%d", &item);
				stack.push(item);
				break;
			case 2:
				printf("--> Pop\n");
				item = stack.pop();
				printf("Popped: %d\n", item);
				system("pause");
				break;
			case 3:
				printf("--> Get Length\n");
				printf("Length: %d\n", stack.getLength());
				system("pause");
				break;
			case 4:
				printf("--> Clear\n");
				stack.clear();
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

