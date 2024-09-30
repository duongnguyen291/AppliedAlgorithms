#include <bits/stdc++.h>
using namespace std;
int n, k, load, cmin = INT_MAX, fopt = INT_MAX, x[25],f;
int visited[25] = {0};
int c[30][30];
// void Try(int k){
//     for(int i = 1; i <= 2*n; i++){
//         if(UCV(i)){
//             x[k] = 1;
//             visited[k]=1;
//             if(i<=n) load++; else load++;
//             f+= c[x[k-1]][x[k]];
//             if(k==2*n) updateBest();
//             else{
//                 int g = f + (2*n+1-k)*cmin;
//                 if(g < fopt) Try(k+1);
//             }
//         }
        
//     }
// }
int main(){
    // freopen("Homework.txt","r",stdin);
    cin >> n >> k;
    for(int i = 0; i < 2*n+1; i++ ){
        for(int j = 0; j < 2*n+1; j++){
            cin >> c[i][j];
            if (i!=j && cmin > c[i][j]) cmin = c[i][j];
        }
    }
    load = 0; x[0] = 0; f=0;
    // Try(1);


    return 0;
}