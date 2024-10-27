#include <iostream>
#include <vector>
using namespace std;

const int MOD = 100000;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

long long pow_mod(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long stirling2(int n, int k) {
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            dp[j] = (dp[j - 1] + (j * dp[j]) % MOD) % MOD;
        }
    }
    return dp[k];
}

int main() {
    freopen("ex1.txt","r",stdin);
    int N, K;
    cin >> N >> K;

    long long result = (stirling2(N, K) * factorial(K)) % MOD;
    cout << result << endl;

    return 0;
}