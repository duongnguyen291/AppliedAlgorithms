#include <bits/stdc++.h>
using namespace std;

// Hàm tính khoảng cách Euclidean giữa hai điểm
double distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + 
                (p1.second - p2.second) * (p1.second - p2.second));
}

// Tìm khoảng cách nhỏ nhất giữa các điểm trong dải (strip)
double closest_strip(vector<pair<int, int>>& strip, double d) {
    double min_d = d;
    sort(strip.begin(), strip.end(), [](auto& a, auto& b) {
        return a.second < b.second;  // Sắp xếp theo tọa độ y
    });

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < min_d; ++j) {
            min_d = min(min_d, distance(strip[i], strip[j]));
        }
    }
    return min_d;
}

// Hàm Chia để trị để tìm khoảng cách nhỏ nhất
double closest_pair(vector<pair<int, int>>& points, int left, int right) {
    if (right - left <= 3) {
        double min_d = DBL_MAX;
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j < right; ++j) {
                min_d = min(min_d, distance(points[i], points[j]));
            }
        }
        return min_d;
    }

    int mid = left + (right - left) / 2;
    pair<int, int> mid_point = points[mid];

    // Tìm khoảng cách nhỏ nhất bên trái và bên phải
    double dl = closest_pair(points, left, mid);
    double dr = closest_pair(points, mid, right);
    double d = min(dl, dr);

    // Tạo dải các điểm gần đường chia có khoảng cách x nhỏ hơn d
    vector<pair<int, int>> strip;
    for (int i = left; i < right; ++i) {
        if (abs(points[i].first - mid_point.first) < d) {
            strip.push_back(points[i]);
        }
    }

    // Tìm khoảng cách nhỏ nhất trong dải
    return min(d, closest_strip(strip, d));
}

// Hàm chính
double find_closest_pair(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end());  // Sắp xếp theo tọa độ x
    return closest_pair(points, 0, points.size());
}

int main() {
    freopen("ex2.txt","r",stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Tìm khoảng cách nhỏ nhất và in ra kết quả với 6 chữ số sau dấu thập phân
    double result = find_closest_pair(points);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
