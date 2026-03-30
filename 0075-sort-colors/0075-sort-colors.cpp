class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        int mid=0;
        int h=nums.size()-1;
        // 0 to low-1 : 0
        // low to mid : 1
        //mid+1 to high : unsorted part store
        //high+1 to n-1 : 2
        //tc o(n)
        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[l], nums[mid]);
                l++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{               //nums[mid]=2
                swap(nums[mid], nums[h]);
                h--;
            }
        }
    }
};