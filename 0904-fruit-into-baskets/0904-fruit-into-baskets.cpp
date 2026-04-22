class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxi=0;
        int i=0;
        int j=0;
        unordered_map<int, int> mp;
        int n=fruits.size();

        while(j<n){
            mp[fruits[j]]++;

            //increase
            if(mp.size() <= 2){
                maxi=max(maxi, j-i+1);
          
            }
            //shrink
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
            
        } 
        return maxi;


        return 0;
}

};