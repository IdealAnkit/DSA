#include <iostream>
#include <vector>
#include <unordered_map>
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

void printDominoes(vector<vector<int>>& dominoes) {
    cout << "[ ";
    for (auto& d : dominoes) {
        cout << "[" << d[0] << "," << d[1] << "] ";
    }
    cout << "]";
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

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i+1 << ": ";
        printDominoes(testCases[i]);
        int result = sol.numEquivDominoPairs(testCases[i]);
        cout << " -> Equivalent Pairs: " << result << "\n";
    }

    return 0;
}
