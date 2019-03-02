#include <cstdio>
#include <windows.h>

class ArrayQueue {
	int* data;
	int frontPtr;
	int backPtr;
	int length;
	int capacity;
	static const int INITIAL_CAPACITY = 8;
	
	void growList() {
		capacity = capacity * 2;
		int* newData = new int[capacity];
		for (int i = frontPtr; i < (backPtr-frontPtr) + 1; i++) 
			newData[i-frontPtr] = data[i];
		delete[] data;
		data = newData;
		frontPtr = 0;
		backPtr = length-1;
	}
	
	void shiftList() {
		for (int i = frontPtr; i < (backPtr-frontPtr) + 1; i++) 
			data[i-frontPtr] = data[i];
		frontPtr = 0;
		backPtr = length-1;
	}
	
	bool isBackPtrOnEnd() {
		return backPtr == capacity-1;
	}
	
	public:
		ArrayQueue() {
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
			if (isEmpty()) {
				frontPtr = 0;
				data[backPtr = 0] = item;
			} else {
				if (isBackPtrOnEnd()) {
					if (length <= capacity/2) {
						shiftList();
					} else {
						growList();
					}
				}
				data[++backPtr] = item;
			}
			length++;
		}
		
		int pop() {
			if (isEmpty()) throw "Queue is empty!";
			int value = data[frontPtr++];
			length--;
			return value;
		}
		
		int front() {
			return data[frontPtr];
		}
		
		void display() {
			if (length == 0) {
				printf("<empty>\n");
			} else {
				printf("[FRONT] ");
				for (int i = frontPtr; i <= backPtr; i++) {
					if (i-frontPtr > 0) printf(", ");
					printf("%d", data[i]);
				}
				printf(" [BACK]\n");
			}
		}
		
		void clear() {
			delete[] data;
			data = new int[INITIAL_CAPACITY];
			length = 0;
			capacity = INITIAL_CAPACITY;
		}
};

int main() {
	ArrayQueue queue;
	int choice = -1;
	while (choice != 0) {
		system("cls");
		printf("Array Queue\n");
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

