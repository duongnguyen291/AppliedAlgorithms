#include <bits/stdc++.h>
using namespace std;
int dodai(int x, int y){
    return sqrt(x*x + y*y);
}
int main(){
    int xO,yO,xA,yA,xB,yB;
    cin >> xO >> yO >> xA >> yA >> xB >> yB;
    int xOA = xA - xO;
    int yOA = yA - yO;
    int xOB = xB - xO;
    int yOB = yB - yO;
    // int res = dodai(xOA,yOA) * dodai(xOB,yOB);
    int res = xOA * yOB - xOB * yOA;
    cout << res << endl;


    return 0;
}