/*
Report- 01: Write a program to detect a cycle in an undirected graph using BFS. The program should print
Cycle found or No cycle.
*/

#include<bits/stdc++.h>

using namespace std;

bool isCyclicBFS(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q;

    visited[start] = true;
    q.push({start, -1});

    while (!q.empty()) {
        int u = q.front().first;
        int p = q.front().second;
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push({v, u});
            }
            else if (v != p) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};

    vector<bool> visited(V, false);
    bool hasCycle = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicBFS(i, adj, visited)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "Cycle found" << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}
