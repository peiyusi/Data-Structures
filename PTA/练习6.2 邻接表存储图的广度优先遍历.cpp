void BFS(LGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	int maxSize = 10;
	int queue[maxSize];
	int front, rear;
	PtrToAdjVNode p;
	
	front = rear = -1;

    rear = (rear + 1) % maxSize;
    queue[rear] = S;
    Visit(S);
    Visited[S] = true;
    while (front != rear) {
        front = (front + 1) % maxSize;
        p = Graph->G[queue[front]].FirstEdge;
        while (p) {
            if (!Visited[p->AdjV]) {
                rear = (rear + 1) % maxSize;
                queue[rear] = p->AdjV;
                Visit(p->AdjV);
                Visited[p->AdjV] = true;
            }
            p = p->Next;
        }
    }
	
}
