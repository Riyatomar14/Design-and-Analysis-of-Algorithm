#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 5
#define INF 99999 // Use a large value as infinity

// Function to find the vertex with the minimum key value
int minKey(int key[], bool visited[]) {
    int min = INF, minIndex;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST (Minimum Spanning Tree)
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Function to implement Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values to pick the minimum weight edge
    bool visited[V]; // To keep track of the vertices included in MST

    // Initialize all keys as infinity and visited[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    // Start with the first vertex (index 0)
    key[0] = 0;
    parent[0] = -1; // The first node is the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, visited);

        // Include the picked vertex in the MST
        visited[u] = true;

        // Update the key and parent values of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Call the function to compute MST
    primMST(graph);

    return 0;
}
