#include <bits/stdc++.h>
using namespace std;
#define MAXX 100001
int n,l,w[MAXX],v[MAXX];
int mem[101][101];
// Base case:
// K[i,0] = 0 with i=1,n
// K[0,l] = 0 with l = 1,l
int KP(int i, int l){
    if(i == 0 || l == 0) return 0;
    if(mem[i][l] != -1) return 0;
    if(w[i] > l) {
        mem[i][l] = KP(i-1,l); 
    }
    else{
        mem[i][l] = max(KP(i-1,l),v[i] + KP(i-1,l-w[i]));
    }
    return mem[i][l];
}
int main(){
    freopen("ex1.txt","r",stdin);
    cin >> n >> l;
    for(int i = 0; i < n; i++)
    memset(mem,-1,sizeof(mem));
    for(int i = 0; i < n; i++){mem[i][0] = 0;}
    for(int i=0; i < l; i++){mem[0][l] = 0;}

    int res = KP(n-1,l);


    return 0;
}