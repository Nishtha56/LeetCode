class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> mp1;

        int n=s.length();
        for(int i=0;i<n;i++){
            char ch1=s[i];
            char ch2=t[i];

            //mp.end() → ch1 already exists in map
            // 1. ch1 is already mapped to a different character
            // 2. ch2 is already mapped from a different character

            if((mp.find(ch1) != mp.end() && mp[ch1] != ch2) || (mp1.find(ch2) != mp1.end() && mp1[ch2] != ch1)){
                return false;
            }
            mp[ch1]=ch2;
            mp1[ch2]=ch1;
        }
        return true;
        

        
    }
};