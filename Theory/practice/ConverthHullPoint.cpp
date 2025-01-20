#include <bits/stdc++.h>
using namespace std;
struct Point{
    int x;
    int y;
    Point(int x1 = 0,int y1 = 0): x(x1), y(y1) {}
};

bool onSegment(int xA,int yA, int xB, int yB, int x, int y){
    return ( x <= max(xA, xB) && x >= min(xA, xB) && y <= max(yA, yB) && y >= min(yA, yB) );
}
int crossProduct(int xA, int yA, int xB, int yB, int xC, int yC) {
    return (xB - xA) * (yC - yA) - (yB - yA) * (xC - xA); 
}
bool isConvexHull(const vector<Point>& point){
    int n = point.size();
    if(n<3) return false;
    for(int i = 0; i < n; i++){
        int j = (i+1)%n; // chia dư để lúc về cuối sẽ back lại 2 điểm đầu 
        int k = (i+2)%n; // thành một vòng tròn
        if(crossProduct(point[i].x,point[i].y,point[j].x,point[j].y,point[k].x,point[k].y) <= 0){
            return false;
        }
    }
    return true;
}
bool isPointInside(const vector<Point> &hull, const Point& p){
    int n = hull.size();
    int windingNumber = 0;
    for(int i = 0; i < n; i++){
        const Point& p1 = hull[i];
        const Point& p2 = hull[(i+1)%n];
        //Kiểm tra điểm có nằm trên cạnh hay không
        if(crossProduct(p1.x, p1.y,p2.x,p2.y, p.x,p.y) == 0 
        && onSegment(p1.x, p1.y,p2.x,p2.y, p.x,p.y)){
            return true;
        }

        if (p1.y <= p.y) {  // p1 nằm dưới hoặc ngang p
            if (p2.y > p.y && crossProduct(p1.x, p1.y,p2.x,p2.y, p.x,p.y) > 0)  
            // p2 nằm trên p và rẽ trái
                windingNumber++;
        } else {  // p1 nằm trên p
            if (p2.y <= p.y && crossProduct(p1.x, p1.y,p2.x,p2.y, p.x,p.y) < 0)  
            // p2 nằm dưới hoặc ngang p và rẽ phải
                windingNumber--;
        }
    }
    return windingNumber != 0;
}
int main(){
    freopen("ex.txt","r",stdin);
    int n;
    cin >> n;
    vector<Point> hull(n);
    for(int i = 0; i < n; i++){
        cin >> hull[i].x >> hull[i].y;
    }
    int k;
    cin >> k;
    bool isConvext = isConvexHull(hull);
    for(int i = 0; i < k; i++){
        Point testPoint; 
        cin >> testPoint.x >> testPoint.y;
        if(isConvext && isPointInside(hull,testPoint)){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}