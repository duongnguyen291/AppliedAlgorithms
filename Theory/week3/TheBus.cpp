#include <bits/stdc++.h>
using namespace std;
int n, k, load, cmin = INT_MAX, fopt = INT_MAX, x[25], f;
int visited[25] = {0}; 
int c[30][30];

bool UCV(int i) {
    if (visited[i] == 1) return false;
    if (i > n) {  
        if (visited[i - n] == 0) return false;  
    } else { 
        if (load + 1 > k) return false;  
    }
    return true;
}

void updateBest() {
    int temp = f + c[x[2 * n]][0]; 
    if (temp < fopt) {
        fopt = temp;
    }
}

void Try(int k) {
    for (int i = 1; i <= 2 * n; i++) {
        if (UCV(i)) {
            x[k] = i;
            visited[i] = 1; 
            f += c[x[k - 1]][x[k]]; 
            if (i <= n) load++; else load--; 
            if (k == 2 * n) updateBest();
            else {
                int g = f + ((2 * n + 1 - k) * cmin);
                if (g < fopt) Try(k + 1);
            }
            if (i <= n) load--; else load++; 
            f -= c[x[k - 1]][x[k]];
            visited[i] = 0; 
        }
    }
}

int main() {
    // freopen("bus.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cin >> c[i][j];
            if (i != j && cmin > c[i][j]) cmin = c[i][j];
        }
    }
    load = 0; x[0] = 0; f = 0;
    Try(1);
    cout << fopt << endl;

    return 0;
}
