#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct aNode {
    int data;
    aNode* prev;
    aNode* next;
} Node;

typedef struct aList {
    Node* head;
    Node* tail;
    char mode[80];
    
    aList(char* jenisPengurutan) {
        head = NULL;
        tail = NULL;
        strcpy(mode, jenisPengurutan);
    }
    
    void AddItem(int item) {
	    // ubah disesuaikan dengan permintaan soal
	    Node* newNode = new Node;
	    newNode->data = item;
	    newNode->next = NULL;
		newNode->prev = NULL;
	    
	    if (head == NULL) {
	    	head = newNode;
	    	tail = newNode;
	    	return;
		}
	    
	    Node* ptr = head;
	    while (true) {
//	    	ASC & DESC
//	    	if (ptr == NULL || (strcmp(mode, "ASC") == 0 && ptr->data > item) || (strcmp(mode, "DESC") == 0 && ptr->data < item)) {

//			ASC
//	    	if (ptr == NULL || ptr->data > item) {

//			DESC
	    	if (ptr == NULL || ptr->data < item) { 
	    		if (ptr == NULL) {
	    			tail->next = newNode;
	    			newNode->prev = tail;
	    			tail = newNode;
				} else if (ptr == head) {
					newNode->next = head;
					head->prev = newNode;
			        head = newNode;
			    } else {
			    	newNode->prev = ptr->prev;
			        newNode->next = ptr;
			        ptr->prev->next = newNode;
			        ptr->prev = newNode;
			    }
			    return;
			}
			ptr = ptr->next;
		}
	}
	
	void AddRange(int item[], int n) {
	    for (int i = 0; i < n; i++)
	        AddItem(item[i]);
	}
	
	int Sum() {
		int sum = 0;
	    Node* ptr = head;
	    while (ptr != NULL) {
	    	sum += ptr->data;
	    	ptr = ptr->next;
		}
	    return sum;
	}
	int Count() {
	    int count = 0;
	    Node* ptr = head;
	    while (ptr != NULL) {
	    	count++;
	    	ptr = ptr->next;
		}
	    return count;
	}
	
	int GetItemTerkecil() {
		int minim = head->data;
	    Node* ptr = head->next;
	    while (ptr != NULL) {
	    	if (ptr->data < minim) minim = ptr->data;
	    	ptr = ptr->next;
		}
	    return minim;
	}
	
	int GetItemTerbesar() {
	    int maxim = head->data;
	    Node* ptr = head->next;
	    while (ptr != NULL) {
	    	if (ptr->data > maxim) maxim = ptr->data;
	    	ptr = ptr->next;
		}
	    return maxim;
	}
    
    void Display() {
        if (head == NULL)
            printf("List is empty ...\n");
        else {
            printf("List Item [%s] :\n", mode);
            Node* p = head;
            while (p != NULL) {
                printf("%d ", p->data);
                p = p->next;
            }
            printf("\n");
        }
    }
    
    void Dispose() {
        if (head != NULL) {
            Node* p = head;
            head = NULL;
            tail = NULL;
            while (p != NULL) {
                Node* q = p->next;
                if (q != NULL)
                    q->prev = NULL;
                p->next = NULL;
                delete p;
                p = q;
            }
        }
    }
} OrderedList;

int* RandomData(int n) {
    int* data = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int x = rand() % 100 + 1;
        data[i] = x;
    }
    return data;
}

int main() {
    int n = 15;
    int* data = RandomData(n);
//    OrderedList* list = new OrderedList("ASC");
    OrderedList* list = new OrderedList("DESC");
    list->AddRange(data, n);
    list->Display();
    printf("Banyak Data = %d\n", list->Count());
    printf("Jumlah Dari Keseluruhan Data = %d\n", list->Sum());
    printf("Item Terkecil = %d\n", list->GetItemTerkecil());
    printf("Item Terbesar = %d\n", list->GetItemTerbesar());
    list->Dispose();
    return 0;
}

