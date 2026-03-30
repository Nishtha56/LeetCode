class Solution {
public:
    void helper(vector<string>& ans, string &s, string s1, int ind){
        if(ind>=s.length()){
            ans.push_back(s1);
            return;
        }
        if(isalpha(s[ind])){
            //lower
            s1+=tolower(s[ind]);
            helper(ans, s, s1, ind+1);
            s1.pop_back();

            //uppercase
            s1+=toupper(s[ind]);
            helper(ans, s, s1, ind+1);
            s1.pop_back();
        }
        else{
            //digits no choice
            s1+=s[ind];
            helper(ans, s, s1, ind+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string s1="";
        helper(ans, s, s1, 0);
        return ans;
    }
};