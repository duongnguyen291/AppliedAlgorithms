#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = -1;  
    int sum = 0;  
    int L = 0;   

    for (int R = 0; R < n; ++R) {
        sum += a[R]; 
        while (sum > Q && L <= R) {
            sum -= a[L];
            L++;
        }
        if (sum <= Q) {
            res = max(res, R - L + 1);
        }
    }
    cout << (res == -1 ? -1 : res) << endl;

    return 0;
}
