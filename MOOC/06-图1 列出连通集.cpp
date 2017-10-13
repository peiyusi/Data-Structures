#include <stdio.h>
#include <string.h>

#define MAXN 11
int G[MAXN][MAXN] = {0};
bool Visited[MAXN] = {false};
int N;

void DFS(int V) {
	int i;
	Visited[V] = true;
	printf("%d ", V);
	for (i = 0; i < N; i++) {
		if (!Visited[i] && G[V][i]) DFS(i);
	}
}

void BFS(int V)
{
	int i;
	const int MAX_SIZE = 100;
    int Queue[MAX_SIZE];
    int first = -1, last = -1;

    Queue[++last] = V;      
    Visited[V] = true;
    while (first < last)    
    {
        int F = Queue[++first];     
        printf("%d ", F);
        for (i = 0; i < N; i++)
        {
            if (G[F][i] && !Visited[i])
            {
                Queue[++last] = i;      
                Visited[i] = true;
            }
        }
    }
}

void ListComponentsWithDFS() {
	int V;
	for (V = 0; V < N; V++) {
		if (!Visited[V]) {
			printf("{ ");
			DFS(V);
			printf("}\n");
		}
	}
}

void ListComponentsWithBFS() {
    int V;
    for (V = 0; V < N; V++) {
		if (!Visited[V]) {
				printf("{ ");
				BFS(V);
				printf("}\n");
			}
	}
}

void BuildGraph() {
	int i, E, v1, v2;
    scanf("%d %d", &N, &E);
	for (i = 0; i < E; i++) {
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = 1;
		G[v2][v1] = 1;	
	}
}

void InitVisit() {
    int i;
	for (i = 0; i < N; i++) {
		Visited[i] = false;
	}	
}
 
int main() {
	BuildGraph();
	ListComponentsWithDFS();
    InitVisit();
    ListComponentsWithBFS();
 
	return 0;
} 
