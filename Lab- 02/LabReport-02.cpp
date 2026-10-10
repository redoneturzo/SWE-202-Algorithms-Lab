///Topological Sorting Using DFS

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100];
bool visited[100];
vector<int> ans;

void DFS(int u) {
    visited[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            DFS(v);
        }
    }

    ans.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    cout << "Topological order: ";

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
