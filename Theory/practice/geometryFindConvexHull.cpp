#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

// Global point needed for sorting points
Point bottomPoint;
// Returns the square of distance between two points
long long distSq(Point p1, Point p2) {
    return 1LL * (p1.x - p2.x) * (p1.x - p2.x) + 
           1LL * (p1.y - p2.y) * (p1.y - p2.y);
}
// Returns orientation of triplet (p, q, r)
// 0 --> Collinear
// 1 --> Clockwise
// -1 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
    long long val = 1LL * (q.y - p.y) * (r.x - q.x) - 
                    1LL * (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}
// Comparison function used to sort points
bool comparePoints(Point &p1, Point &p2) {
    int orient = orientation(bottomPoint, p1, p2);
    if (orient == 0)
        return distSq(bottomPoint, p1) < distSq(bottomPoint, p2);
    return orient == -1;
}
// Function to find convex hull
vector<Point> findConvexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return points;
    // Find the bottommost point (and leftmost if tied)
    int bottomIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[bottomIdx].y ||
           (points[i].y == points[bottomIdx].y && 
            points[i].x < points[bottomIdx].x)) {
            bottomIdx = i;
        }
    }
    // Place the bottom point at first position
    swap(points[0], points[bottomIdx]);
    bottomPoint = points[0];

    // Sort remaining points based on polar angle and distance
    sort(points.begin() + 1, points.end(), comparePoints);

    // Initialize result with first three points
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    // Process remaining points
    for (int i = 2; i < n; i++) {
        while (hull.size() > 1 && 
               orientation(hull[hull.size()-2], 
                         hull[hull.size()-1], 
                         points[i]) != -1) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}
int main() {
    // Read input
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    // Find convex hull
    vector<Point> hull = findConvexHull(points);
    // Output results
    cout << hull.size() << endl;
    for (const Point& p : hull) {
        cout << p.x << " " << p.y << endl;
    }
    return 0;
}