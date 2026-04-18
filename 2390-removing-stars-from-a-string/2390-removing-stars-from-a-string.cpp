class Solution {
public:
    string removeStars(string s) {
        string ans="";
        int c=0;
        int a=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        // if(c==a){
        //     return ans;
        // }
        return ans;
        
    }
};