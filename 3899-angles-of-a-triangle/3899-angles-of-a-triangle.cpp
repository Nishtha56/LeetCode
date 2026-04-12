class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> res;
        double a=sides[0];
        double b=sides[1];
        double c=sides[2];
        double PI=3.14159265359;
        
        if(a+b>c && b+c>a && c+a>b){  //Triangle check 
            //a=b2+c2-a2/2bc
            double x=acos((b*b + c*c - a*a) / (2*b*c));
            double y=acos((a*a + c*c - b*b) / (2*a*c));
            double z=acos((a*a + b*b - c*c) / (2*a*b));

            x=x*(180/PI);
            y=y*(180/PI);
            z=z*(180/PI);

            res.push_back(x);
            res.push_back(y);
            res.push_back(z);

        }
        sort(res.begin(), res.end());
        return res;
    }
};