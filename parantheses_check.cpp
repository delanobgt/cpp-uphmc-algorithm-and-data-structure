#include <stdio.h>
#include <stdlib.h>
#include <cstring>

const int MAX = 100;

struct Stack {
	char* data;
	int count;
	
	Stack() {
		data = new char[MAX];
		count = 0;
	}
	
	char length() {
		return count;
	}
	
	bool is_full() {
		return count == MAX;
	}
	
	bool is_empty() {
		return count == 0;
	}
	
	void push(char item) {
		data[count++] = item;
	}
	
	char pop() {
		return data[--count];
	}
	
	char peek() {
		return data[count-1];
	}
	
	void display() {
		for (int i = count - 1; i >= 0; i--) {
			printf("%5d\n", data[i]);
		}
	}
	
	void clear() {
		count = 0;
	}
	
	void dispose() {
		delete[] data;
		clear();
	}
};

bool check_parantheses(char expression[]) {
	Stack s;
	for (int i = 0; i < strlen(expression); i++) {
		if (expression[i] == '(') {
			s.push(expression[i]);
		} else if (expression[i] == ')') {
			if (!s.is_empty() && s.peek() == '(') s.pop(); 
			else return false;
		}
	}
	return s.is_empty();
}

int main() {
	char expression[MAX];
	scanf("%s", expression);
	
	printf("%s %s\n", expression, check_parantheses(expression) ? "VALID" : "TIDAK VALID");
	
	return 0;
}
