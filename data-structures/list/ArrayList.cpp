#include <cstdio>
#include <windows.h>

class ArrayList {
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
	
	bool isValidIndex(int index) {
		return 0 <= index && index < length;
	}
	
	bool isValidIndexPlusOne(int index) {
		return 0 <= index && index <= length;
	}
	
	public:
		ArrayList() {
			data = new int[INITIAL_CAPACITY];
			length = 0;
			capacity = INITIAL_CAPACITY;
		}
		
		bool addItem(int item) {
			if (isFull()) growList();
			data[length++] = item;
			return true;
		}
		
		bool insertItem(int index, int item) {
			if (!isValidIndexPlusOne(index)) throw "Invalid index!";
			if (isFull()) growList();
			for (int i = length; i > index; i--) 
				data[i] = data[i-1];
			data[index] = item;
			length++;
		}
		
		bool setItem(int index, int item) {
			if (!isValidIndex(index)) throw "Invalid index!";
			data[index] = item;
			return true;
		}
		
		int getItem(int index) {
			if (!isValidIndex(index)) throw "Invalid index!";
			return data[index];
		}
		
		int getLength() {
			return length;
		}
		
		int findItemIndex(int item) {
			for (int i = 0; i < length; i++)
				if (data[i] == item) return i;
			return -1;
		}
		
		bool removeItemAtIndex(int index) {
			if (!isValidIndex(index)) throw "Invalid index!";
			for (int i = index; i < length-1; i++)
				data[i] = data[i+1];
			length--;
			return true;
		}
		
		bool removeItemsByValue(int value) {
			int a = 0, b = 0;
			while (a < length && b < length) {
				if (data[a] != value) {
					a++;
				} else if (b < a || data[b] == value) {
					b++;
				} else  {
					int tmp = data[a];
					data[a] = data[b];
					data[b] = tmp;
					a++; b++;
				}
			}
			length = a;
			return true;
		}
		
		void clear() {
			delete[] data;
			data = new int[INITIAL_CAPACITY];
			length = 0;
			capacity = INITIAL_CAPACITY;
		}
		
		void display() {
			if (length == 0) {
				printf("<empty>\n");
			} else {
				for (int i = 0; i < length; i++) {
					if (i > 0) printf(", ");
					printf("%d", data[i]);
				}
			}
			printf("\n");
		}
};

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
