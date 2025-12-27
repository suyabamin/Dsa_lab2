#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> trains = {
        {1000,1030},{840,1030},{850,1040},{1700,2000},
        {800,835},{1300,1800},{1500,1650},{1200,1380}
    };

    // Sort by departure time
    sort(trains.begin(), trains.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });

    int last_departure = -1;
    int safety_gap = 10;
    vector<pair<int,int>> schedule;

    for(auto t : trains){
        if(t.first >= last_departure + safety_gap){
            schedule.push_back(t);
            last_departure = t.second;
        }
    }

    cout << "Maximum trains = " << schedule.size() << endl;
    cout << "Selected trains: ";
    for(auto t : schedule){
        cout << "[" << t.first << "," << t.second << ") ";
    }
    cout << endl;

    return 0;
}
