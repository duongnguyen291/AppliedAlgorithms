#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    int count = 0;

    while (i < j) {
        int sum = a[i] + a[j];

        if (sum == M) {
            count++;
            i++;
            j--;
        } else if (sum < M) {
            i++;
        } else {
            j--;
        }
    }

    cout << count << endl;

    return 0;
}
