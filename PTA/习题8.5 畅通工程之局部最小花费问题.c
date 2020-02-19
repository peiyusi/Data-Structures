#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 101 //最大顶点数，注意顶点下标从1开始 

typedef int Vertex;

typedef Vertex ElementType;
typedef Vertex SetName;
typedef ElementType SetType[MaxVertexNum]; //并查集 

typedef int Cost;
typedef int Build;
typedef struct ENode *PtrToENode;   //边 
struct ENode {
	Vertex V1;
	Vertex V2;
	Cost C;
	Build B;
};
typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode; //临接点 
struct AdjVNode {
	Vertex Adj;
	PtrToAdjVNode Next;
	Cost C;
	Build B;
};

typedef struct VNode {     //头节点 
	PtrToAdjVNode FirstEdge;   
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode; //邻接表 
struct GNode {
	AdjList G;
	int Nv;  //顶点数 
	int Ne;  //边数 
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)  //创建一个空图 
{
	LGraph Graph;
	Vertex V;
	
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 1; V <= VertexNum; V++) {
		Graph->G[V].FirstEdge = NULL;
	}
	
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)  //头插法插入边 
{
	PtrToAdjVNode NewNode;
	
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adj = E->V2;
	NewNode->C = E->C;
	NewNode->B = E->B;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode)); //无向图还需要插入边<V2, V1> 
	NewNode->Adj = E->V1;
	NewNode->C = E->C;
	NewNode->B = E->B;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
	
	Graph->Ne++;
}

LGraph BuildGraph()  //读取数据, 把边插入图中 
{
	int N;
	LGraph Graph;
	Edge E;
	
	scanf("%d", &N);
	Graph = CreateGraph(N);
	N = N * (N - 1) / 2;
	while (N--) {
		E = (Edge)malloc(sizeof(struct ENode));
		scanf("%d %d %d %d", &E->V1, &E->V2, &E->C, &E->B);
		InsertEdge(Graph, E);
	}
	
	return Graph; 
}

void PercDown(Edge ESet, int P, int N)  //过滤最小堆操作，从第一个有叶结点的结点开始 
{
	int Parent, Child;
	struct ENode X;
	
	X = ESet[P];
	for (Parent = P; Parent * 2 + 1 < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if (Child != N - 1 && ESet[Child].C > ESet[Child + 1].C) { //如果右结点权重更小，更新子节点 
			Child++;
		}
		if (X.C > ESet[Child].C) {
			ESet[Parent] = ESet[Child];
		} else {
			break;
		}
	}
	ESet[Parent] = X;
}

void InitESet(Edge ESet, LGraph Graph)
{
	Vertex V;
	PtrToAdjVNode P;
	int ECount;
	
	ECount = 0;           
	for (V = 1; V <= Graph->Nv; V++) {  //把边存进最小堆 
		for (P = Graph->G[V].FirstEdge; P; P = P->Next) {
			if (V < P->Adj) { //无向图的边是双向的，为避免重复录入，只收取V1<V2的边 
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = P->Adj;
				ESet[ECount].C = P->C;
				ESet[ECount++].B = P->B;	
			}
		}
	}
	for (ECount = Graph->Ne / 2 - 1; ECount >= 0; ECount--) { //建立最小堆 
		PercDown(ESet, ECount, Graph->Ne);
	}
}

void Swap(Edge E1, Edge E2)  //注意是交换两边的值
{
	Vertex V1, V2;
	Cost C;
	Build B;
	
	V1 = E1->V1, V2 = E1->V2, C = E1->C, B = E1->B;
	E1->V1 = E2->V1, E1->V2 = E2->V2, E1->C = E2->C, E1->B = E2->B;
	E2->V1 = V1, E2->V2 = V2, E2->C = C, E2->B = B;
}

int GetEdge(Edge ESet, int CurrentSize)
{
	Swap(&ESet[0], &ESet[CurrentSize - 1]); //将最小边与最后一条边交换
	PercDown(ESet, 0, CurrentSize - 1); //调整堆
	
	return CurrentSize - 1; 
}

SetName Find(SetType S, ElementType X)  //寻找根节点并压缩路径 
{
	if (S[X] < 0) {
		return X;
	}
	return S[X] = Find(S, S[X]);
}

void Union(SetType S, ElementType Root1, ElementType Root2)  //合并 
{ 
	if (S[Root1] < S[Root2]) {
		S[Root1] += S[Root2]; 
		S[Root2] = Root1;
	} else {
		S[Root2] += S[Root1]; 
		S[Root1] = Root2;
	}
}

bool CheckCycle(SetType VSet, Vertex V1, Vertex V2) //检查是否构成回路 
{
	Vertex Root1, Root2;
	
	Root1 = Find(VSet, V1);
	Root2 = Find(VSet, V2);
	if (Root1 == Root2) {
		return false;
	} else {
		Union(VSet, Root1, Root2); //不是的话，把V1, V2并入一个集合 
		return true;
	}
}

void InitVSet(SetType VSet, int Nv) //初始化并查集，注意结点下标从1开始 
{
	int i;
	
	for (i = 1; i <= Nv; i++) {
		VSet[i] = -1;
	}
}
 
int CheckEdge(SetType VSet, Edge ESet, int Ne) //检查已建好的道路
{
	int ECount, i;
	
	ECount = 0;
	for (i = 0; i < Ne; i++) {
		if (ESet[i].B) {  //如果已经建造了道路
			if (CheckCycle(VSet, ESet[i].V1, ESet[i].V2)) { //如果不构成回路 
				ECount++;	   //累加边数
			}
		}
	}
	
	return ECount;	
} 
 
int Kruskal(LGraph Graph) 
{
	Cost TotalCost;
	int ECount, NextEdge; 
	Edge ESet; 
	SetType VSet; 
	
	NextEdge = Graph->Ne, TotalCost = 0;
	//初始化最小堆 
	ESet = (Edge)malloc(sizeof(struct ENode) * Graph->Ne);
	InitESet(ESet, Graph);
	//初始化并查集 
	InitVSet(VSet, Graph->Nv);
	//统计已经得到的边数 
	ECount = CheckEdge(VSet, ESet, Graph->Ne);
	while (ECount < Graph->Nv - 1) {  //最小生成树的边数等于结点数-1 
		NextEdge = GetEdge(ESet, NextEdge);  //从最小堆中得到权重最小的一条边 
		if (CheckCycle(VSet, ESet[NextEdge].V1, ESet[NextEdge].V2) == true) { //如果不构成回路 
			TotalCost += ESet[NextEdge].C;   //累加权重 
			ECount++;                        //累加边数 
		}
	}
	free(ESet); //记得释放内存 
	
	return TotalCost;
}

void DestroyGraph(LGraph Graph) //遍历邻接点并释放内存 
{
	Vertex V;
	PtrToAdjVNode P, Temp;
	
	for (V = 1; V <= Graph->Nv; V++) {
		for (P = Graph->G[V].FirstEdge; P; P = Temp) {
			Temp = P->Next;
			free(P);
		}
	}
	free(Graph);
}

int main() 
{
	LGraph Graph; 
	int result;
	
	Graph = BuildGraph();
	printf("%d", Kruskal(Graph));
	DestroyGraph(Graph); //记得释放内存 

    return 0;
}
