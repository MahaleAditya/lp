#include <iostream>
#include <queue>
using namespace std;

// Recursive function to process BFS
void BFSRecursive(int adj[][100], bool visited[], queue<int> &q, int ver) {
    if (q.empty())
        return;

    int node = q.front();
    q.pop();
    cout << node << " ";

    for (int i = 0; i < ver; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            visited[i] = true;
            q.push(i);
        }
    }

    BFSRecursive(adj, visited, q, ver); // Recur with updated queue
}

int main() {
    int ver;
    cout << "Enter the number of vertices: ";
    cin >> ver;

    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    int adj[100][100] = {0};
    cout << "Enter the edges (start to end):" << endl;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    bool visited[100] = {false};
    queue<int> q;

    visited[0] = true;
    q.push(0);

    cout << "BFS Traversal (Recursive) starting from 0: ";
    BFSRecursive(adj, visited, q, ver);
    cout << endl;

    return 0;
}
