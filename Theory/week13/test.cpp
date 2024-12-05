#include <bits/stdc++.h>
using namespace std;
struct Node{
    int u,v,w;
};
vector<Node> adj;
vector<int> parent;
void addEdge(int i, int u, int v, int w){
    adj[i].u = u;
    adj[i].v = v;
    adj[i].w = w;
}
int findParent(int u){
    if(parent[u]!=u){
        parent[u] = findParent(parent[u]);
    }
    return parent[u];
}

int main(){
    freopen("ex2.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    adj.resize(m);
    parent.resize(n+1);
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        addEdge(i,u,v,w);
    }
    sort(adj.begin(),adj.end(),[](const Node& a,const Node& b){
        return a.w < b.w;
    });
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    int res = 0;
    for(int i = 0; i < m; i++){
        int u = adj[i].u;
        int v = adj[i].v;
        int w = adj[i].w;
        if(findParent(u) != findParent(v)){ // khong tao thanh cycle
            res += w;
            parent[findParent(u)] = findParent(v);
        }
    }
    cout << res << endl;
    return 0;
}