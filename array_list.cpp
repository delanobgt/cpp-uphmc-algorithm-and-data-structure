//ArrayList
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10 // konstanta

typedef struct my_list {
	int *data;
	int size;
	int capacity;
} List;

List* newList() { 
	List *list = (List *)malloc(sizeof(List));
	list->data = (int *)malloc(sizeof(int) * INITIAL_CAPACITY);
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	return list;
}

int getSize(List *list) {
	return list->size;
}

int getCapacity(List *list) {
	return list->capacity;
}

bool isValidIndex(List *list, int index) {
	return index >= 0 && index < getSize(list);
}

bool isFull(List *list) {
	return getSize(list) == getCapacity(list);
}

void deleteList(List *list) {
	free(list->data);
	free(list);
}

void growList(List *list) {
	int newCapacity = getCapacity(list) + INITIAL_CAPACITY;
	int *newData = (int *)malloc(sizeof(int) * newCapacity);
	for (int i = 0; i < getSize(list); i++)
		newData[i] = list->data[i];
	int *temp = list->data;
	list->data = newData;
	list->capacity = newCapacity;
	free(temp);
}

bool addItem(List *list, int item) {
	if (isFull(list)) 
		growList(list);
	list->data[list->size++] = item;
	return true;
}

int getItem(List *list, int index) {
	// fungsi untuk mengakses item dari list pada index tertentu 
	// index harus valid
	if (isValidIndex(list, index)) 
		return list->data[index];
	else
		return -1;
}

void setItem(List *list, int index, int item) {
	// fungsi untuk mengubah item data pada list pada index tertentu
	// index harus valid
	if (isValidIndex(list, index))
		list->data[index] = item;
}

void insertItem(List *list, int index, int item) {
	// fungsi untuk menginsert item baru pada posisi index tertentu pada list
	// index harus valid
	if (isFull(list)) 
		growList(list);
	if (index >= 0 && index <= getSize(list)) {
		if (index == getSize(list)) {
			// sisip belakang
			addItem(list, item);
		}
		else {
			// sisip tengah atau depan
			for (int i = list->size; i > index; i--) 
				list->data[i] = list->data[i-1];
			list->data[index] = item;
			list->size++;
		}
	}
}

void removeItem(List *list, int index) {
	// fungsi untuk menghapus item data dari list pada posisi index tertentu
	// index harus valid
	if (isValidIndex(list, index)) {
		for (int i = index; i < getSize(list)-1; i++)
			list->data[i] = list->data[i+1];
		list->size--;		
	}
}

void clearList(List *list) {
	// fungsi untuk mengosongkan list
	// dan mengembalikan capacity list ke initial capacity 
	//list->data = new List;
	delete[] list->data;
	list->data = (int *)malloc(sizeof(int));
	list->size = 0;
	list->capacity = 10;
}

bool findItem(List *list, int item) {
	// fungsi untuk mencari apakah item ada di dalam list atau tidak 
	for (int i = 0; i < getSize(list); i++)
		if (list->data[i] == item)
			return true;
	return false;
}

void display(List *list) {
	// fungsi untuk menampilkan isi data yang ada dalam list
	printf("List Item :\n");
	for (int i = 0; i < getSize(list); i++)
		printf("%5d ", list->data[i]);
	printf("\n");
}

int main() {
	List *myList = newList(); // create new list (capacity = 10, size = 0)
	for (int i = 1; i <= 13; i++)
		addItem(myList, i);
	printf("size of myList = %d\n", getSize(myList));
	printf("capacity of myList = %d\n", getCapacity(myList));
	printf("is myList Full ? %s\n", (isFull(myList) ? "YES" : "NO"));
	display(myList);
	printf("item pada index posisi 5 = %d\n", getItem(myList, 5));
	setItem(myList, 0, 100);
	insertItem(myList, 1, 200);
	removeItem(myList, 0);
	removeItem(myList, 0);
	display(myList);
	deleteList(myList);
	getchar();
	return 0;
}
