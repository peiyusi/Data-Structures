#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Cutoff 5
typedef int ElementType;

typedef struct LNode *List;
struct LNode {
	ElementType *Data;
	int Size;
};

void Swap(List L, int X, int Y)
{
	ElementType Temp;
	
	Temp = L->Data[X], L->Data[X] = L->Data[Y], L->Data[Y] = Temp;
}

void InsertionSort(List L)
{
	int i, j, Temp;
	
	for (i = 1; i < L->Size; i++) { 
		Temp = L->Data[i];
		for (j = i; j > 0 && L->Data[j - 1] > Temp; j--) {
			L->Data[j] = L->Data[j - 1];
		}
		L->Data[j] = Temp;
	}
}

int Median3(List L, int Left, int Right)
{
	int Center;
	
	if (L) {
		Center = (Left + Right) / 2;
		if (L->Data[Left] > L->Data[Center]) {
			Swap(L, Left, Center);
		}
		if (L->Data[Left] > L->Data[Right]) {
			Swap(L, Left, Right);
		}
		if (L->Data[Center] > L->Data[Right]) {
			Swap(L, Center, Right); 
		}	
	}
	
	return L->Data[Center];
}

void QuickSort(List L, int Left, int Right)
{
	int i, j, X, Temp;
	
	if (L) {
		if (Left >= Right) {
			return;
		} 
		if (Cutoff <= Right - Left) {
			i = Left, j = Right;
			//	X = Median3(L, Left, Right);
			X = L->Data[(Left + Right) / 2];
			while (i <= j) {
				while (L->Data[i] < X) i++;
				while (L->Data[j] > X) j--;
				if (i <= j) {
					Swap(L, i++, j--);
				}
			}
			QuickSort(L, Left, j);
			QuickSort(L, i, Right);
		} else {
			InsertionSort(L->Data + Left, Right - Left + 1);
		}
	}
} 

void Perc_Down(ElementType Data[], int P, int N)
{
	int Parent, Child;
	ElementType X; 
	
	X = Data[P];
	for (Parent = P; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if (Child != N - 1 && Data[Child] < Data[Child + 1]) {
			Child++;
		}
		if (X < Data[Child]) {
			Data[Parent] = Data[Child];
		} else {
			break;
		}
	}
	Data[Parent] = X;	
}

void HeapSort(List L)
{
	int i;
	
	for (i = L->Size / 2 - 1; i >= 0; i--) {
		Perc_Down(L->Data, i, L->Size);
	}
	for (i = L->Size - 1; i > 0; i--) {
		Swap(L, 0, i);
		Perc_Down(L->Data, 0, i); 
	}
}

void BubbleSort(List L)
{
	int i, j;
	bool flag;
	
	for (i = L->Size - 1; i >= 0; i--) {
		flag = false;
		for (j = 0; j < i; j++) {
			if (L->Data[j] > L->Data[j + 1]) {
				Swap(L, j, j + 1);
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}	
} 

void SimpleSelectionSort(List L)
{
	int min, i, j;
	
	for (i = 0; i < L->Size - 1; i++) {
		min = i;
		for (j = i + 1; j < L->Size; j++) {
			if (L->Data[j] < L->Data[min]) {
				min = j;
			}
		}
		Swap(L, i, min);
	}
}

void Sort(List L)
{
	if (L) {
		InsertionSort(L);
	}
}

List Read()
{
	List L;
	int N, i;
	
	L = NULL;
	scanf("%d", &N);
	if (N) {
		L = (List)malloc(sizeof(struct LNode));
		L->Size = N;
		L->Data = (ElementType *)malloc(sizeof(ElementType) * N); 
		for (i = 0; i < N; i++) {
			scanf("%d", &L->Data[i]);
		}
	}
	
	return L;
}

void Print(List L)
{
	int i, flag;
	
	if (L) {
		flag = 0;
		for (i = 0; i < L->Size; i++) {
			if (!flag) {
				printf("%d", L->Data[i]);	
				flag = 1;
			} else {
				printf(" %d", L->Data[i]);	
			}
		}	
	}
}

int main()
{
	freopen("E:in.txt", "r", stdin);
	List L;
	
	L = Read();
	Sort(L);
	Print(L);
	free(L->Data);
	free(L); 
	fclose(stdin);
	return 0;
}
