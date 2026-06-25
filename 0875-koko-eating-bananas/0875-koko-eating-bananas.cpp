class Solution {
public:
long long func(vector<int> &piles, int h){
    long long total=0;
    for(long long i=0;i<piles.size();i++){
        total+=ceil((double)piles[i]/(double)h);
    }
    return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        sort(piles.begin(), piles.end());
        int r=piles[piles.size()-1];
        long long ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long t=func(piles, mid);
            if(t<=h){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};