class Solution {
public:
    //Jab koi number pehli baar mile → uske index ko negative kar do
    //Agar dubara mile → uska index already negative hoga
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            int ind=abs(nums[i])-1;    //index 0 based se hai range [1, n] hai

            if(nums[ind]<0){
                ans.push_back(ind+1);   //index to value → index + 1
            }
            else{
                nums[ind]=-nums[ind];
            }
        }
        return ans;
    }
};