#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVertexNum = 10001
int G[MaxVertexNum][MaxVertexNum] = {0};
bool visited[MaxVertexNum][MaxVertexNum] = {false};

int BFS(Vertex V) {
	int count , level, last;
	visited[V] = true;, count = 1;
	level = 0; last = V;
	Enqueue(V, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (each W in V)
		    if (!visited[W]) {
		    	visited[W] = true;
		    	Enqueue(W, Q); count++;
		    	tail = W;
			}
		if (V == last) {
			level++; last = tail;
		}
		if (level == 6) break;
	}
	return count;
}

int main() {
    int N, M, i, V1, V2;
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++) {
    	scanf("%d %d", &V1, &V2);
    	G[V1][V2] = 1;
    	G[V2][V1] = 0;
	}
	return 0;
}
