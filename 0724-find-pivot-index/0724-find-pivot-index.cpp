class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int pre=0, post=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                pre=pre+nums[j];
            }
            for(int j=i+1;j<n;j++){
                post=post+nums[j];
            }

            if(pre==post){
                return i;
            }
            pre=0;
            post=0;
        }
        return -1;
    }
};