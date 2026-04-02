class Solution {
public:
    void helper(vector<vector<int> >& ans, vector<int> &nums, vector<int>& flag, vector<int> ex){
        if(ex.size()==nums.size()){
            ans.push_back({ex});
            return;
        }
        for(int i=0; i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1] && flag[i-1]==1) continue; // skip those who having same element and of i-1 having picked(1) it also not taken  
            //previous duplicate NOT allowed

           if(flag[i]==0){
            flag[i]=1;
            
            ex.push_back(nums[i]);
            helper(ans, nums, flag, ex);

            flag[i]=0;
            ex.pop_back();
           }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> ex;
        vector<int> flag(nums.size(), 0);
        helper(ans, nums, flag, ex);
        return ans;
    }
};