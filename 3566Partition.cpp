//3566 . Partition Array into Two Equal Product Subsets
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int in, long long p1, long long p2, long long target, vector<int>& nums){
        if(p1 > target || p2 > target){
            return false;
        }
        if(in == nums.size()){
            return p1 == target && p2 == target;
        }
        bool a = solve(in + 1, p1 * nums[in], p2, target, nums);
        bool b = solve(in + 1, p1, p2 * nums[in], target, nums);
        return a | b;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(0, 1, 1, target, nums);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    long long target;
    cin >> target;

    Solution obj;

    if(obj.checkEqualPartitions(nums, target))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
