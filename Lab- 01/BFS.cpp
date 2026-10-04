//BFS basic code

#include<bits/stdc++.h>
using namespace std;

void BFS(const vector<vector<int>>& adjecencyList, int start, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front(); //0
        q.pop();
        cout << current << " ->";

        for (auto neighbor : adjecencyList[current]) { //{1, 2},
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    vector<vector<int>> adjecencyList = {
        {1, 2},        //node 0 is connected to nodes 1 and 2
        {0, 3, 4},     //node 1 is connected to nodes 0, 3, and 4
        {0, 5},        //node 2 is connected to nodes 0 and 5
        {1},           //node 3 is connected to node 1
        {1, 6},        //node 4 is connected to nodes 1 and 6
        {2},           //node 5 is connected to node 2
        {4}            //node 6 is connected to node 4
    };

    vector<bool> visited(adjecencyList.size(), false);

    BFS(adjecencyList, 0, visited);
}
