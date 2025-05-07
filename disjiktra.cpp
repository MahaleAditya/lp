#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(vector<int> dist, vector<bool> sptSet, int V) {
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if(!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(vector<vector<int>> graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for(int v = 0; v < V; v++)
            if(!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Vertex\tDistance from Source\n";
    for(int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int V, src;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix:\n";
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cin >> graph[i][j];

    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, src, V);
}


/*
i/p
Enter number of vertices: 5
Enter the adjacency matrix:
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0
Enter source vertex: 0

*/