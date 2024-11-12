#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNonOverlappingSegments(vector<pair<int, int>>& segments) {
    sort(segments.begin(), segments.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    
    int count = 0;
    int last_end = -1;
    
    for (const auto& segment : segments) {
        int start = segment.first;
        int end = segment.second;
        if (start > last_end) {
            count++;
            last_end = end;
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> segments(n);
    
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    cout << maxNonOverlappingSegments(segments) << endl;
    
    return 0;
}
