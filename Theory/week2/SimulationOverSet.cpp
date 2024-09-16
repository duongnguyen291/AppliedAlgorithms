#include <iostream>
#include <set>

using namespace std;

int main() {
    freopen("SimulationOverSet.txt","r",stdin);
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        S.insert(num);
    }
    string operation;

    while (cin >> operation && operation != "#") {
        if (operation == "min_greater_equal") {
            int v;
            cin >> v;
            auto it = S.lower_bound(v);
            if (it != S.end()) {
                cout << *it << endl;
            } else {
                cout << "NULL" << endl;
            }
        } 
        else if (operation == "min_greater") {
            int v;
            cin >> v;
            auto it = S.upper_bound(v);
            if (it != S.end()) {
                cout << *it << endl;
            } else {
                cout << "NULL" << endl;
            }
        } 
        else if (operation == "insert") {
            int v;
            cin >> v;

            S.insert(v);
        } 
        else if (operation == "remove") {
            int v;
            cin >> v;
            S.erase(v);
        }
    }

    return 0;
}
