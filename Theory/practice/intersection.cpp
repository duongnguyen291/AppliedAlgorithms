#include <bits/stdc++.h>
using namespace std;
int orientation(int xA,int yA, int xB, int yB, int xC, int yC){
    int val = (yB-yA) * (xC-xB) - (xB - xA) * (yC - yB);
    if(val == 0) return 0;
    return (val > 0) ? 1:-1;
}
bool onSegment(int xA,int yA, int xB, int yB, int x, int y){
    return ( x <= max(xA, xB) && x >= min(xA, xB) && y <= max(yA, yB) && y >= min(yA, yB) );
}
bool doIntersection(int xA,int yA, int xB, int yB, int xC, int yC, int xD, int yD){
    int o1 = orientation(xA,yA,xB,yB,xC,yC); // A,B,C
    int o2 = orientation(xA,yA,xB,yB,xD,yD); // A,B,D
    int o3 = orientation(xC,yC,xD,yD,xA,yA); // C,D,A
    int o4 = orientation(xC,yC,xD,yD,xB,yB); // C,D,B

    if(o1!=o2 && o3 != o4){
        return true;
    }
    if(o1 == 0 && onSegment(xA,yA,xB,yB,xC,yC)) return true;
    if(o2 == 0 && onSegment(xA,yA,xB,yB,xD,yD)) return true;    
    if(o3 == 0 && onSegment(xC,yC,xD,yD,xA,yA)) return true;   
    if(o4 == 0 && onSegment(xC,yC,xD,yD,xB,yB)) return true;   
    return false;
}

int main(){
    freopen("ex.txt","r",stdin);
    int n;
    cin >> n;
    int a[n+1][9];
    int res[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5] >> a[i][6] >> a[i][7];
    }
    for(int i = 0; i < n; i++){
        cout << (doIntersection(a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6],a[i][7]) ? 1 : 0) << endl;
    }
    
}