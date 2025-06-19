#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Function to sort an array using bucket sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // 1. Create n empty buckets
    vector<vector<float>> buckets(n);

    // 2. Put array elements into buckets
    for (int i = 0; i < n; ++i) {
        int index = n * arr[i]; // index in [0, n-1]
        buckets[index].push_back(arr[i]);
    }

    // 3. Sort individual buckets
    for (int i = 0; i < n; ++i)
        sort(buckets[i].begin(), buckets[i].end());

    // 4. Concatenate all buckets into arr
    int idx = 0;
    for (int i = 0; i < n; ++i)
        for (float val : buckets[i])
            arr[idx++] = val;
}

// main function
int main() {
    vector<float> arr = {0.897f, 0.565f, 0.656f, 0.123f, 0.665f, 0.343f};

    cout << "Original array:\n";
    for (float x : arr) cout << x << " ";
    cout << "\n";

    bucketSort(arr);

    cout << "Sorted array:\n";
    for (float x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
