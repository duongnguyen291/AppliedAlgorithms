#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;
    
    vector<int> d(n);  // Sử dụng vector thay cho mảng tĩnh
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    int res = 0;
    sort(d.begin(), d.end());  // Sử dụng cú pháp đúng của hàm sort
    
    for(int i = n - 1; i >= 0; i--) {
        if(X >= d[i]) {  // Cần sửa thành >= thay vì chỉ >
            int temp = X / d[i];
            res += temp;
            X -= temp * d[i];
        }
    }

    if(X > 0) {
        cout << -1 << endl;  // Nếu X không thể chia hết cho các phần tử trong d, in -1
    } else {
        cout << res << endl;
    }

    return 0;
}
