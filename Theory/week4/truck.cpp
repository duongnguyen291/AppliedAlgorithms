#include <bits/stdc++.h>
using namespace std;

#define MAX 50
int n, K, Q;
int y[MAX], x[MAX], segments = 0, nbR = 0;
int c[MAX][MAX], f = 0, fopt = INT_MAX, visited[MAX], d[MAX], load[MAX];
int cmin = INT_MAX;

bool checkX(int v, int k) {
    if (v == 0) return true;
    if (visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

void TryX(int s, int k) {
    if (s == 0) { // back to depot
        if (k == K) return; // all trucks checked
        TryX(y[k + 1], k + 1); // move to next truck
    } else {
        for (int v = 0; v <= n; v++) {
            if (checkX(v, k)) {
                x[s] = v;
                visited[v] = true;
                f += c[s][v]; // update total cost
                load[k] += d[v];
                segments++;
                if (v > 0) { // still visiting clients
                    int lowerB = f + (n + nbR - segments) * cmin;
                    if (lowerB < fopt) TryX(v, k); // only continue if promising
                } else { // back to depot, complete this truck's route
                    if (k == K) {
                        if (segments == n + nbR) {
                            if (f < fopt) fopt = f; // update optimal cost
                        }
                    } else {
                        int lowerB = f + (n + nbR - segments) * cmin;
                        if (lowerB < fopt) TryX(y[k + 1], k + 1); // next truck
                    }
                }
                // backtrack
                visited[v] = false;
                f -= c[s][v];
                load[k] -= d[v];
                segments--;
            }
        }
    }
}

bool checkY(int v, int k) {
    if (v == 0) return true;
    if (visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

void TryY(int k) {
    int s = 0;
    if (y[k - 1] > 0) s = y[k - 1] + 1;
    for (int v = s; v <= n; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0) {
                visited[v] = 1;
                f += c[0][v];
                load[k] += d[v];
                segments++;
            }
            if (k == K) {
                nbR = segments;
                TryX(y[1], 1); // start trying truck routes
            } else {
                TryY(k + 1);
            }
            if (v > 0) {
                visited[v] = 0;
                f -= c[0][v];
                load[k] -= d[v];
                segments--;
            }
        }
    }
}

int main() {
    cin >> n >> K >> Q; 
    for (int i = 1; i <= n; i++) cin >> d[i];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (i != j && c[i][j] < cmin) cmin = c[i][j]; // calculate minimum distance
        }
    }

    TryY(1); // start with truck 1
    cout << fopt << endl;

    return 0;
}
