#include <bits/stdc++.h>
using namespace std;

int minDif(int a[], int dif, int n, int check[]){
    int minDif = INT_MAX; // Set to max int value initially
    int index = -1;
    // cout << "Dif: " << dif << endl;
    for(int i = 0; i < n; i++){
        if(abs(a[i] - dif) <= minDif && check[i] == 0){
            minDif = abs(a[i] - dif);
            index = i;
        }
    }
    if(index != -1){
        // cout << "Res: " << a[index] << endl;
        check[index] = 1;
        return a[index];
    }
    return 0; // Return 0 if no valid element is found
}

int sol(int n, int arr[]){
    int a = 0, b = 0;
    int check[n] = {0};
    a += arr[n-1]; b += arr[n-2];
    check[n-1] = 1;
    check[n-2] = 1;
    int sole = a <= b ? 0 : 1;
    for(int i = 0; i < n - 2; i++){
        if(sole % 2 == 0){
            int temp  = minDif(arr, abs(a - b), n, check);
            // cout << "A: " << temp << endl;
            a += temp;
            sole++;
        } else {
            int temp  = minDif(arr, abs(a - b), n, check);
            // cout << "B: " << temp << endl;
            b += temp;
            sole++;
        }
    }
    return abs(a - b); // Return the absolute difference
}

int main(){
    freopen("test1.txt","r",stdin);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int res = sol(n, a);
    cout << res << endl;
    return 0;
}
