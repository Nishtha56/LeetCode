class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {

        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int a=nums[i];
            nums.push_back(a);
        }
        return nums;
    }
};