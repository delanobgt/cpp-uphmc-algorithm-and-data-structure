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
	
	Stack *s = new Stack;
	
	int pil;
	
	do {
		system("cls");
		printf("M  E  N  U [Stack dengan Array]\n");
		printf("===============================\n");
		printf("1. IsFull\n");
		printf("2. IsEmpty\n");
		printf("3. Count\n");
		printf("4. Push\n");
		printf("5. Pop\n");
		printf("6. Peek\n");
		printf("7. Display\n");
		printf("8. Clear\n");
		printf("0. Exit Program\n");
		printf("===============================\n");
		printf("? ");
		scanf("%d", &pil);
		switch (pil) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				system("cls");
				printf("your choice : 1 - 8\n");
				system("pause");
				break;
			case 0:
				system("cls");
				printf("bye bye\n");
				system("pause");
				break;
		}
	} while (pil != 0);
	
	s->Dispose();
	
	return 0;
}
