// Parallel Job Execution 
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("ex2.txt","r",stdin);
    int n;
    cin >> n;
    int d[n];
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    sort(d,d+n);

    int res = 0;
    res+=d[n-1];
    int ite = 1;
    for(int i = n-2; i > 0; i--){
        if(ite + d[i] > res){
            res = ite+d[i];
        }
        ite++;
    }
    cout << res <<endl;
    return 0;
}