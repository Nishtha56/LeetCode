//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sub(vector<int> &curr, vector<int>& nums, vector<vector<int>> &res) {
        if(nums.size() == 0){
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            curr.push_back(x);
            nums.erase(nums.begin() + i);
            sub(curr, nums, res);
            curr.pop_back();
            nums.insert(nums.begin() + i, x);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sub(curr, nums, res);
        return res;
    }
};

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> result = obj.permute(nums);

    cout << "\nPermutations:\n";
    for(auto &v : result){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
