//task- 02
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(int current, int destination, const vector<vector<int>>& adjacencyList, vector<bool>& visited, vector<int>& parent) {

    if (current == destination) {
        return true;
    }

    visited[current] = true;

    for (int neighbor : adjacencyList[current]) {
        if (!visited[neighbor]) {
            parent[neighbor] = current;

            if (DFS(neighbor, destination, adjacencyList, visited, parent)) {
                return true;
            }
        }
    }
    return false;
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

    int source, destination;
    cin >> source >> destination;

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    if (DFS(source, destination, adjacencyList, visited, parent)) {
        vector<int> path;
        int current = destination;

        while (current != -1) {
            path.push_back(current);
            if (current == source) break;
            current = parent[current];
        }


        reverse(path.begin(), path.end());


        cout << "Path: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "No path" << endl;
    }

    return 0;
}

