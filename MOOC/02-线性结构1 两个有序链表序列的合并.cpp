#include <stdio.h>
#include <stdilib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

int data1[] = {1, 3, 5};
int data2[] = {2, 4, 6, 8, 10}; 

List Read() {
	
}

void Print( List L ) {
	L = L->Next;
	if (L == NULL) {
		printf("NULL");
	}
    while (L != NULL) {
    	printf("%d ", L->Data);
    	L = L->Next;
	}
	printf("\n");	
}

List Merge( List L1, List L2 ) {
	List Temp1 = L1->Next;
	List Temp2 = L2->Next;
	List P;
	P = (List)malloc(sizeof(List));
	List Temp = P;
	
	while (Temp1 && Temp2) {
		if (Temp1->Data < Temp2->Data) {
			Temp->Next = Temp1;
			Temp1 = Temp1->Next;
			Temp = Temp->Next; 
		} else {
			Temp->Next = Temp2;
			Temp2 = Temp2->Next;
			Temp = Temp->Next;
		}
	}
	
	while (Temp1 != NULL) {
		Temp->Next = Temp1;
		Temp1 = Temp1->Next;
		Temp = Temp->Next;
	}
	
	while (Temp2 != NULL) {
		Temp->Next = Temp2;
		Temp2 = Temp2->Next;
		Temp = Temp->Next;
	}

	L1->Next = NULL;
	L2->Next = NULL;
	Temp->Next = NULL;
	
	return P;

}
