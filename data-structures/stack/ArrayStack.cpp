#include <stdio.h>
#include <stdlib.h>

const int MAX = 100;

class ArrayStack {
	int* data;
	int length;
	int capacity;
	static const int INITIAL_CAPACITY = 8;
	
	void growList() {
		capacity = capacity * 2;
		int* newData = new int[capacity];
		for (int i = 0; i < length; i++) newData[i] = data[i];
		delete[] data;
		data = newData;
	}
	
	bool isFull() {
		return length == capacity;
	}
	
	public:
		ArrayStack() {
			data = new int[INITIAL_CAPACITY];
			length = 0;
			capacity = INITIAL_CAPACITY;
		}
	
		bool isEmpty() {
			return length == 0;	
		}
		
		int getLength() {
			return length;
		}
		
		void push(int item) {
			
		}
		
		int pop() {
			
		}
		
		int peek() {
			
		}
		
		void display() {
			
		}
		
		void clear() {
			
		}
};

int main() {
	ArrayStack stack;
	int choice = -1;
	while (choice != 0) {
		system("cls");
		printf("Array List\n");
		printf("----------\n");
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
				int popped = stack.pop();
				printf("Popped: %d\n", popped);
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

