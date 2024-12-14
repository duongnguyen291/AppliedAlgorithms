#include <bits/stdc++.h>
using namespace std;
#define MAXX 21
int adj[MAXX][MAXX];
int minF = INT_MAX;
int visited[MAXX];
int n;
int current_cost = 0;
int cmin = INT_MAX;
int x[MAXX] = {1};

void sol(int k){
    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            x[k] = i;
            current_cost += adj[x[k-1]][x[k]];
            visited[i] = 1;
            if(k == n){
                minF =  minF > current_cost + adj[i][1] ? current_cost + adj[i][1] : minF;
            }
            else{
                if(current_cost + (n - k + 1) * cmin < minF){
                    sol(k+1);
                }
            }
            current_cost -= adj[x[k-1]][x[k]];
            visited[i] = 0;
        }
    }
}
int main(){
    freopen("ex1.txt","r",stdin);
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> adj[i][j]; 
            cmin = min(cmin,adj[i][j]);
        }
    }
    sol(1);
    cout << minF << endl;
    return 0;
}