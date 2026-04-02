class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        unordered_set<int> mp;
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        
        for(int num : mp){
          if(mp.find(num-1) == mp.end()){   //ELEMENT NOT EXIST
                int c=1; 
                int b=num+1;
                while(mp.find(b)!=mp.end()){          // FINDING IN THE MAP TC WILL BE ALWAYS 1
                c++;
                b=b+1;
                }
                 maxi=max(c, maxi);
            }
            
           
        }
        return maxi;
    }
};