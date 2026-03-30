class Solution {
public:
    void subset(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int>&help){
        int n=nums.size();
        if(ind>=n){
            ans.push_back({help});
            return;
        }

        //take
        help.push_back(nums[ind]);
        subset(ind+1, nums, ans, help);

        //not take
        help.pop_back();
        subset(ind+1, nums, ans, help);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> help;
        subset(0, nums, ans, help);
        return ans;
    }
};