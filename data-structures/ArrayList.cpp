#define INF 1000000007
#include <cstdio>

class ArrayList {
	int* data;
	int length;
	int capacity;
	static const int INITIAL_CAPACITY = 8;
	
	void growList() {
		capacity = capacity * 2;
		int *newData = new int[capacity];
		for (int i = 0; i < length; i++) newData[i] = data[i];
		delete[] data;
		data = newData;
	}
	
	public: 
		ArrayList() {
			data = new int[INITIAL_CAPACITY];
			length = 0;
			capacity = INITIAL_CAPACITY;
		}
		
		int getLength() {
			return length;
		}
		
		int getCapacity() {
			return capacity;
		}
		
		bool isValidIndex(int index) {
			return 0 <= index && index < length;
		}
		
		bool isValidIndexPlusOne(int index) {
			return 0 <= index && index <= length;
		}
		
		bool isFull() {
			return length == capacity;
		}
		
		bool addItem(int item) {
			if (isFull()) growList();
			data[length++] = item;
			return true;
		}
		
		int getItem(int index) {
			if (!isValidIndex(index)) return INF;
			return data[index];
		}
		
		bool setItem(int index, int item) {
			if (!isValidIndex(index)) return false;
			data[index] = item;
			return true;
		}
		
		bool insertItem(int index, int item) {
			if (!isValidIndexPlusOne(index)) return false;
			if (isFull()) growList();
			for (int i = length; i > index; i--) 
				data[i] = data[i-1];
			data[index] = item;
			length++;
		}
		
		bool removeItem(int index) {
			if (!isValidIndex(index)) return false;
			for (int i = index; i < length-1; i++)
				data[i] = data[i+1];
			length--;
			return true;
		}
		
		void deleteList() {
			delete[] data;
		}
		
		void clearList() {
			delete[] data;
			data = new int[INITIAL_CAPACITY];
			length = 0;
			capacity = INITIAL_CAPACITY;
		}
		
		int findItemIndex(int item) {
			for (int i = 0; i < length; i++)
				if (data[i] == item) return i;
			return -1;
		}
		
		void display() {
			printf("Display:\n");
			for (int i = 0; i < length; i++) {
				if (i > 0) printf(", ");
				printf("%d", data[i]);
			}
			printf("\n");
		}
};

int main() {
	printf("Array List\n");
	while (true) {
		
	}
	return 0;
}
