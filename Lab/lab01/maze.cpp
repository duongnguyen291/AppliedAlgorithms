#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int visited[1000][1000];
int n,m,r,c;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
struct Point{
    int x;
    int y;
    int dist;
};
queue<Point> hangdoi;
bool valid(int r,int c){
    return (r>=1 && r <= n && c >= 1 && c <=m && a[r][c] == 0 && visited[r][c] == 0);
}
int sol(int r,int c){
    hangdoi.push({r,c,0});
    visited[r][c] = 1;
    while(!hangdoi.empty()){
        Point current = hangdoi.front();
        hangdoi.pop();
        int x = current.x;
        int y = current.y;
        int dist = current.dist;
        if(x == 1 || x == n || y == 1 || y == m){
            return dist+1;
        }
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(valid(new_x,new_y)){
                visited[new_x][new_y] = 1;
                hangdoi.push({new_x,new_y,dist+1});
            }
        }
    }
    return -1;
}
int main(){
    freopen("maze.txt","r",stdin);

    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int step = sol(r,c);
    cout << step << endl;
    return 0;
}