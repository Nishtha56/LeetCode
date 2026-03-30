class Solution {
public:
    void subset(int ind, vector<int> &nums, vector<vector<int>>&ans, vector<int>&help){
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

        int i=ind+1;
        while(i<n && nums[i]==nums[i-1]){
            i++;
        }
        subset(i, nums, ans, help);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> help;
        sort(nums.begin(), nums.end());
        subset(0, nums, ans, help);
        return ans;
    }
};