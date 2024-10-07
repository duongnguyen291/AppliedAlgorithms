#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, K, Q;
vector<int> demand;
vector<vector<int>> dist;
int bestDistance = INT_MAX;

vector<int> visited;
vector<int> load;
int f = 0;
int f_star = INT_MAX;

void tryRoute(int vehicle, int client, int routeDistance) {
    if (vehicle == K + 1) {
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) return;
        }
        bestDistance = min(bestDistance, routeDistance);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && load[vehicle] + demand[i - 1] <= Q) {
            visited[i] = true;
            load[vehicle] += demand[i - 1];

            int distToNext = dist[client][i] + dist[i][0];
            tryRoute(vehicle, i, routeDistance + distToNext);

            visited[i] = false;
            load[vehicle] -= demand[i - 1];
        }
    }

    tryRoute(vehicle + 1, 0, routeDistance);
}

int main() {
    freopen("truck.txt","r",stdin);
    cin >> n >> K >> Q;
    demand.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> demand[i];
    }

    dist.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    visited.resize(n + 1, false);
    load.resize(K + 1, 0);

    tryRoute(1, 0, 0);

    cout << bestDistance << endl;

    return 0;
}
