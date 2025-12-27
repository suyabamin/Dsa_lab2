#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> A) {
    sort(A.begin(), A.end());
    int moves = 0;
    int i = 0, n = A.size();

    while(i < n) {
        // Check if next element can pair with current
        if(i + 1 < n && A[i+1] - A[i] <= 2) { 
            // Remove 2 elements
            i += 2;
        } else {
            // Remove 1 element
            i += 1;
        }
        moves++;
    }

    return moves;
}

int main() {
    vector<int> A = {1, 3, 5, 9};
    cout << "Minimum moves: " << minMoves(A) << endl;
    return 0;
}
