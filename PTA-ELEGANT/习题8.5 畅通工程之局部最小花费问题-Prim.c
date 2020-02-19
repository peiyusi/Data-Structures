#include <stdio.h>

#define MAXVERTEXNUM 101
#define INFINITY 65532
#define ERROR -1
#define VISITED -2

int Graph[MAXVERTEXNUM][MAXVERTEXNUM];
int dist[MAXVERTEXNUM];  //dist存储各顶点与当前树的距离 

int findMinSet(int n)
{
	int minDist, minSet, i;
	
	minDist = INFINITY;
	for(i = 1; i <= n; i++) {
		if (dist[i] != VISITED && dist[i] < minDist) {
			minSet = i;
			minDist = dist[i];
		}
	}
	
	return (minDist == INFINITY ? ERROR : minSet);	
}

int main()
{
	//freopen("E:in.txt", "r", stdin);
	int n, eNum, V1, V2, C, B;
	scanf("%d", &n);
	eNum = n * (n - 1) / 2;
	
	int i, j;
	
	while (eNum--) {
		scanf("%d %d %d %d", &V1, &V2, &C, &B);
		if (B) {
			Graph[V1][V2] = 0;
			Graph[V2][V1] = 0;
		} else {
			Graph[V1][V2] = C;
			Graph[V2][V1] = C;
		}
	}
	dist[1] = VISITED; 
	for (i = 2; i <= n; i++) {
		dist[i] = Graph[1][i];
	}
	int costSum = 0;
	while (1) {
		int Set = findMinSet(n);
		if (Set == ERROR) break; 
		costSum += dist[Set];
		dist[Set] = VISITED;
		for (j = 1; j <= n; j++) {
			if (dist[j] != VISITED && Graph[Set][j] < dist[j]) {
				dist[j] = Graph[Set][j];
			}
		}
	}
	printf("%d", costSum);
	//fclose(stdin);
	return 0;
}
