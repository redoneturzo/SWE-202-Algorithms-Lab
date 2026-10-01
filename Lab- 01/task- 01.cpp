/*
* Task 1: BFS on a dynamic graph
*
* Write a program that reads a graph from the user, stores it as an adjacency matrix, and prints the BFS traversal
from a start vertex chosen by the user.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS function using an Adjacency Matrix
void BFS(const vector<vector<int>>& adjMatrix, int start, int nodes) {
    vector<bool> visited(nodes, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Look across the matrix row for connected neighbors
        for (int neighbor = 0; neighbor < nodes; neighbor++) {
            // Check if there's an edge (1) and if it hasn't been visited yet
            if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes, edges;
    cout << "Enter number of vertices (n) and edges (e): ";
    cin >> nodes >> edges;

    // Initialize a 2D adjacency matrix (n x n) filled with 0s
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    cout << "Enter " << edges << " lines of edges (pairs of vertices):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        // Mark the connection in the matrix (undirected graph)
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    int startVertex;
    cout << "Enter the start vertex: ";
    cin >> startVertex;

    // Run BFS traversal from the user-selected start vertex
    BFS(adjMatrix, startVertex, nodes);

    return 0;
}
