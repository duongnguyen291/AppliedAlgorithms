#include <bits/stdc++.h>
using namespace std;
int findMin(int *arr, int a, int b){
    int min = INT_MAX;
    for(int i = a-1; i < b ; i++){
        if(min > arr[i]){ min = arr[i];}
    }
    return min;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    freopen("RangeMinimumQuery.txt","r",stdin);
    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    long res = 0;
    for(int j = 0; j < m; j++){
        int a,b;
        cin >> a >> b; 
        int temp =  findMin(arr,a,b);
        // cout << "Range [" <<a << ","<< b << "]:" << temp << endl;
        res += temp;
    }
    cout << res << endl;
    return 0;
}