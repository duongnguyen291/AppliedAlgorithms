#include <bits/stdc++.h>
using namespace std;

int count_solutions(int n, int M, vector<int>& a) {
    int sum_a = 0;
    for (int i = 0; i < n; ++i) {
        sum_a += a[i];
    }

    M -= sum_a;
    if (M < 0) {
        return 0;
    }
    vector<int> dp(M + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j <= M; ++j) {
            dp[j] += dp[j - a[i]];
        }
    }
    return dp[M];
}
int main(){
    freopen("ex1.txt","r",stdin);
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
        cout << count_solutions(n, M, a) << endl;
    
    return 0;
}