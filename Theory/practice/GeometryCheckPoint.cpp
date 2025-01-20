#include <bits/stdc++.h>
using namespace std;

bool onSegment(int xA,int yA, int xB, int yB, int x, int y){
    return ( x <= max(xA, xB) && x >= min(xA, xB) && y <= max(yA, yB) && y >= min(yA, yB) );
}
int checkPoint(int xA, int yA, int xB, int yB, int xC, int yC) {
    int val = (yB-yA) * (xC-xB) - (xB - xA) * (yC - yB); 
    if(val == 0 && onSegment(xA,yA,xB,yB,xC,yC)) return 1;
    return 0;
}
int main(){
    int n;
    cin >> n;
    int a[n+2];
    int toado[n+2][10];
    for(int i = 0; i < n; i++){
        cin >> toado[i][1] >> toado[i][2] >> toado[i][3] >> toado[i][4] >> toado[i][5] >> toado[i][6];
    }
    for(int i = 0; i < n; i++){
        cout << checkPoint(toado[i][3], toado[i][4],toado[i][5],toado[i][6],toado[i][1] ,toado[i][2])<< endl;
    }
    return 0;
}