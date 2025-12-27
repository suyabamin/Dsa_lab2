//thef 
#include <bits/stdc++.h>
using namespace std;

// Structure to store item info
struct Item {
    string name;
    double weight;    // remaining weight in shop
    double price;     // total price of item
    double valuePerKg; // price per kg
};

int main() {
    // Initialize items
    vector<Item> shop = {
        {"Rice", 12, 840, 840.0/12},
        {"Salt", 10, 870, 870.0/10},
        {"Saffron", 8, 2000, 2000.0/8},
        {"Sugar", 5, 500, 500.0/5}
    };

    double thiefCapacity = 9.0; // each thief's knapsack
    int thiefCount = 0;

    while (true) {
        // Check if shop is empty
        bool empty = true;
        for (auto &it : shop) {
            if (it.weight > 0) {
                empty = false;
                break;
            }
        }
        if (empty) break;

        thiefCount++;
        double remaining = thiefCapacity;
        double profit = 0;

        vector<pair<string,double>> itemsTaken; // name + weight

        // Sort items by value per kg descending
        sort(shop.begin(), shop.end(), [](Item a, Item b){
            return a.valuePerKg > b.valuePerKg;
        });

        for (auto &it : shop) {
            if (remaining == 0) break;
            if (it.weight == 0) continue;

            double take = min(it.weight, remaining);
            profit += take * it.valuePerKg;
            it.weight -= take;
            remaining -= take;

            itemsTaken.push_back({it.name, take});
        }

        // Print this thief's details
        cout << "Thief " << thiefCount << ":\n";
        cout << "Items taken: ";
        for (auto &p : itemsTaken) {
            cout << p.second << " kg " << p.first << ", ";
        }
        cout << "\nProfit: " << profit << " taka\n\n";
    }

    cout << "Total thieves needed: " << thiefCount << endl;

    return 0;
}

/*
Thief 1:
Items taken: 8 kg Saffron, 1 kg Sugar, 
Profit: 2100 taka

Thief 2:
Items taken: 4 kg Sugar, 5 kg Salt, 
Profit: 935 taka

Thief 3:
Items taken: 5 kg Salt, 4 kg Rice, 
Profit: 715 taka

Thief 4:
Items taken: 8 kg Rice, 
Profit: 560 taka

Total thieves needed: 4

*/