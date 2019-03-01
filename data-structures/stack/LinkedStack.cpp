#include <stdio.h>
#include <stdlib.h>

const int MAX = 100;

typedef struct List {
	
	int *data;
	int count;
	
	void CreateNewStack() {
		
	}
	
	int Count() {
		
	}
	
	bool IsFull() {
		
	}
	
	bool IsEmpty() {
		
	}
	
	void Push(int item) {
		
	}
	
	int Pop() {
		
	}
	
	int Peek() {
		
	}
	
	void Display() {
		
	}
	
	void Clear() {
		
	}
	
	void Dispose() {
		
	}
	
} Stack;

int main() {
	ArrayList list;
	int choice = -1;
	while (choice != 0) {
		system("cls");
		printf("Array List\n");
		printf("----------\n");
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
