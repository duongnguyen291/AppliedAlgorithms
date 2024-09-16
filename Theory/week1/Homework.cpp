#include <bits/stdc++.h>
using namespace std;

int main(){
     freopen("Homework.txt","r",stdin);
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    int list1[a+1],list2[b+1];
    int cnt = 0;
    map <int,int> mapList1,mapList2;
    for(int i = 1;i < a; i++){
        cin >> list1[i];
        mapList1[list1[i]]++;
    }
    for(int i = 1;i < a; i++){
        cin >> list2[i];
        mapList2[list2[i]]++;
    }
    for(const auto &pair: mapList1 ){
        if(mapList2[pair.first] == 0) cnt++;
    }
    for(const auto &pair: mapList2){
        if(mapList1[pair.first] == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}