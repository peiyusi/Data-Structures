#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxWindow 10
#define MaxTime 60

typedef struct People ElementType;
struct People {
	int T;
	int P;
};

typedef int Position;
typedef struct QNode *Queue;
struct QNode {
	ElementType *Data;
	Position Front;
	Position Rear;
	int MaxSize;	
};

bool isFull(Queue Q)
{
	return ((Q->Rear + 1) % Q->MaxSize) == Q->Front;
}

bool isEmpty(Queue Q)
{
	return Q->Front == Q->Rear;
}

Queue CreateQueue(int MaxSize)
{
	int i;
	Queue Q;
	
	Q = NULL;
	if (MaxSize) {
		Q = (Queue)malloc(sizeof(struct QNode));
		Q->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
		Q->Front = Q->Rear = -1;
		Q->MaxSize = MaxSize;
	}
	
	return Q;
}

bool Push(Queue Q, ElementType X)
{
	if (isFull(Q)) {
		return false;
	}
	Q->Rear = (Q->Rear + 1) % Q->MaxSize; 
	Q->Data[Q->Rear] = X;
	
	return true; 
}

ElementType Pop(Queue Q)
{
	if (!isEmpty(Q)) {
		Q->Front = (Q->Front + 1) % Q->MaxSize;
		return Q->Data[Q->Front];
	}
}

void DestroyQueue(Queue Q) {
	if (Q) {
		free(Q->Data);
		free(Q);
	}
}

int FindWinAvail(int Windows[], int K, int *WaitTime)
{
	int WinAvail;
	int MinW;
	int i;
	
	MinW = MaxTime + 1;
	for (i = 0; i < K; i++) {
		if (Windows[i] < MinW) {
			MinW = Windows[i];
			WinAvail = i;
		}
	}
	for (i = 0; i < K; i++) {
		Windows[i] -= MinW;
	}
	*WaitTime = MinW;
	
	return WinAvail;
}

int GetFinishedTime(int Windows[], int K, int CurrentTime)
{
	int i, LastTime;
	
	LastTime = 0;
	for (i = 0; i < K; i++) {
		if (Windows[i] > LastTime) {
			LastTime = Windows[i];
		}
	}
	
	return CurrentTime + LastTime;
}

void Print(Queue Q, int N)
{
	int Windows[MaxWindow];
	int ServiceLog[MaxWindow];
	int K, i;
	int WinAvail;
	int CurrentTime;
	int WaitTime;
	int TotalTime;
	int MaxWaitTime;
	ElementType X;
	
	scanf("%d", &K);
	if (K) {
		TotalTime = CurrentTime = MaxWaitTime = 0;;
		for (i = 0; i < K; i++) {
			Windows[i] = 0;
			ServiceLog[i] = 0;
		}
		while (!isEmpty(Q)) {
			X = Pop(Q);
			WinAvail = FindWinAvail(Windows, K, &WaitTime);
			CurrentTime += WaitTime;
			
			if (X.T <= CurrentTime) {
				WaitTime = CurrentTime - X.T;
				TotalTime += WaitTime;
				if (MaxWaitTime < WaitTime) {
					MaxWaitTime = WaitTime;
				}
			} else {
				WaitTime = X.T - CurrentTime;
				for (i = 0; i < K; i++) {
					Windows[i] -= WaitTime;
					if (Windows[i] <= 0) {
						Windows[i] = 0;
						if (WinAvail > i) {
							WinAvail = i;
						}
					}
				}
				CurrentTime = X.T;
			}
			Windows[WinAvail] = X.P;
			ServiceLog[WinAvail]++;	
		}
				
		printf("%.1f %d %d\n", (double)TotalTime / (double)N, MaxWaitTime, GetFinishedTime(Windows, K, CurrentTime));
		printf("%d", ServiceLog[0]);
		for (i = 1; i < K; i++) {
			printf(" %d", ServiceLog[i]);
		}
	}
}


int main() 
{
	//freopen("E:in.txt", "r", stdin);
	int N, i;
	Queue Q;
	ElementType X;
	
	scanf("%d", &N);
	if (N) {
		Q = CreateQueue(N);
		for (i = 0; i < N; i++) {
			scanf("%d %d", &X.T, &X.P);
			if (X.P > MaxTime) {
				X.P = MaxTime;
			}
			Push(Q, X);
		}
		Print(Q, N);;
		DestroyQueue(Q);
	}	
		
    //fclose(stdin);
    return 0;
}
 

