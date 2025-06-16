#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            return binarySearchRecursive(arr, mid + 1, high, target);
        else
            return binarySearchRecursive(arr, low, mid - 1, target);
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result == -1)
        cout << "Element not present in the array." << endl;
    else
        cout << "Element found at index " << result << endl;

    return 0;
}
