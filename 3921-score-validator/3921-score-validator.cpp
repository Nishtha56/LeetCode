class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int c=0;
        int res=0;
        for(int i=0;i<events.size();i++){
            string ch=events[i];
            if(c>=10){
                return {res, 10};
            }
            else if(events[i] == "W"){
                c++;
            }
            
            else if(isdigit(ch[0])){
                res=res+stoi(ch);
            }
            else{
                res++;
            }
        }
       
        return {res, c};

    }
};