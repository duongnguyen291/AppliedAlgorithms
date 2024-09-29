#include <bits/stdc++.h>
using namespace std;
struct Call{
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};
bool is_valid_phone_number(const string &phone) {
    if (phone.length() != 10) return false;
    for (char c : phone) {
        if (!isdigit(c)) return false;
    }
    return true;
}
int time_to_seconds(const string &time) {
    int hh, mm, ss;
    sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    return hh * 3600 + mm * 60 + ss;
}

int main(){
    freopen("telco.txt","r",stdin);
    vector<Call> calls;
    map<string,int> number_calls_from; 
    map<string,int> count_time_calls_from;
    string line;
    bool valid_numbers = true;
    while(getline(cin,line)){
        if(line == "#") break;
        Call call;
        istringstream iss(line);
        string command;
        iss >> command >> call.from_number >> call.to_number >> call.date >> call.from_time >> call.end_time;
        if (!is_valid_phone_number(call.from_number) || !is_valid_phone_number(call.to_number)) {
                    valid_numbers = false;
                }
        number_calls_from[call.from_number]++;
        count_time_calls_from[call.from_number] += (time_to_seconds(call.end_time) -  time_to_seconds(call.from_time));
        calls.push_back(call);
    }
    while (getline(cin, line)) {
        if (line == "#") break;

        if (line == "?check_phone_number") {
            cout << (valid_numbers ? 1 : 0) << endl;
        }
        else if (line.substr(0, 18) == "?number_calls_from") {
            string phone_number = line.substr(19);
            cout << number_calls_from[phone_number] << endl;
        }
        else if (line == "?number_total_calls") {
            cout << calls.size() << endl;
        }
        else if (line.substr(0, 22) == "?count_time_calls_from") {
            string phone_number = line.substr(23);
            // int total_time = 0;
            // for (const auto &call : calls) {
            //     if (call.from_number == phone_number) {
            //         int start_time = time_to_seconds(call.from_time);
            //         int end_time = time_to_seconds(call.end_time);
            //         total_time += (end_time - start_time);
            //     }
            // }
            cout << count_time_calls_from[phone_number] << endl;
        }
    }
    return 0;
}