//it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int i, vector<int> &nums, vector<int> &dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + fun(i + 2, nums, dp);
        int skip = fun(i + 1, nums, dp);
        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return fun(0, nums, dp);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution s;
    cout << s.rob(nums);
    return 0;
}
