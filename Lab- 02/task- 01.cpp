//task- 01: DFS on a dynamic graph

#include <iostream>
#include <vector>

using namespace std;

void DFS(int current, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {

    visited[current] = true;
    cout << current << " ";

    for (int neighbor : adjacencyList[current]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjacencyList, visited);
        }
    }
}

int main() {

    int n, e;
    if (!(cin >> n >> e)) return 0;

    vector<vector<int>> adjacencyList(n);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    int startVertex;
    cin >> startVertex;

    vector<bool> visited(n, false);

    cout << "DFS order: ";
    DFS(startVertex, adjacencyList, visited);
    cout << endl;

    return 0;
}
