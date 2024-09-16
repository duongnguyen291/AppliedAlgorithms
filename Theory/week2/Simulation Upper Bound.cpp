#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        S.insert(num);
    }
    string query;
    while (cin >> query && query != "#") {
        if (query == "next") {
            int k;
            cin >> k;
            auto it = S.upper_bound(k);
            if (it != S.end()) {
                cout << *it << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
