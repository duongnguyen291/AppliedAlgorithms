#include <bits/stdc++.h>
using namespace std;
#define MAX 50
int n,K,Q;
int y[MAX], x[MAX],visited[MAX],c[MAX][MAX],d[MAX],load[MAX];
int f,fopt = INT_MAX,segment,cmin,numberR;

bool checkX(int v,int k){
    if(v==0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

void TryX(int s, int k){
    if(s == 0){
        if(k == K) return;
        TryX(y[k+1],k+1);
    }else{
        for(int v = 0; v <= n; v++){
            if(checkX(v,k)){
                x[s] = v;visited[v]=1;f+=c[s][v];load[k]+=d[v];segment++;
                if(v>0){
                    int lowerB = f + (n+numberR-segment)*cmin;
                    if(lowerB < fopt) TryX(v,k);
                }else{
                    if(k==K){
                        if(segment==n+numberR){
                            if(f < fopt) fopt = f;
                        }
                    }else{
                        int lowerB = f + (n + numberR - segment) * cmin;
                        if(lowerB < fopt)  TryX(y[k+1],k+1);
                    }
                    visited[v]=0;f-=c[s][v];load[k]-=d[v];segment--;
                }
            }
        }
    }
}
bool checkY(int v,int k){
    if(v == 0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}
void TryY(int k){
    int s = 0;
    if(y[k-1] > 0) s = y[k-1] + 1;
    for(int v = s; v <= n; v++){
        if(checkY(v,k)){
            y[k] = v;
            if(v>0){visited[v]=1;f+=c[0][v];load[K]+=d[v];segment++;}
        }
        if(k == K){
            numberR = segment;
            TryX(y[1],1);
        }
        else{
            TryY(k+1);
        }
        if(v > 0){
            visited[v]=0;f-=c[0][v];load[K]-=d[v];segment--;
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
