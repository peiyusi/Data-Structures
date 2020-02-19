#include <stdio.h>
#include <stdlib.h>

typedef struct LNode *PtrToLNode;
struct LNode {
	int Data;
	PtrToLNode Next;
};

void Merge(int A[], int TmpArr[], int Left, int Right, int RightEnd)
{
	int Len, i, ALen, LeftEnd;
	
	ALen = RightEnd - Left + 1, Len = Left, LeftEnd = Right - 1;
	while (Left <= LeftEnd && Right <= RightEnd) {
		if (A[Left] < A[Right]) {
			TmpArr[Len++] = A[Left++];
		} else {
			TmpArr[Len++] = A[Right++];
		}
	}
	while (Left <= LeftEnd) {
		TmpArr[Len++] = A[Left++];
	}
	while (Right <= RightEnd) {
		TmpArr[Len++] = A[Right++];
	}
	for (i = 0; i < ALen; i++, RightEnd--) {
		A[RightEnd] = TmpArr[RightEnd];
	} 
}

void MSort(int A[], int TmpArr[], int Left, int Right)
{
	int Center;
	
	if (Left < Right) {
		Center = (Left + Right) / 2;
		MSort(A, TmpArr, Left, Center);
		MSort(A, TmpArr, Center + 1, Right);
		Merge(A, TmpArr, Left, Center + 1, Right);
	}
}

void MergeSort(int A[], int N) 
{
	int *TmpArr;
	
	if (N <= 0 || !A) {
		return;
	}
	TmpArr = (int *)malloc(sizeof(int) * N);
	
	if (TmpArr) {
		MSort(A, TmpArr, 0, N - 1);	
		free(TmpArr);
	} else {
		printf("No space\n");
	}
}

//LinkList MergeSort
PtrToLNode CreateNode(int Data) {
	PtrToLNode Node = (PtrToLNode)malloc(sizeof(struct LNode));
	Node->Data = Data;
	Node->Next = NULL;
	
	return Node;
}

void DestroyList(PtrToLNode Head) {
	if (Head) {
		PtrToLNode Temp;
		Temp = Head;
		Head = Head->Next;
		free(Head);
	}
}

PtrToLNode L_Merge(PtrToLNode L1, PtrToLNode L2)
{
	PtrToLNode Head, P;
	
	Head = (PtrToLNode)malloc(sizeof(struct LNode));
	Head->Next = NULL;
	P = Head;
	while (L1 && L2) {
		if (L1->Data < L2->Data) {
			P->Next = L1;
			L1 = L1->Next;
		} else {
			P->Next = L2;
			L2 = L2->Next;
		}
		P = P->Next;
	}

	if (L1) {
		P->Next = L1;
	}
	if (L2) {
		P->Next = L2;
	}
	
	return Head->Next;
}

PtrToLNode L_MergeSort(PtrToLNode Head)
{
	PtrToLNode Pre, Slow, Fast;
	
	if (!Head || !Head->Next) {
		return Head; 
	}
	
	Pre = Slow = Fast = Head;
	while (Fast && Fast->Next) {
		Pre = Slow;
		Slow = Slow->Next;
		Fast = Fast->Next->Next;
	}
	Pre->Next = NULL;
	
	return L_Merge(L_MergeSort(Head), L_MergeSort(Slow));
}

void L_Iterate(PtrToLNode Head) {
	while (Head) {
		printf("%d ", Head->Data);
		Head = Head->Next;
	}
}

void Iterate(int A[], int N)
{
	int i;
	
	if (N <= 0 || !A) {
		return;
	}
	for (i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
}

int main()
{
	int A[10] = {23, 2, 5, 10, 40, 50, 12, 12, 2, 1}, i;
	PtrToLNode Head, P;
	
	Head = CreateNode(-999);
	P = Head;
	for (i = 0; i < 10; i++) {
		P->Next = CreateNode(A[i]);
		P = P->Next;
	}
	
	printf("Sort LinkList\n");
	printf("Before\n");
	L_Iterate(Head->Next);
	Head->Next = L_MergeSort(Head->Next);
	printf("\nAfter\n");
	L_Iterate(Head->Next);
	printf("\n--------------------------\n");
	printf("Sort Array\n");
	printf("Before\n");
	Iterate(A, 10);
	MergeSort(A, 10);
	printf("\nAfter\n");
	Iterate(A, 10);
	
	DestroyList(Head);
	
	return 0;
}
