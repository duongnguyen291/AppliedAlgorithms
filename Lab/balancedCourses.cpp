#include <bits/stdc++.h>
using namespace std;
#define MAXX 32
int m,n,k;
int bestLoad = INT_MAX;
vector<int> courseTeacher[MAXX];
int teacherList[MAXX][MAXX], conflictCourse[MAXX][MAXX];
int teacherLoad[MAXX],visitedCourse[MAXX];
void solution(){
    int maxCurrent = 0;
    for(int i = 1; i <= m; i++){
        if(maxCurrent < teacherLoad[i]) maxCurrent = teacherLoad[i];
    }
    if(maxCurrent < bestLoad) bestLoad = maxCurrent;
}
bool check(int teacher, int k){
    if(visitedCourse[k] != 0){return false;}
    if(teacherList[teacher][k] != 1){ return false;}
    for(auto course: courseTeacher[teacher]){
        if(conflictCourse[course][k] == 1){
            return false;
        }
    }
    return true;
}
void sol(int k){
    for(int teacher = 1; teacher <= m; teacher++){
        if(check(teacher,k)){
            visitedCourse[k] = teacher;
            teacherLoad[teacher]++;
            courseTeacher[teacher].push_back(k);
            if(k == n) solution();
            else{
                if(teacherLoad[teacher] < bestLoad){
                    sol(k+1);
                }
            }
            visitedCourse[k] = 0;
            teacherLoad[teacher]--;
            courseTeacher[teacher].pop_back();



        }
    }
}
int main(){
    freopen("ex1.txt","r",stdin);
    cin >> m >> n;
    for(int i = 1; i <= m ;i++){
        cin >> k;
        int temp;
        for(int j = 1; j <= k; j++){
            cin >> temp;
            teacherList[i][temp] = 1;
        }
    }
    int temp; 
    cin >> temp;
    int a,b;
    for(int i = 0; i < temp; i++){
        cin >> a >> b;
        conflictCourse[a][b] = 1;
        conflictCourse[b][a] = 1;
    }

    sol(1);
    if(bestLoad == INT_MAX){
        cout << "-1" << endl;
    }
    else{
        cout << bestLoad << endl;
    }
    return 0;
}