#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 6
#define INF 99999  // Define a large value for infinity

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array to store the shortest distance from the source
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as infinity and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }

    // Distance from the source to itself is 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if and only if it is not in sptSet, there is an edge from u to v, 
            // and the total weight of path from source to v through u is smaller than the current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the computed shortest distances
    cout << "Vertex\tDistance from Source (" << src << ")" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    // Adjacency matrix representation of the graph
    // graph[i][j] represents the weight of the edge from vertex i to vertex j
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 0},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 0, 0, 9, 0}
    };

    int src;
    cout << "Enter the source vertex (0-5): ";
    cin >> src;

    // Call Dijkstra's algorithm to compute shortest paths from the source vertex
    dijkstra(graph, src);

    return 0;
}
