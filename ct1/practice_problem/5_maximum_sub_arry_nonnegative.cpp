#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = 0, rightSum = 0;
    int sum = 0;
    bool valid = true;

    // sum non-negative numbers on left side
    for (int i = mid; i >= low; i--) {
        if (arr[i] < 0) {           // break when negative found
            valid = false;
            break;
        }
        sum += arr[i];
        leftSum = sum;
    }

    sum = 0;
    bool validRight = true;

    // sum non-negative numbers on right side
    for (int i = mid + 1; i <= high; i++) {
        if (arr[i] < 0) {
            validRight = false;
            break;
        }
        sum += arr[i];
        rightSum = sum;
    }

    if (valid && validRight)
        return leftSum + rightSum;   // fully valid combined subarray
    else if (valid)
        return leftSum;              // only left side valid
    else if (validRight)
        return rightSum;             // only right side valid
    else
        return 0;                    // no valid crossing subarray
}

int maxNonNegativeSubarray(int arr[], int low, int high) {
    if (low == high) {
        if (arr[low] >= 0) return arr[low];
        else return 0;
    }

    int mid = (low + high) / 2;

    int left = maxNonNegativeSubarray(arr, low, mid);
    int right = maxNonNegativeSubarray(arr, mid + 1, high);
    int cross = maxCrossingSum(arr, low, mid, high);

    return max(left, max(right, cross));
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = maxNonNegativeSubarray(arr, 0, n - 1);
    cout << "Maximum non-negative subarray sum = " << ans;

    return 0;
}
