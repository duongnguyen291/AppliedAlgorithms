#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_N = 5005;

// Input data
int n, m;                     // Number of cities and roads
int C[MAX_N], D[MAX_N];       // C[i]: Bus cost, D[i]: Max distance of bus i
vector<int> adj[MAX_N];       // Adjacency list for city connections
// Graph for shortest path calculation
vector<pair<int, int>> graph[MAX_N];
int dist[MAX_N];              // Minimum cost to reach each city
bool visited[MAX_N];          // Visited array for Dijkstra
// Function to add edges for bus i using BFS
void build_graph_with_bus(int start_city, int max_distance, int bus_cost) {
    vector<int> depth(n + 1, -1); // Track distances from start_city
    queue<int> q;
    q.push(start_city);
    depth[start_city] = 0;
    while (!q.empty()) {
        int current_city = q.front();
        q.pop();
        // Stop if we have reached the maximum distance
        if (depth[current_city] == max_distance) continue;
        for (int neighbor : adj[current_city]) {
            if (depth[neighbor] == -1) {
                depth[neighbor] = depth[current_city] + 1;
                q.push(neighbor);
                graph[start_city].emplace_back(neighbor, bus_cost);
            }
        }
    }
}
// Dijkstra's algorithm to find the shortest path from city 1 to city n
int find_min_cost() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist, dist + n + 1, INF);
    dist[1] = 0; // Start from city 1
    pq.emplace(0, 1);

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        int current_cost = current.first;
        int current_city = current.second;
        pq.pop();
        if (visited[current_city]) continue;
        visited[current_city] = true;
        for (auto next : graph[current_city]) {
            int next_city = next.first;
            int cost = next.second;
            if (dist[next_city] > dist[current_city] + cost) {
                dist[next_city] = dist[current_city] + cost;
                pq.emplace(dist[next_city], next_city);
            }
        }
    }
    return dist[n] == INF ? -1 : dist[n]; // Return -1 if city n is unreachable
}
int main() {
    // Input
    freopen("ex.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Build graph for each city's bus
    for (int i = 1; i <= n; i++) {
        build_graph_with_bus(i, D[i], C[i]);
    }
    // Find the minimum cost to travel from city 1 to city n
    cout << find_min_cost() << endl;
    return 0;
}
