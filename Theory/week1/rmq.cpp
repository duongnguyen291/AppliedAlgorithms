#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
//Sử dụng Segment tree

const int N = 1000002;

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
     
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int a[N], n, m; // Mảng gốc
int st[N << 2]; // Segment tree trong array

void sol (int x, int l, int r) {
    // Tổ chức Segment trên array
    if(l == r) {
        st[x] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    sol(x << 1, l, mid);
    sol(x << 1 | 1, mid + 1, r);
    st[x] = min(st[x << 1], st[x << 1 | 1]); //Lưu giá trị nhỏ nhất của mỗi đoạn mà nó đại diện
}

int getAns (int x, int l, int r, int u, int v) {
    if(u > r || v < l) return INT_MAX;
    if(u <= l && r <= v) return st[x];
    
    int mid = (l + r) >> 1;
    int x1 = getAns(x << 1, l, mid, u, v);
    int x2 = getAns(x << 1 | 1, mid + 1, r, u, v);
    return min(x1, x2);
}

int main() {
    // freopen("RangeMinimumQuery.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    sol(1, 1, n);
    
    long long ans = 0;
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        l++; r++;
        ans += getAns(1, 1, n, l, r);
    }
    
    cout << ans;
    return 0;
}
