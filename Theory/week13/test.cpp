#include <bits/stdc++.h>
using namespace std;
#define MAXX 100001
vector<int> adj[MAXX], trans_adj[MAXX];
stack<int> s;
bool visited[MAXX];
void dfs1(int u){
    visited[u] = 1;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    s.push(u);
}
void dfs2(int u){
    visited[u] = 1;
    for(int v : trans_adj[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }

}
int main(){
    freopen("ex1.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        trans_adj[v].push_back(u);
    }
    fill(visited, visited + n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    fill(visited, visited + n + 1,false);
    int cnt = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u]){
            dfs2(u);
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}