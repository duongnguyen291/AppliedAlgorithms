#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj; 
vector<bool> visited;
int maxDist = 0; 

void DFS(int u, int dist, int &farthestNode) {
    visited[u] = true;
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = u;
    }

    for (auto v : adj[u]) {
        if (!visited[v.first]) {
            DFS(v.first, dist + v.second, farthestNode);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ex1.txt","r",stdin);
    int N;
    cin >> N;

    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int farthest_1 = 1;
    maxDist = 0;
    DFS(1, 0, farthest_1);  
    fill(visited.begin(), visited.end(), false);
    maxDist = 0; 
    DFS(farthest_1, 0, farthest_1); 
    cout << maxDist << "\n";

    return 0;
}
