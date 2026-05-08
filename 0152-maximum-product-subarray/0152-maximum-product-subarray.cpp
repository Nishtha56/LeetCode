class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //brute
        // int maxi=INT_MIN;
      
        // for(int i=0;i<nums.size();i++){
        //     int p=1;
        //     for(int j=i;j<nums.size();j++){
        //         p=p*nums[j];
        //         maxi=max(maxi, p);
                
        //     }
        // }
        // return maxi;
        //prefix sum

        int n=nums.size();
        int left=1;
        int right=1;
        int ans=nums[0];

        for(int i=0;i<n;i++){

            if(left==0){
                left=1;
            }
            if(right==0){
                right=1;
            }

            left=left*nums[i];
            right=right*nums[n-i-1];

            int maxi=max(left, right);
            ans=max(maxi, ans);
        }

        return ans;

    }
};