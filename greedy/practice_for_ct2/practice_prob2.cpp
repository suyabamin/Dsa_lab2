#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int S, N, M;
    cin >> S >> N >> M;

    int totalFood = S * M;
    int sundays = S / 7;
    int buyingDays = S - sundays;

    if (buyingDays * N < totalFood) {
        cout << -1;  // Not possible to survive
    } else {
        cout << ceil((double)totalFood / N);
    }

    return 0;
}

/*Input: S = 10, N = 16, M = 2
Output: 2 */