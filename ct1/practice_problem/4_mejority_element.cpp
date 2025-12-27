#include <iostream>
using namespace std;

int countInRange(int arr[], int low, int high, int target) {
    int count = 0;
    for (int i = low; i <= high; i++) {
        if (arr[i] == target) count++;
    }
    return count;
}

int majorityDivide(int arr[], int low, int high) {

    // Base case: only one element
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    // Recursively find majority in left and right halves
    int leftMajor = majorityDivide(arr, low, mid);
    int rightMajor = majorityDivide(arr, mid + 1, high);

    // If both halves agree, return that element
    if (leftMajor == rightMajor)
        return leftMajor;

    // Otherwise, count which one appears more in the whole range
    int leftCount = countInRange(arr, low, high, leftMajor);
    int rightCount = countInRange(arr, low, high, rightMajor);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maj = majorityDivide(arr, 0, n - 1);
    cout << "Majority element = " << maj << endl;

    return 0;
}
