class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mp1;
        int c=0;

        for(string c: words1){
            mp[c]++;
        }

        for(string c: words2){
            mp1[c]++;
        }

        for(auto i : mp){
            if(mp[i.first] == 1 && mp1[i.first]==1){
                c++;
            }
        }
        return c;

    }
};