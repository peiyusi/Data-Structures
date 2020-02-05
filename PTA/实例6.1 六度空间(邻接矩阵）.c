#include <stdio.h>
#include <stdbool.h>

#define SIX 6

int Graph[1001][1001], Queue[1001], N;
bool Visited[1001];

void Reset()
{
	int i;
	for (i = 1; i <= N; i++) {
		Visited[i] = false;
	}
}

void Read()
{
	int M, i, j;

	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		Visited[i] = false;
		for (j = 1; j <= N; j++) {
			Graph[i][j] = 0;
		}
	}
	
	while (M--) {
		scanf("%d %d", &i, &j);
		Graph[i][j] = 1;
		Graph[j][i] = 1;
	}
}

int BFS(int V)
{
	int Front, Rear, Vertex, Tail, Last, Count, Level;
	int i;
	
	if (!Visited[V]) {
		Front = Rear = 0;
		Level = 0, Count = 1, Last = V;
		Visited[V] = true;
		Queue[Rear++] = V;
		while (Front != Rear) {
			Vertex = Queue[Front++];
			for (i = 1; i <= N; i++) {
				if (Graph[Vertex][i] && !Visited[i]) {
					Visited[i] = true;
					Queue[Rear++] = i;
					Tail = i;
					Count++;
				} 
			}
			if (Vertex == Last) {
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

void Print(int V, int Count)
{
	printf("%d: %.2f%%\n", V, (double)(Count * 100) / (double) N);
}

void Compute()
{
	int i;
	
	for (i = 1; i <= N; i++) {
		Print(i, BFS(i));
		Reset();
	}
}

int main()
{
	//freopen("E:in.txt", "r", stdin);
		
	Read();
	Compute();
	
	//fclose(stdin);
	return 0;
}
