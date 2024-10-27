#include <bits/stdc++.h>
using namespace std;
#define MAX 31
int load[MAX], conflict[MAX][MAX];
int n,m;
int assigned[MAX];
int best_load = MAX;
int preferencesTeacher[MAX][MAX];
int check_course(int k, int teacher){
    return 0;
}
int check(int k, int teacher){
    if(preferencesTeacher[teacher][k] == 0){
        return 0;
    }
    for(int i = 1;i <= n;i++){
        if(assigned[i] == teacher && conflict[i][k] == 1){
            return 0;
        }
    }
    return 1;
}
void assign_course(int k){
    if(k > n){
        int max_load = *max_element(load+1, load + m + 1);
        best_load = min(max_load, best_load);
        return;
    }
    for(int teacher = 1; teacher <= m; teacher++){
        if(check(k,teacher)){
            assigned[k] = teacher;
            load[teacher]++;
            if(*max_element(load,load+m+1) < best_load){
                assign_course(k+1);
            }
            load[teacher]--;
            assigned[k] = 0;
        }
    }
}
int main(){
    freopen("ex3.txt","r",stdin);
    cin >> m >> n;
    int k;
    for(int i = 0; i < m; i++){
        cin >> k;
        int temp;
        for(int j = 0; j < k;j++){
            cin >> temp;
            preferencesTeacher[i+1][temp] = 1; 
        }
    }
    cin >> k;
    int v,l;
    for(int i = 0; i < k;i++){
        cin >> v >> l;
        conflict[v][l] =  conflict[l][v] = 1;
    }
    assign_course(1);

    if (best_load == MAX) {
        cout << -1 << endl;
    } else {
        cout << best_load << endl;
    }
    return 0;
}