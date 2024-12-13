#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int graph[MAXN][MAXN], residual[MAXN][MAXN];
int parent[MAXN];
int V, E, s, t;

bool bfs() {
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(s);
    parent[s] = s;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= V; v++) {
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int edmonds_karp() {
    // Reset residual graph
    memset(residual, 0, sizeof(residual));
    for (int u = 1; u <= V; u++) {
        for (int v = 1; v <= V; v++) {
            residual[u][v] = graph[u][v];
        }
    }

    int max_flow = 0;

    while (bfs()) {
        // Find minimum flow in the path
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
        }

        // Update residual graph
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    // Reset graph
    freopen("ex1.txt","r",stdin);
    memset(graph, 0, sizeof(graph));

    // Input
    cin >> V >> E >> s >> t;

    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        graph[u][v] += cap;  // Handle multiple edges
    }

    // Compute max flow
    int result = edmonds_karp();
    cout << "The maximum possible flow is " << result << endl;

    return 0;
}