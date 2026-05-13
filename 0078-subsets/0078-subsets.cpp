class Solution {
public:
    void helper(vector<int>& nums, int i, vector<vector<int>> &ans, vector<int> &res){
        if(i==nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        helper(nums, i+1, ans, res);

        res.pop_back();
        helper(nums, i+1, ans, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        helper(nums, 0, ans, res);
        return ans;
    }
};