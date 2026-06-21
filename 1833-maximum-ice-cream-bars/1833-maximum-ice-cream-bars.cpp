class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        long long int sum=0,c=0;
        int n=costs.size();
        for(int i=0;i<n;i++){
            sum+=costs[i];
            if(sum<=coins){
                c++;
            }
        }
        return c;
    }
};