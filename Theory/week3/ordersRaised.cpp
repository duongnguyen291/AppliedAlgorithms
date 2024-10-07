#include <bits/stdc++.h>
using namespace std;
int time_to_seconds(const string& time) {
    int hh, mm, ss;
    sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    return hh * 3600 + mm * 60 + ss;
}

int main() {
    freopen("order.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    
    vector<int> numberOrder(86400, 0); 
    string line;
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        string orderId, timePoint;
        istringstream iss(line);
        iss >> orderId >> timePoint;
        int timeInSeconds = time_to_seconds(timePoint);
        numberOrder[timeInSeconds]++; 
    }
    
    for (int i = 1; i < 86400; i++) {
        numberOrder[i] += numberOrder[i - 1];  
    }

    while (getline(cin, line)) {
        if (line == "###") break;
        
        if (line == "?number_orders") {
          
            cout << numberOrder[86399] << endl;
        }
        else if (line.substr(0, 24) == "?number_orders_in_period") {
            string fromTimePoint, toTimePoint;
            istringstream iss(line);
            string command;
            iss >> command >> fromTimePoint >> toTimePoint;
            
            int fromTime = time_to_seconds(fromTimePoint);
            int endTime = time_to_seconds(toTimePoint);
            
            int totalOrdersInPeriod = numberOrder[endTime];
            if (fromTime > 0) {
                totalOrdersInPeriod -= numberOrder[fromTime - 1];
            }
            cout << totalOrdersInPeriod << endl;
        }
        else if (line.substr(0, 22) == "?number_orders_at_time") {
            string timeAtPoint = line.substr(23); 
            int timeAt = time_to_seconds(timeAtPoint);
            
            int ordersAtTime = numberOrder[timeAt] - (timeAt > 0 ? numberOrder[timeAt - 1] : 0);
            cout << ordersAtTime << endl;
        }
    }

    return 0;
}
