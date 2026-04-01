class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            s=s+s[i];
            string temp=s.substr(i+1, s.length());

            if(temp==goal){
                return true;
            }
        }
        return false;
    }
};