#include <bits/stdc++.h>
using namespace std;
const int N = 21;
const int INF = INT_MAX;
int n;
int C[N][N], mem[N][1 << N];
int TSP(int i, int S){
    if(S == (1 << n) - 1) return mem[i][S] = C[i][0];
    if(mem[i][S] != -1 ) return mem[i][S];
    int res = INF;
    for(int j = 0; j < n; ++j){
        if (S & (1 << j)) continue;
        if(C[i][j] != INF){
            res = min(res,C[i][j] + TSP(j, S | (1 << j)));
        }
    }
    return mem[i][S] = res;
}

int main(){
    freopen("ex2.txt","r",stdin);
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        cin >> C[i][j];
        
        }
    }
    memset(mem, -1, sizeof(mem));
    int res = TSP(0, 1);
    cout << res << endl;

    return 0;
}