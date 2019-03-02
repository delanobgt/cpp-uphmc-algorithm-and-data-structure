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

class LinkedQueue {
	Node* front;
	Node* back;
	int length;
	
	public:
		LinkedQueue() {
			front = NULL;
			back = NULL;
			length = 0;
		}
	
		bool isEmpty() {
			return length == 0;	
		}
		
		int getLength() {
			return length;
		}
		
		void push(int item) {
			Node* newNode = new Node(item);
			if (isEmpty()) {
				front = newNode;
				back = newNode;
			} else {
				back->next = newNode;
				back = newNode;
			}
			length++;
		}
		
		int pop() {
			int value = front->data;
			Node* nextFront = front->next;
			delete front;
			front = nextFront;
			length--;
			if (length == 0) {
				front = NULL;
				back = NULL;
			}
			return value;
		}
		
		int peek() {
			return front->data;
		}
		
		void display() {
			if (length == 0) {
				printf("<empty>\n");
			} else {
				printf("[FRONT] ");
				Node* ptr = front;
				for (int i = 0; i < length; i++) {
					if (i > 0) printf(", ");
					printf("%d", ptr->data);
					ptr = ptr->next;
				}
				printf(" [BACK]\n");
			}
		}
		
		void clear() {
			Node* ptr = front;
			while (ptr != NULL) {
				Node* nextPtr = ptr->next;
				delete ptr;
				ptr = nextPtr;
			}
			length = 0;
		}
};

int main() {
	LinkedQueue queue;
	int choice = -1;
	while (choice != 0) {
		system("cls");
		printf("Linked Queue\n");
		printf("-----------\n");
		queue.display();
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
				queue.push(item);
				break;
			case 2:
				printf("--> Pop\n");
				item = queue.pop();
				printf("Popped: %d\n", item);
				system("pause");
				break;
			case 3:
				printf("--> Get Length\n");
				printf("Length: %d\n", queue.getLength());
				system("pause");
				break;
			case 4:
				printf("--> Clear\n");
				queue.clear();
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

