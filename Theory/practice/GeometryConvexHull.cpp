#include <bits/stdc++.h>
using namespace std;

// Struct to represent a point
struct Point {
    int x;
    int y;
    Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
};

// Function to compute the cross product of three points
int crossProduct(int xA, int yA, int xB, int yB, int xC, int yC) {
    return (xB - xA) * (yC - yA) - (yB - yA) * (xC - xA);
}

// Function to check if a sequence of points forms a convex hull
bool isConvexHull(const vector<Point>& points) {
    int n = points.size();
    if (n < 3) return false; // At least 3 points are needed for a convex hull

    // Check if all cross products have the same sign
    bool isPositive = false, isNegative = false;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        int cross = crossProduct(points[i].x, points[i].y, points[j].x, points[j].y, points[k].x, points[k].y);
        if (cross > 0) isPositive = true;
        if (cross < 0) isNegative = true;

        // If both positive and negative cross products exist, it's not a convex hull
        if (isPositive && isNegative) return false;
    }

    return true;
}

int main() {
    freopen("ex.txt","r",stdin);
    int T; // Number of test cases
    cin >> T;

    vector<int> results(T); // Store results for each test case
    for (int t = 0; t < T; t++) {
        int n; // Number of points in this test case
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
  
        // Check if the points form a convex hull
        results[t] = isConvexHull(points) ? 1 : 0;
    }

    // Output results for all test cases
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
