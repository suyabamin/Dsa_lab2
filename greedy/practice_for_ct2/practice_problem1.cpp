#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin>>b;

    cout << min((a + b) / 3, min(a, b)) << endl;

    return 0;
}


/*
3
2
ans-2
*/