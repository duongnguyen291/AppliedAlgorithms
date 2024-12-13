#include <bits/stdc++.h>
using namespace std;


typedef pair<int, long long> Edge;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("ex3.txt","r",stdin);
    int n;
    cin >> n;
    vector<vector<Edge>> tree(n+1, vector<Edge>());
    
    for(int i=0; i<n-1; ++i){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    vector<long long> count_(n+1, 0);
    vector<long long> dp(n+1, 0);
    vector<long long> f(n+1, 0);

    typedef tuple<int, int, bool> StackElement;
    stack<StackElement> s;
    s.emplace(1, -1, false); 
    
    while(!s.empty()){
        StackElement current = s.top();
        s.pop();
        
        int node = get<0>(current);
        int parent = get<1>(current);
        bool visited = get<2>(current);
        
        if(visited){
            count_[node] = 1;
            long long total = 0;
            for(auto it = tree[node].begin(); it != tree[node].end(); ++it){
                int neighbor = it->first;
                long long w = it->second;
                if(neighbor != parent){
                    count_[node] += count_[neighbor];
                    total += dp[neighbor] + count_[neighbor] * w;
                }
            }
            dp[node] = total;
        }
        else{
            s.emplace(node, parent, true);
            for(auto it = tree[node].begin(); it != tree[node].end(); ++it){
                int neighbor = it->first;
                long long w = it->second;
                if(neighbor != parent){
                    s.emplace(neighbor, node, false);
                }
            }
        }
    }

    long long max_f = 0;
    stack<pair<int, int>> s2;
    s2.emplace(1, -1);
    f[1] = dp[1];
    max_f = f[1];
    
    while(!s2.empty()){
        pair<int, int> current = s2.top();
        s2.pop();
        
        int node = current.first;
        int parent = current.second;
        
        for(auto it = tree[node].begin(); it != tree[node].end(); ++it){
            int neighbor = it->first;
            long long w = it->second;
            if(neighbor != parent){
                f[neighbor] = f[node] - (count_[neighbor] * w) + ((long long)(n - count_[neighbor]) * w);
                if(f[neighbor] > max_f){
                    max_f = f[neighbor];
                }
                s2.emplace(neighbor, node);
            }
        }
    }
    
    cout << max_f;
}
