#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the vertex with the minimum key value not yet included in MST
int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index = -1;
    for(int v = 0; v < V; v++) {
        if(!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's MST algorithm
void primMST(const vector<vector<int>>& graph, int V) {
    vector<int> key(V, INT_MAX);      // Stores minimum weights
    vector<int> parent(V, -1);        // Stores MST structure
    vector<bool> mstSet(V, false);    // True if vertex is included in MST

    key[0] = 0;  // Start from vertex 0

    for(int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    cout << "\nEdge \tWeight\n";
    for(int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
        totalWeight += graph[i][parent[i]];
    }

    cout << "Total weight of MST: " << totalWeight << endl;
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

    return 0;
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
