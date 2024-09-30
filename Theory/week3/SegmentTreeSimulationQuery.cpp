
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
int st[N << 2] = {0}; // Segment tree trong array

void sol (int x, int l, int r) {
    // Tổ chức Segment trên array
    if(l == r) {
        st[x] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    sol(x << 1, l, mid); // x << 1 = 2 * x
    sol(x << 1 | 1, mid + 1, r); // x << 1 | 1 = 2*x + 1
    st[x] = max(st[x << 1], st[x << 1 | 1]); //Lưu giá trị nhỏ nhất của mỗi đoạn mà nó đại diện
}
void update(int x, int l, int r, int i, int val) {
    if(i < l || i > r) return; 
    if(l == r) { 
        st[x] = val; 
        return;
    }
    int mid = (l + r) >> 1; 
    int leftChild = x << 1;
    int rightChild = x << 1 | 1; 
    update(leftChild, l, mid, i, val);
    update(rightChild, mid + 1, r, i, val);
    st[x] = max(st[leftChild], st[rightChild]);
}

int getAns (int x, int l, int r, int u, int v) {
    if(u > r || v < l) return -1;
    if(u <= l && r <= v) return st[x];
    
    int mid = (l + r) >> 1;
    int x1 = getAns(x << 1, l, mid, u, v);
    int x2 = getAns(x << 1 | 1, mid + 1, r, u, v);
    return max(x1, x2);
}

int main() {
    freopen("ex1.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    sol(1, 1, n);
    int numberQuery;
    cin >> numberQuery;
    for(int i = 0; i < numberQuery; i++){
        string command;
        cin >> command;
        int u,v;
        if( command == "get-max"){
            cin >> u >> v;
            cout << getAns(1,1,n,u,v) << endl;
        }
        else if( command == "update"){
            cin >> u >> v;
            update(1,1,n,u,v);
        }
    }
    return 0;
}
