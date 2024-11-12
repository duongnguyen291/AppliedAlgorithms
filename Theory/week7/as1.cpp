#include <bits/stdc++.h>
using namespace std;


int main(){
    // freopen("Homework.txt","r",stdin);
    int n;
    cin >> n;
    int X[n+1];
    for(int i = 0; i < n; i++){ cin >> X[i];}
    int low = 0, high = n - 1;
    while(low < high){
        int mid = (low + high ) / 2;
        if(X[mid] == 0){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    if(X[low] == 0){
        cout << -1 << endl;
    }
    else{
        cout << low << endl;
    }
    return 0;
}