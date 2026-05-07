class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int s=flowerbed.size();
        if(n==0) return true;
      
        for(int i=0;i<s;i++){
            if(flowerbed[i]==0){

                if((i==0 || flowerbed[i-1]==0) && (i==s-1 || flowerbed[i+1]==0)){
                    n--;
                    flowerbed[i]=1;
                    if(n==0) return true;
                    
                }
                
            }
        }
        if(n!=0){
            return false;
        }
        return true;



    }
};