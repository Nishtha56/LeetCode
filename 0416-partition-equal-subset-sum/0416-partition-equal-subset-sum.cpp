class Solution {
public:
    int dp[201][20001];
    bool helper(vector<int> &nums, int target, int i){
        if(target==0){
            return true;
        }
        if(nums.size()==i || target<0){
        return false;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        
        bool take=helper(nums, target-nums[i], i+1);

     
        bool notTake=helper(nums, target, i+1);
        return dp[i][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }


        int target=sum/2;
        memset(dp, -1, sizeof(dp));
        return helper(nums, target, 0);
    }
};