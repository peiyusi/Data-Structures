#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxWindow 10
#define MaxTime 60
#define EmptyQ -1

typedef struct People ElementType;
struct People {
	int T;
	int P;
	int V; 
};

typedef int Position;
typedef struct QNode *Queue;
struct QNode {
	ElementType *Data;
	Position Front;
	Position Rear;
	int MaxSize;
	
	int *VIPData;
	int VIPSize;
	Position VIPFront;
	Position VIPRear;	
};

bool isFull(Queue Q);
bool isEmpty(Queue Q);
ElementType Pop(Queue Q);
bool Push(Queue Q, ElementType X);
Queue CreateQueue(int MaxSize);
void DestroyQueue(Queue Q);
bool VIPIsEmpty(Queue Q);
void VIPPush(Queue Q, Position X);
ElementType VIPPop(Queue Q);
bool VIPIsHere(Queue Q, int CurrentTime);
int GetFinishedTime(int Windows[], int K, int CurrentTime);
int FindWinAvail(int Windows[], int K, int *WaitTime);
void Print(Queue Q, int N);

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
			scanf("%d %d %d", &X.T, &X.P, &X.V);
			if (X.P > MaxTime) {
				X.P = MaxTime;
			}
			Push(Q, X);
		}
		Print(Q, N);
		DestroyQueue(Q);
	}	
		
    //fclose(stdin);
    return 0;
}
 
bool VIPIsEmpty(Queue Q)
{
	return Q->VIPSize == 0;
}

void VIPPush(Queue Q, Position X)
{
	Q->VIPData[Q->VIPRear++] = X;
	Q->VIPSize++;
}

ElementType VIPPop(Queue Q)
{
	ElementType X;
	Position P;
	
	P = Q->VIPData[Q->VIPFront++];
	X = Q->Data[P];
	Q->Data[P].V = -1;
	Q->VIPSize--;
	
	return X;
}

bool VIPIsHere(Queue Q, int CurrentTime)
{
	Position P;
	
	if (VIPIsEmpty(Q)) {
		return false;
	} else {
		P = Q->VIPData[Q->VIPFront];
		if (Q->Data[P].T <= CurrentTime) {
			return true;
		} else {
			return false;
		}
	}
}

bool isEmpty(Queue Q)
{
	return Q->Front == Q->Rear;
}

ElementType Pop(Queue Q)
{
	ElementType X;
	
	while (Q->Data[Q->Front].V == -1) {
		Q->Front++; 
	} //ÕæÕýÉ¾³ýÀÁ¶èÉ¾³ýµÄ¹Ë¿Í¡£ 
		
	if (isEmpty(Q)) {
		X.T = EmptyQ;
	} else {
		if (Q->Data[Q->Front].V == 1) {
			X = VIPPop(Q);
		} else {
			X = Q->Data[Q->Front];
		}		
	}
	Q->Front++;
	
	return X;
}

bool Push(Queue Q, ElementType X)
{	
	if (X.V) {
		VIPPush(Q, Q->Rear);
	}
	Q->Data[Q->Rear++] = X;
	
	return true; 
}

Queue CreateQueue(int MaxSize)
{
	int i;
	Queue Q;
	
	Q = NULL;
	if (MaxSize) {
		Q = (Queue)malloc(sizeof(struct QNode));
		Q->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
		Q->Front = Q->Rear = 0;
		Q->MaxSize = MaxSize;
		
		Q->VIPData = (int *)malloc(sizeof(int) * MaxSize);
		Q->VIPFront = Q->VIPRear = 0;
		Q->VIPSize = 0;
	}
	
	return Q;
}

void DestroyQueue(Queue Q)
{
	if (Q) {
		free(Q->Data);
		free(Q->VIPData);
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
	int VIPWindow;
	ElementType X;
	
	scanf("%d %d", &K, &VIPWindow);
	if (K) {
		TotalTime = CurrentTime = MaxWaitTime = 0;;
		for (i = 0; i < K; i++) {
			Windows[i] = 0;
			ServiceLog[i] = 0;
		}
		while (!isEmpty(Q)) {
			WinAvail = FindWinAvail(Windows, K, &WaitTime);
			CurrentTime += WaitTime;
			if (WinAvail == VIPWindow && VIPIsHere(Q, CurrentTime)) {
				X = VIPPop(Q);
			} else {
				X = Pop(Q);
			}
			if (X.T == EmptyQ) {
				break;
			}
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
			if (X.V == 1 && Windows[VIPWindow] == 0) {
				WinAvail = VIPWindow;
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
