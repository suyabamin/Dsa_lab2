#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> trains = {
        {8,12}, {6,9}, {11,14}, {2,7}, {1,7}, {12,20}, {7,12}, {13,19}
    };

    // Sort by departure time
    sort(trains.begin(), trains.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });

    int count = 0;
    int last_departure = -1; // initial

    vector<pair<int,int>> schedule;

    for(auto t : trains) {
        if(t.first >= last_departure + 1) { // 1-unit gap
            count++;
            last_departure = t.second;
            schedule.push_back(t);
        }
    }

    cout << "Maximum trains = " << count << "\n";
    cout << "Trains scheduled: ";
    for(auto t : schedule) {
        cout << "[" << t.first << "," << t.second << ") ";
    }
    cout << endl;

    return 0;
}
