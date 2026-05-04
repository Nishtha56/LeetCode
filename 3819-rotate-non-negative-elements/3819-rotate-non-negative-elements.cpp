class Solution {
public:
    void reverse(int a, int b, vector<int> &nums){
        while(a<b){
            swap(nums[a], nums[b]);
            a++;
            b--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(0, k-1, nums);
        reverse(k, n-1, nums);
        reverse(0, n-1, nums);

    }

    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr;

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                arr.push_back(nums[i]);
            }
        }
        if (arr.size()==0){
            return nums;
        } 
       

        rotate(arr, k);
        int j=0;

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i]=arr[j];
                j++;
            }
        
        }
        return nums;
    }
};