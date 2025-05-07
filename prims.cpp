#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minKey(vector<int> key, vector<bool> mstSet, int V) {
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if(!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(vector<vector<int>> graph, int V) {
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for(int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for(int v = 0; v < V; v++)
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Edge \tWeight\n";
    for(int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (0 if no edge):\n";
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph, V);
}


//ip
/*
Enter number of vertices: 5
Enter the adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/