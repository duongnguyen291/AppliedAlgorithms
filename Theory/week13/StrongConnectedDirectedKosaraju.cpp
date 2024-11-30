#include <bits/stdc++.h>
using namespace std;
const int MAXX = 100001; 
vector<int> adj[MAXX], rev_adj[MAXX];  // Đồ thị ban đầu và nghịch đảo
bool visited[MAXX]; 
stack<int> s;

void dfs1(int u ){
    visited[u] = true; //đánh dấu đỉnh u đã được thăm
    for(int v : adj[u]){ // Duyệt qua các đỉnh kề của u
        if(!visited[v]){ // nếu đỉnh kề của u chưa được duyệt qua
            dfs1(v); // thì dfs vào đỉnh đó
        }
    }
    s.push(u); // sau khi duyệt qua hết thì quay về đặt u vào stack
}
void dfs2(int u){
    visited[u] = true;
    for(int v : rev_adj[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }

}
int main(){
    freopen("ex1.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u); // Đồ thị nghịch đảo
    }
    fill(visited, visited + n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs1(i); // dfs từng đỉnh một
        }
    }
    
    fill(visited, visited + n + 1, false);
    int sccCount = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u]){
            dfs2(u);
            sccCount++;
        }
    }
    cout << sccCount << endl;
    return 0;
}