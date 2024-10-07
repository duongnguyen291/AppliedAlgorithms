#include <bits/stdc++.h>
using namespace std;
#define MAX 50
int n,K,Q,y[MAX],x[MAX],segments = 0,nbR = 0,c[MAX][MAX],f = 0,fopt=INT_MAX,visited[MAX],d[MAX],load[MAX];
int cmin = INT_MAX;
void TryX(int s, int k){
    if(s == 0){
        if(k ==K) return;
        TryX(y[k+1],k+1);
    }
    else{
        for(int v = 0; v <=n; v++){
            if(checkX(v,k)){
                x[s] = v;
                visited[v] =true; f+=c[s][v];load[k]+=d[v];segments++;
                if( v > 0){
                    int lowerB = f + (n+nbR - segments)* cmin;
                    if(lowerB < fopt) Try(v,k);
                }
                else{ //v = 0 truck back to warehouse
                    if(k == K ){
                        if(segments==n+nbR){if(f<fopt) fopt=f;}

                    }
                    else{
                        int lowerB = f+(n+nbR-segments)*cmin;
                        if(lowerB<fopt) TryX(y[k+1],k+1);
                    }

                }
                visited[v] =false;f-=c[s][v];load[k]-=d[v];segments--;
            }
        }
    }
}
bool checkY(int v, int k){
    if(v==0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}
void TryY(int k){
    int s = 0;
    if(y[k-1] > 0) s = y[k-1]+1;
    for(int v = s; v <=n; v++){
        if(checkY(v,k)){
            y[k] = v; 
            if( v > 0){
                visited[v] = 1;
                f += c[0][v]; 
                load[k]+=d[v];
                segments++;
            }
            if(k==K){nbR=segments;TryX(y[1],1);}
            else TryY(k+1);
            if(v > 0){
                visited[v] = 0; f-=c[0][v]; load[k] -=d[v];segments--;
            }
        }
    }
}
int main(){
    cin >> n >> K >> Q; 
    for(int i = 1; i<=n; i++) cin >> d[i];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> c[i][j];
            if( i != j && cmin > c[i][j]) cmin = c[i][j]; 
        }
    }
    TryY(1);
    cout << fopt << endl;

    return 0;
}