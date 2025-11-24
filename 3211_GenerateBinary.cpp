//3211. Generate Binary Strings Without Adjacent Zeros
//A binary string x is valid if all substrings of x of length 2 contain at least one "1". Return all valid strings with length n, in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(int idx, string& s, vector<string>& res, int pre){
        if(idx == s.size()){
            res.push_back(s);
            return;
        }
        
        if(pre != 0){
            s[idx] = '0';
            generate(idx + 1, s, res, 0);
        }
        
        s[idx] = '1';
        generate(idx + 1, s, res, 1);
    }

    vector<string> validStrings(int n) {
        string s(n, '\0');
        vector<string> res;
        generate(0, s, res, 1);
        return res;
    }
};

int main(){
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    
    Solution obj;
    vector<string> ans = obj.validStrings(n);

    cout << "\nValid Binary Strings:\n";
    for(string &str : ans){
        cout << str << endl;
    }

    return 0;
}
