#include <iostream>
#include <climits>
using namespace std;

void largestPair(int arr[], int low, int high, int &largest, int &secondLargest) {

    // Base case: single element
    if (low == high) {
        largest = arr[low];
        secondLargest = INT_MIN;
        return;
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            largest = arr[low];
            secondLargest = arr[high];
        } else {
            largest = arr[high];
            secondLargest = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;

    int Lmax, Lsecond;
    int Rmax, Rsecond;

    // Recursively process left half
    largestPair(arr, low, mid, Lmax, Lsecond);

    // Recursively process right half
    largestPair(arr, mid + 1, high, Rmax, Rsecond);

    // Combine results
    if (Lmax > Rmax) {
        largest = Lmax;
        secondLargest = max(Lsecond, Rmax);
    } else {
        largest = Rmax;
        secondLargest = max(Rsecond, Lmax);
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = INT_MIN, secondLargest = INT_MIN;

    largestPair(arr, 0, n - 1, largest, secondLargest);

    cout << "Largest number = " << largest << endl;
    cout << "Second largest number = " << secondLargest << endl;

    return 0;
}
