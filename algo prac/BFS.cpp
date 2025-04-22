#include <iostream>
using namespace std;

#define MAX 10  // Maximum number of vertices

void BFS(int adj[MAX][MAX], int n, int start) {
    bool visited[MAX] = {false};
    int queue[MAX], front = 0, rear = 0;

    // Enqueue the start vertex and mark as visited
    queue[rear++] = start;
    visited[start] = true;

    cout << "BFS traversal starting from vertex " << start << ": ";

    while (front < rear) {
        int current = queue[front++];
        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    cout << endl;
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

    int startVertex = 0;
    BFS(adj, n, startVertex);

    return 0;
}
