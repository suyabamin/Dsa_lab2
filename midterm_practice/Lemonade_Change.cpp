#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> bills;
    int n, x;
    cin >> n;  // number of customers
    for(int i=0; i<n; i++){
        cin >> x;
        bills.push_back(x);
    }

    int five = 0, ten = 0;

    for(int bill : bills){
        if(bill == 5){
            five++;
        }
        else if(bill == 10){
            if(five == 0){
                cout << "false";
                return 0;
            }
            five--;
            ten++;
        }
        else if(bill == 20){
            if(ten > 0 && five > 0){
                ten--;
                five--;
            }
            else if(five >= 3){
                five -= 3;
            }
            else{
                cout << "false";
                return 0;
            }
        }
    }

    cout << "true";
    return 0;
}
