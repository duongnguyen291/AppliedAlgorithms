#include <bits/stdc++.h>
using namespace std;
#define MAXX 100001
struct Edges{
    int v,w;
};
vector<Edges> adj[MAXX];
vector<bool> visited;
vector<int> dist;
vector<int> sumTreeSum;
queue<int> q;
int n;

// void DFS(int u, int parent){
//     visited[u] = true;
//     for(const auto &edge : adj[u]){
//         int v = edge.v;
//         int w = edge.w;
//         if(!visited[v]){    
//             dist[v] = dist[u] + w; 
//             DFS(v,u); 
//         }
//     }
// }
void DFS(int u){
    
}
int main(){
    freopen("ex3.txt","r",stdin);
    int maxF = -1;
    cin >> n;

    visited.resize(n+1, false);
    sumTreeSum.resize(n+1,0);

    for(int i = 1; i < n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w}); // 1->2 = 1
        adj[v].push_back({u,w}); // 2->1 = 1
    }
    dist[1] = 0;
    for(auto &a : dist){
        
    }    
    cout << "Khong chay dc den dau";
    cout << maxF << endl;
    return 0;
}