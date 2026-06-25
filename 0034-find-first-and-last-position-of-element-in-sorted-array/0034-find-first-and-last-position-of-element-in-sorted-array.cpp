class Solution {
public:
    int lower(vector<int> &nums, int target){
        int l=0, r=nums.size()-1;
        int idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                idx=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return idx;

    }
    int upper(vector<int> &nums, int target){
        int l=0;
        int r=nums.size()-1;
        int idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                idx=mid;
                l=mid+1;
            }
            else if(nums[mid]>target){
                r=mid-1;
                
            }
            else{
                l=mid+1;
            }
        }
        return idx;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int a=lower(nums, target);
        int b=upper(nums, target);

        ans={a,b};
        return ans;
    }
};