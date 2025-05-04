#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip> // for setw
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int res = 0;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            int key = a < b ? a * 10 + b : b * 10 + a;
            res += count[key];
            count[key]++;
        }

        return res;
    }
};

// Helper function to convert vector<vector<int>> to string
string formatDominoes(const vector<vector<int>>& dominoes) {
    string result = "[ ";
    for (auto& d : dominoes) {
        result += "[" + to_string(d[0]) + "," + to_string(d[1]) + "] ";
    }
    result += "]";
    return result;
}

int main() {
    Solution sol;

    vector<vector<vector<int>>> testCases = {
        {{1,2}, {2,1}, {3,4}, {5,6}},               // Expected: 1
        {{1,2}, {1,2}, {1,1}, {1,2}, {2,2}},         // Expected: 3
        {{1,1}, {1,1}, {1,1}},                       // Expected: 3
        {{1,2}, {3,4}, {5,6}, {7,8}},                // Expected: 0
        {{2,1}, {2,1}, {1,2}, {2,1}},                // Expected: 6
    };

    // Print table header
    cout << left
         << setw(10) << "Test #" 
         << setw(40) << "Dominoes"
         << setw(20) << "Equivalent Pairs" 
         << endl;

    cout << string(70, '-') << endl;

    // Process test cases
    for (int i = 0; i < testCases.size(); ++i) {
        string dominoStr = formatDominoes(testCases[i]);
        int result = sol.numEquivDominoPairs(testCases[i]);

        cout << left 
             << setw(10) << (i + 1)
             << setw(40) << dominoStr
             << setw(20) << result 
             << endl;
    }

    return 0;
}
