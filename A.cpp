#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Structure for Node
struct Node {
    vector<int> state; // 8-puzzle as 1D array
    int g, h;          // g = cost so far, h = heuristic
    Node* parent;      // to trace the path

    Node(vector<int> s, int g_val, int h_val, Node* p = nullptr) {
        state = s;
        g = g_val;
        h = h_val;
        parent = p;
    }

    // Priority in priority_queue -> smallest (g+h) first
    bool operator<(const Node& other) const {
        return (g + h) > (other.g + other.h);
    }
};

// Function to print 8 puzzle
void printState(vector<int> state) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) cout << "\n";
        if (state[i] == -1) cout << "_ ";
        else cout << state[i] << " ";
    }
    cout << "\n";
}

// Heuristic: Manhattan Distance
int heuristic(vector<int> current, vector<int> goal) {
    int distance = 0;
    for (int i = 0; i < 9; i++) {
        if (current[i] == -1) continue;
        for (int j = 0; j < 9; j++) {
            if (current[i] == goal[j]) {
                distance += abs(i / 3 - j / 3) + abs(i % 3 - j % 3);
                break;
            }
        }
    }
    return distance;
}

// Find possible moves
vector<vector<int>> getNeighbors(vector<int> state) {
    vector<vector<int>> neighbors;
    int empty = -1;
    for (int i = 0; i < 9; i++) {
        if (state[i] == -1) {
            empty = i;
            break;
        }
    }
    int row = empty / 3;
    int col = empty % 3;

    // Move up
    if (row > 0) {
        vector<int> newState = state;
        swap(newState[empty], newState[empty - 3]);
        neighbors.push_back(newState);
    }
    // Move down
    if (row < 2) {
        vector<int> newState = state;
        swap(newState[empty], newState[empty + 3]);
        neighbors.push_back(newState);
    }
    // Move left
    if (col > 0) {
        vector<int> newState = state;
        swap(newState[empty], newState[empty - 1]);
        neighbors.push_back(newState);
    }
    // Move right
    if (col < 2) {
        vector<int> newState = state;
        swap(newState[empty], newState[empty + 1]);
        neighbors.push_back(newState);
    }

    return neighbors;
}

// Compare two states
bool isGoal(vector<int> state, vector<int> goal) {
    return state == goal;
}

// A* Algorithm
void aStar(vector<int> start, vector<int> goal) {
    priority_queue<Node> openList;
    openList.push(Node(start, 0, heuristic(start, goal)));

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        // Check if goal is reached
        if (isGoal(current.state, goal)) {
            cout << "\nSolved!\nPath to goal:\n";
            vector<Node*> path;
            Node* temp = &current;
            while (temp != nullptr) {
                path.push_back(temp);
                temp = temp->parent;
            }
            reverse(path.begin(), path.end());
            for (auto node : path) {
                printState(node->state);
                cout << "\n";
            }
            cout << "Total Moves: " << path.size() - 1 << "\n";
            return;
        }

        // Expand neighbors
        vector<vector<int>> neighbors = getNeighbors(current.state);
        for (auto neighbor : neighbors) {
            int g_new = current.g + 1;
            int h_new = heuristic(neighbor, goal);
            openList.push(Node(neighbor, g_new, h_new, new Node(current)));
        }
    }

    cout << "No solution found.\n";
}

int main() {
    vector<int> start(9), goal(9);

    cout << "Enter Start State (Use -1 for empty tile):\n";
    for (int i = 0; i < 9; i++) cin >> start[i];

    cout << "Enter Goal State (Use -1 for empty tile):\n";
    for (int i = 0; i < 9; i++) cin >> goal[i];

    aStar(start, goal);

    return 0;
}
// Enter Start State (Use -1 for empty tile):
// 2 8 3 -1 1 4 7 6 5
// Enter Goal State (Use -1 for empty tile):
// 1 2 3 8 -1 4 7 6 5
// Solved!
// Path to goal:

// 2 8 3 
// _ 1 4 
// 7 6 5 

// 2 _ 3 
// 8 1 4 
// 7 6 5 

// _ 2 3 
// 8 1 4 
// 7 6 5 

// 1 2 3 
// 8 _ 4 
// 7 6 5 

// 1 2 3 
// 8 _ 4 
// 7 6 5 

// Total Moves: 4
