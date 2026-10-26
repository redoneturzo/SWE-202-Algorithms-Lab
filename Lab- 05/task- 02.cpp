#include <bits/stdc++.h>
using namespace std;


bool hasNegativeCycle(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;


    for (int i = 0; i < V - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }


    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return true;
        }
    }

    return false;
}

int main() {
    int V, E;
    if (!(cin >> V >> E)) return 0;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int S;
    cin >> S;


    if (hasNegativeCycle(V, edges, S)) {
        cout << "Negative cycle detected" << endl;
    } else {
        cout << "No negative cycle" << endl;
    }

    return 0;
}

