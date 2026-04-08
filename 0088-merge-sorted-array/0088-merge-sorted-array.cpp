class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int idx=m+n-1;
        //compare from the last because in starting some values may over wrote O(n+m)
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[idx]=nums1[i];
                i--;
            }
            else{
                nums1[idx]=nums2[j];
                j--;
            }
            idx--;
        }
        //element num1 remain
        while(i>=0){
            nums1[idx]=nums1[i];
            idx--;
            i--;
        }
        //nums2 remain
        while(j>=0){
            nums1[idx]=nums2[j];
            idx--;
            j--;
        }

    }
};