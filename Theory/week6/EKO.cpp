#include <bits/stdc++.h>
using namespace std;
#define MAXX 1000
int n;
int p[MAXX+1];
int dp[MAXX+1];
int sol(int n, int p[], int dp[]){
    for(int i = 1; i<=n; i++){
        int max_val = 0;
        for(int j = 1; j <= i; j++){
            max_val = max(max_val, p[j-1] + dp[i - j]);
        }
        dp[i] = max_val;
    }
    return dp[n];
}
int main(){
    freopen("eko.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){cin >> p[i];}
    int res = sol(n, p, dp);
    for(int i = 0; i <= n; i++){cout << dp[i] << " ";}
    cout << "\n";
    cout << res << endl;
    return 0;
}