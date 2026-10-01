/*
* Task 2: Level of each node using BFS
*
* Extend Task 1 so that, for every vertex, the program prints its level, i.e. the minimum number of edges from
the start vertex. Print −1 for vertices that cannot be reached
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS function to calculate levels/distances using an Adjacency Matrix
void findLevelsBFS(const vector<vector<int>>& adjMatrix, int start, int nodes) {
    // Initialize all levels to -1 (means unreachable initially)
    vector<int> level(nodes, -1);
    queue<int> q;

    // The level of the start vertex is always 0
    level[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < nodes; neighbor++) {
            // Check if there is an edge and if the neighbor hasn't been visited yet
            if (adjMatrix[current][neighbor] == 1 && level[neighbor] == -1) {
                // The level of the neighbor is 1 more than the current node's level
                level[neighbor] = level[current] + 1;
                q.push(neighbor);
            }
        }
    }

    // Print the levels of all vertices
    cout << "\nVertex -> Level from start vertex (" << start << "):" << endl;
    for (int i = 0; i < nodes; i++) {
        cout << "Vertex " << i << " : " << level[i] << endl;
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of vertices (n) and edges (e): ";
    cin >> nodes >> edges;

    // Initialize an n x n adjacency matrix with 0s
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    cout << "Enter " << edges << " lines of edges (pairs of vertices):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    int startVertex;
    cout << "Enter the start vertex: ";
    cin >> startVertex;

    // Calculate and print levels
    findLevelsBFS(adjMatrix, startVertex, nodes);

    return 0;
}

