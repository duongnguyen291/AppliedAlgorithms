#include <bits/stdc++.h>
using namespace std;
bool canPlace(vector<int>& pos, int n,int c,int mid){
    int count = 1;
    int lastPos = pos[0];
    for(int i = 1; i < n; i++){
        if(pos[i] - lastPos >= mid){
            count++;
            lastPos = pos[i];
        }
        if(count>=c){
            return true;
        }
    }
    return false;
}
int findMaxDistance(vector<int>& pos, int n, int c){
    int low = 0; int hight = pos[n-1] - pos[0];
    int best = 0;
    while(low<=hight){
        int mid = low + (hight-low)/2 ;
        if(canPlace(pos,n,c,mid)){
            best = mid;
            low = mid + 1;
        }else{
            hight=mid - 1;
        }
    }
    return best;
}
int main() {
    freopen("ex3.txt","r",stdin);
    int T;
    cin >> T;  
    while (T--) {
        int N, C;
        cin >> N >> C;  

        vector<int> positions(N);
        for (int i = 0; i < N; i++) {
            cin >> positions[i];  
        }
        sort(positions.begin(), positions.end());
        cout << findMaxDistance(positions, N, C) << endl;
    }

    return 0;
}