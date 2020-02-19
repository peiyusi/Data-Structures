#include <stdio.h>

#define MaxVertexNum 100
//边 
typedef struct ENode {
	int V1; 
	int V2;
	int C;
	int B;	
} Edges[MaxVertexNum * (MaxVertexNum - 1) / 2];
//并查集 
int VSet[MaxVertexNum + 1];

void Swap(Edges ESet, int E1, int E2)
{
    int V1, V2, C, B;
	
	V1 = ESet[E1].V1, V2 = ESet[E1].V2, C = ESet[E1].C, B = ESet[E1].B;
	ESet[E1].V1 = ESet[E2].V1, ESet[E1].V2 = ESet[E2].V2, ESet[E1].C = ESet[E2].C, ESet[E1].B = ESet[E2].B;
	ESet[E2].V1 = V1, ESet[E2].V2 = V2, ESet[E2].C = C, ESet[E2].B = B;
}

int Compare(struct ENode E1, struct ENode E2)
{
	if (E1.B == E2.B) {
		return E1.C < E2.C;
	} 
	
	return E1.B > E2.B;
}

void Perc_Down(Edges ESet, int P, int N)
{
	int Parent, Child;
	struct ENode X;
	
	X.V1 = ESet[P].V1, X.V2 = ESet[P].V2, X.C = ESet[P].C, X.B = ESet[P].B;
	for (Parent = P; Parent * 2 + 1 < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if (Child != N - 1 && Compare(ESet[Child + 1], ESet[Child])) {
			Child++;
		}
		if (Compare(ESet[Child], X)) {
			ESet[Parent].V1 = ESet[Child].V1, ESet[Parent].V2 = ESet[Child].V2, ESet[Parent].C = ESet[Child].C, ESet[Parent].B = ESet[Child].B;
		} else {
			break;
		}
	}
	ESet[Parent].V1 = X.V1, ESet[Parent].V2 = X.V2, ESet[Parent].C = X.C, ESet[Parent].B = X.B;
}

int Find(int S)
{
	if (VSet[S] < 0) {
		return S;
	}
	return VSet[S] = Find(VSet[S]);
}

void Union(int Root1, int Root2)
{
	if (VSet[Root1] < VSet[Root2]) {
		VSet[Root1] += VSet[Root2];
		VSet[Root2] = Root1;
	} else {
		VSet[Root2] += VSet[Root1];
		VSet[Root1] = Root2;
	}
}

int main() 
{
	freopen("E:in.txt", "r", stdin);
	int N, ENum, i, j, Root1, Root2, TotalCost;
	Edges ESet; 
	
	scanf("%d", &N);
	ENum = N * (N - 1) / 2;
	TotalCost = 0;
	//读取数据 
	for (i = 0; i < ENum; i++) {
		scanf("%d %d %d %d", &ESet[i].V1, &ESet[i].V2, &ESet[i].C, &ESet[i].B);
	}
	//对边集排序 
	for (i = ENum / 2 - 1; i >= 0; i--) {
		Perc_Down(ESet, i, ENum);
	}

	//初始化并查集 
	for (i = 1; i <= N; i++) {
		VSet[i] = -1;
	}
	
	for (i = ENum - 1; i >= 0; i--) {
		Swap(ESet, 0, i);
		Root1 = Find(ESet[i].V1);
		Root2 = Find(ESet[i].V2);
		if (Root1 != Root2) {
			Union(Root1, Root2);	
			if (!ESet[i].B) {
				TotalCost += ESet[i].C;
			}
		}
		Perc_Down(ESet, 0, i);
	}
	
	printf("%d", TotalCost);
	fclose(stdin);
    return 0;
}
