#include <stdio.h>

#define MAX 501
int dist[MAX];
int map[MAX][MAX];
int cost[MAX][MAX];
int MCost[MAX];
bool visited[MAX] = {false};

void dijktra(int v0, int v, int d) {
	dist[v0] = 0; visited[v0] = true;
	int i, w;
	for (i = 1; i < v; i++) {
		int MIN = MAX;
		for (w = 0; w < v; w++) {
			if (!visited[w]) {
				if (dist[w] < MIN) {
					MIN = dist[w];
					v0 = w;
				}
			}
		}
		visited[v0] = true;
		for (w = 0; w < v; w++) {
			if (!visited[w] && MIN + map[v0][w] < dist[w]) {
				dist[w] = MIN + map[v0][w];
				MCost[w] = MCost[v0] + cost[v0][w];
			} else if (!visited[w] && MIN + map[v0][w] == dist[w]
			          && MCost[v0] + cost[v0][w] < MCost[w]) {
			          	MCost[w] = MCost[v0] + cost[v0][w];
					  }
		}
	}
}

int main() {
    int N, M, S, D, i, j;
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			map[i][j] = map[j][i] = MAX;
			cost[i][j] = cost[j][i] = MAX;
		}
	}
	for (i = 0; i < M; i++) {
		int n1, n2, m, c;
		scanf("%d%d%d%d", &n1, &n2, &m, &c);
		map[n1][n2] = map[n2][n1] = m;
		cost[n1][n2] = cost[n2][n1] = c;
	}
	for (i = 0; i < N; i++) {
		dist[i] = map[i][S];
		MCost[i] = cost[i][S];
	}
	dijktra(S, N, D);
	printf("%d %d\n", dist[D], MCost[D]);
		
	return 0;
}
