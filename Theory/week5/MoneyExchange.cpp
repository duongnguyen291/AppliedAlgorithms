#include <bits/stdc++.h>
using namespace std;
int n, X, d[11],mem[10][100001];
int cnt[100001];
// mem[i][X]: Số đồng xu ít nhất nếu sử dụng i đồng xu đầu tiên để đạt đủ số tiền X
void trace(int i, int X){
    if(X == 0) return;
    if( i < 0 || X < 0) return;
    if(mem[i][X] == mem[i-1][X]) trace(i-1, X);
    else {
        cnt[i]++;
        trace(i, X - d[i]);
    }
}

long long opt(int i, int X){
    if(X == 0) return 0;
    if(i < 0 || X < 0) return INT_MAX;
    if(mem[i][X] == -1){
        int res = min(opt(i-1,X),1 + opt(i,X - d[i]));
        mem[i][X] = res;
    }
    return mem[i][X];
}
int main(){
    freopen("ex2.txt","r",stdin);
    cin >> n >> X;
    for(int i = 0; i < n; i++) cin >> d[i];
    memset(mem, -1, sizeof(mem));
    // mem[0][X] = 0;
    long long res = opt(n - 1, X);
    if (res == INT_MAX) cout << "-1" << endl;
    else cout << res << endl;

    trace(n - 1, X);
    for(int i = 0; i <= n - 1; ++i)
        cout << cnt[i] << " ";

    return 0;
}