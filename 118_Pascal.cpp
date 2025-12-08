//Pascal Triangle

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    int numRows;
    cin >> numRows;
    Solution obj;
    vector<vector<int>> ans = obj.generate(numRows);
    for (auto &row : ans) {
        for (auto &x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
