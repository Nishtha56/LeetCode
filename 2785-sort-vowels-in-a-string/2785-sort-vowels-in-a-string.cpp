class Solution {
public:
    bool isVowel(char c){
        if(c=='a'|| c=='e' || c=='i'|| c=='o' || c=='u' ||c=='A'|| c=='E' || c=='I'|| c=='O' || c=='U'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string t="";
        string v="";
        for(char c :s){
            if(isVowel(c)){
                v+=c;
            }
        }
        sort(v.begin(), v.end());
        int a=0;
        for(int i=0;i<s.length(); i++){
            if(isVowel(s[i])){
                s[i]=v[a];
                a++;
            }
        }
        return s;

    }
};