#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100001;
vector<int> adj[MAXN]; // Danh sách kề của đồ thị
int num[MAXN], low[MAXN], parent[MAXN];
bool isCutVertex[MAXN];
vector<pair<int, int>> bridges;
int timeDfs;

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    int children = 0;
    for (int v : adj[u]) {
        if (num[v] == 0) { // Nếu đỉnh v chưa được thăm
            children++;
            parent[v] = u;
            dfs(v);

            // Cập nhật giá trị low[u]
            low[u] = min(low[u], low[v]);

            // Nếu u là gốc và có nhiều hơn 1 con
            if (parent[u] == -1 && children > 1) {
                isCutVertex[u] = true;
            }

            // Nếu u không phải gốc và low[v] >= num[u] (Nghĩa là ko có back edges)
            if (parent[u] != -1 && low[v] >= num[u]) {
                isCutVertex[u] = true;
            }

            // Nếu low[v] > num[u], thì (u, v) là cầu
            if (low[v] > num[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parent[u]) { // Cập nhật low[u] nếu v là cạnh ngược
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    freopen("ex1.txt","r",stdin);
    int n, m;
    cin >> n >> m;

    // Nhập danh sách cạnh
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Khởi tạo
    fill(num, num + n + 1, 0);
    fill(low, low + n + 1, 0);
    fill(parent, parent + n + 1, -1);
    fill(isCutVertex, isCutVertex + n + 1, false);
    timeDfs = 0;

    // DFS từ các đỉnh chưa được thăm
    for (int u = 1; u <= n; u++) {
        if (num[u] == 0) {
            dfs(u);
        }
    }

    // Đếm số lượng điểm khớp
    int articulationPoints = 0;
    for (int u = 1; u <= n; u++) {
        if (isCutVertex[u]) {
            articulationPoints++;
        }
    }

    // In kết quả
    cout << articulationPoints << " " << bridges.size() << endl;

    return 0;
}
