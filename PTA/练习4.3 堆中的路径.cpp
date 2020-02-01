#include <stdio.h>
#include <stdlib.h>

#define MAXCAPACITY 1001
#define MIN -32767
typedef int ElementType;
typedef struct HNode *MinHeap;
struct HNode {
	ElementType *Data;
	int Size;
};
 
void Insert(MinHeap H, ElementType X)
{
	int i;
	
	i = ++H->Size;
	for (; H->Data[i / 2] > X; i /= 2) {
		H->Data[i] = H->Data[i / 2];
	}
	H->Data[i] = X;
}

MinHeap BuildHeap(int N)
{
	MinHeap H;
	ElementType Data;
	
	H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType *)malloc(MAXCAPACITY * sizeof(ElementType));
	H->Data[0] = MIN, H->Size = 0; 
	
	while (N--) {
		scanf("%d", &Data);
		Insert(H, Data);
	}
	
	return H;
}

void PrintPath(MinHeap H, int Index)
{
	int flag = 0;
	for (; Index > 0; Index /= 2) {
		if (!flag) {
			printf("%d", H->Data[Index]);
			flag = 1;
		} else {
			printf(" %d", H->Data[Index]);
		}
	}
	printf("\n");
}


int main()
{
	//freopen("E:in.txt", "r", stdin);
	int N, M, Index;
	MinHeap H;
	
	scanf("%d %d", &N, &M);
	if (N) {
		H = BuildHeap(N);	
		while (M--) {
			scanf("%d", &Index);
			PrintPath(H, Index);
		}
	}

	//fclose(stdin);
	return 0;
}
