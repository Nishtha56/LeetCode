//Given an integer array nums of unique elements, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void AllSubset(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSets){
        if(i == nums.size()){
            allSets.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);     
        AllSubset(nums, ans, i + 1, allSets);

        ans.pop_back();  
        AllSubset(nums, ans, i + 1, allSets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSets;
        vector<int> ans;
        AllSubset(nums, ans, 0, allSets);
        return allSets;
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
    vector<vector<int>> result = obj.subsets(nums);

    cout << "\nSubsets:\n";
    for(auto &subset : result){
        cout << "{ ";
        for(int x : subset){
            cout << x << " ";
        }
        cout << "}\n";
    }

    return 0;
}
