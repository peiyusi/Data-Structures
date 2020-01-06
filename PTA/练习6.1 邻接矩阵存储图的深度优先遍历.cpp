void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    Vertex i;
    Visited[V] = true;
    Visit(V);
    for (i = 0; i < Graph->Nv; i++) {
        if (Graph->G[V][i] == 1 && !Visited[i]) {
            DFS(Graph, i, Visit);
        }
    }
}
