class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int l=0, r=0;
        int c=0;
       for(r=0; r<n;r++){
        if(nums[r]==0){
            c++;
        }
            

            while(c>k){
                if(nums[l]==0){
                    c--;
                }
                l++;
            }
            maxi=max(maxi, r-l+1);
       }
       return maxi;

    }
};