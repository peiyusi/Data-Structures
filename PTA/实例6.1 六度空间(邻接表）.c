#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Vertex;
#define MaxVertexNum 1001
#define SIX 6

int Queue[1001];
bool Visited[1001];

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode {
	Vertex Adj;
	PtrToAdjVNode Next;
}; 

typedef struct VNode {
	PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;
	AdjList G;
};
typedef PtrToGNode LGraph;

void Reset(int N)
{
	int i;
	
	for (i = 1; i <= N; i++) {
		Visited[i] = false;
	}
}

void InsertAdj(LGraph Graph)
{
	int V1, V2;
	PtrToAdjVNode NewNode;
	
	scanf("%d %d", &V1, &V2);
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adj = V2;
	NewNode->Next = Graph->G[V1].FirstEdge;
	Graph->G[V1].FirstEdge = NewNode;
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adj = V1;
	NewNode->Next = Graph->G[V2].FirstEdge;
	Graph->G[V2].FirstEdge = NewNode;
}

LGraph CreateGraph()
{
	int N, M, i;
	LGraph Graph;

	scanf("%d %d", &N, &M);
	if (N) {
		Graph = (LGraph)malloc(sizeof(struct GNode));
		Graph->Nv = N;
		for (i = 1; i <= N; i++) {
			Visited[i] = false;
			Graph->G[i].FirstEdge = NULL; 
		}
		while (M--) {
			InsertAdj(Graph);
		}
	}
	
	return Graph; 
}

int BFS(LGraph Graph, Vertex V)
{
	int Front, Rear, Tail, Last, Count, Level, PopV;
	PtrToAdjVNode P;
	
	if (!Visited[V]) {
		Front = Rear = 0;
		Level = 0, Count = 1, Last = V;
		Visited[V] = true;
		Queue[Rear++] = V;
		while (Front != Rear) {
			PopV = Queue[Front++];
			for (P = Graph->G[PopV].FirstEdge; P; P = P->Next) { 
				if (!Visited[P->Adj]) {
					Visited[P->Adj] = true;
					Queue[Rear++] = P->Adj;
					Tail = P->Adj;
					Count++;
				}
			}
			if (PopV == Last) {
				Level++;
				Last = Tail;
			}
			if (Level == SIX) {
				break;
			}
		}
	}
	
	return Count;
}

void Print(int V, int N, int Count)
{
	printf("%d: %.2f%%\n", V, (double)(Count * 100) / (double) N);
}

void DestroyGraph (LGraph Graph)
{
	int i;
	PtrToAdjVNode P, Temp;
	
	for (i = 1; i <= Graph->Nv; i++) {
		for (P = Graph->G[i].FirstEdge; P; P = Temp) {
			Temp = P->Next;
			free(P);
		}
	}
	free(Graph); 
}

void Compute(LGraph Graph)
{
	int i;
	
	for (i = 1; i <= Graph->Nv; i++) {
		Print(i, Graph->Nv, BFS(Graph, i));
		Reset(Graph->Nv);
	}
	DestroyGraph(Graph); 
}

int main()
{
	freopen("E:in.txt", "r", stdin);
	LGraph Graph;
	
	Graph = CreateGraph();
	Compute(Graph);
	
	fclose(stdin);
	return 0;
}
