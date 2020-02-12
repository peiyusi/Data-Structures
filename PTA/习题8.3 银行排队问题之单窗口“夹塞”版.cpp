#include <iostream>
#include <map>
#include <queue>
#include <cstdio>

using namespace std;

#define MaxNameLen 3
#define MaxPeopleNum 10000

typedef struct People ElementType;
typedef int Position;
struct People {
	int T;
	int P;
	char Name[MaxNameLen + 1];
	Position Index;
} PQueue[MaxPeopleNum];

int main() 
{
	//freopen("E:in.txt", "r", stdin);
	map<string, int> Group;
	queue<ElementType> Que;
	char Name[MaxNameLen + 1];
	int N, M, L, i, j;
	
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &L);
		for (j = 0; j < L; j++) {
			scanf("%s", Name);
			Group[Name] = i;
		}
	}
	for (i = 0; i < N; i++) {
		scanf("%s %d %d", &PQueue[i].Name, &PQueue[i].T, &PQueue[i].P);
		if (PQueue[i].P > 60) {
			PQueue[i].P = 60;
		} 
		PQueue[i].Index = i;
		Que.push(PQueue[i]);
	}
	
	int CurrentTime, SumWaitTime, WindowsTime, WaitTime;
	ElementType X;
	bool Visited[N] = {false};
		
	CurrentTime = SumWaitTime = WindowsTime = WaitTime = 0;
	while (!Que.empty()) {
		X = Que.front();
		Que.pop();
		if (!Visited[X.Index]) {  //如果没有被删除 
			Visited[X.Index] = true;
			printf("%s\n", X.Name);
			CurrentTime += WindowsTime; //解决掉上一个事务 
			if (X.T <= CurrentTime) {   //如果顾客提前来到，累加等待时间 
				WaitTime = CurrentTime - X.T;
				SumWaitTime += WaitTime;
			} else {
				CurrentTime = X.T;  //否则更新当前时间，为顾客到达时间 
			} 
			WindowsTime = X.P; //添加当前事务
			for (i = X.Index + 1; i < N; i++) {
				if (!Visited[i] && Group.count(X.Name) && Group.count(PQueue[i].Name) && (Group[X.Name] == Group[PQueue[i].Name])) {  //判断是否在同一个朋友圈 
					if (CurrentTime + WindowsTime >= PQueue[i].T) {  //如果当前事务完成前，朋友已经来到，帮助朋友 
						SumWaitTime += (CurrentTime + WindowsTime - PQueue[i].T);  //累加朋友等待时间 
						Visited[i] = true;
						printf("%s\n", PQueue[i].Name);
						WindowsTime += PQueue[i].P;
					}
				}
			}
		}		
	}
	
	printf("%.1f", (double)SumWaitTime / (double)N);
	
    //fclose(stdin);
    return 0;
}
