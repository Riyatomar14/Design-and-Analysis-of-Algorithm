#include <iostream>
using namespace std;

#define MAX 10  // Maximum number of vertices

void DFS(int adj[MAX][MAX], int n, int start, bool visited[MAX]) {
    // Mark the current node as visited
    visited[start] = true;
    cout << start << " ";

    // Visit all the adjacent vertices of the current vertex
    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(adj, n, i, visited);  // Recur for adjacent node
        }
    }
}

int main() {
    int n = 5;  // Number of vertices
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    bool visited[MAX] = {false};  // Array to track visited nodes
    int startVertex = 0;  // Starting vertex for DFS

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    DFS(adj, n, startVertex, visited);
    cout << endl;

    return 0;
}
