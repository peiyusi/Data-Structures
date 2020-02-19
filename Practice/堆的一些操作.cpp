#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#define MAXDATA 32767;
typedef int ElementType;
typedef struct HNode *MaxHeap;
typedef struct HNode *MinHeap;
struct HNode {
	ElementType *Data;
	int Size;
	int Capacity;
}; 

bool isFull(MaxHeap H)
{
	return H->Size == H->Capacity;
}

bool isEmpty(MaxHeap H) 
{
	return H->Size == 0;
}
 
bool Insert(MaxHeap H, ElementType X)
{
	if (isFull(H)) {
		printf("MaxHeap is Full\n");
		return false;
	} else {
		int i = ++H->Size;
		for (; H->Data[i / 2] < X; i /= 2) {
			H->Data[i] = H->Data[i / 2];
		}
		H->Data[i] = X;
		return true;
	}
}

ElementType Delete(MaxHeap H)
{
	int Parent, Child;
	ElementType MaxItem, X;
	
	if (isEmpty(H)) {
		printf("MaxHeap is Empty\n");
		return MAXDATA;
	}
		
	MaxItem = H->Data[1];
	X = H->Data[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if (Child != H->Size && H->Data[Child] < H->Data[Child + 1]) {
			Child++;
		}
		if (X < H->Data[Child]) {
			H->Data[Parent] = H->Data[Child];
		} else {
			break;			
		}
	}
	H->Data[Parent] = X;
	
	return MaxItem;
}

void PercDown(MaxHeap H, int i) 
{
	int Parent, Child;
	ElementType	X;
	
	X = H->Data[i];
	for (Parent = i; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if (Child != H->Size && H->Data[Child] < H->Data[Child + 1]) {
			Child++;
		}
		if (X < H->Data[Child]) {
			H->Data[Parent] = H->Data[Child];
		} else {
			break;
		}
	}
	H->Data[Parent] = X;
}

MaxHeap BuildHeap()
{
	MaxHeap H = NULL;
	int N, Data, i;
	scanf("%d", &N);
	if (N) {
		H = (MaxHeap)malloc(sizeof(struct HNode));
		H->Size = 0, H->Capacity = N;
		H->Data = (ElementType *)malloc((N + 1) * sizeof(ElementType));
		H->Data[0] = MAXDATA;
		for (i = 0; i < N; i++) {
			scanf("%d", &Data);
			H->Data[++H->Size] = Data;
		}
		for (i = H->Size / 2; i > 0; i--) {
			PercDown(H, i);
		}
	}
	
	return H;
}



int main()
{
	freopen("E:in.txt", "r", stdin);
	

	fclose(stdin);
	
	return 0;
}
