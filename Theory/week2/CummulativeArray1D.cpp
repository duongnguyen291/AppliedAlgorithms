#include <bits/stdc++.h>
using namespace std;
int a[100002];
int S[100002];


int main(){
    freopen("CummulativeArray1D.txt","r",stdin);
    int n,q;
    cin >> n;
    S[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        S[i+1] = S[i] + a[i];

    }
    cin >> q;
    int i=0,j=0;
    // for(int i = 0; i <= n; i++){
    //     cout << S[i] << endl;
    // }
    for(int k = 0; k < q; k++){
        cin >> i >> j;
        cout << S[j] - S[i-1] << endl;
    }


    return 0;
}