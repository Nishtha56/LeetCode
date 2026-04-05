class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(begin(s), end(s));

            mp[s].push_back(strs[i]);
        }
        // sorted string -> words of that matching string
        // aet => eat, tea, ate
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;  // O(nlogn)*m


        //optimal

        
    }
};