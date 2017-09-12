
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

ElementType data1[] = {1, 3, 5};
ElementType data2[] = {2, 4, 6, 8, 10}; 

List Read() {
	static int state = 0;
	ElementType *data, size;
	List P = (List)malloc(sizeof(List));
	List Head = P;
	P->Next = NULL;
	
	if (state == 0) {
		data = data1;
		size = sizeof(data1) / sizeof(ElementType);
	} else {
		data = data2;
		size = sizeof(data2) / sizeof(ElementType);
	}
	
	for (int i = 0; i < size; i++) {
	    P->Next = (List)malloc(sizeof(List));
	    P = P->Next;
	    P->Data = data[i];
	    P->Next = NULL;
	}
	
	state++;
	return Head;
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

int main() {
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    Print(L1);
    Print(L2);
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
