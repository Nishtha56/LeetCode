// 121. Best Time to Buy and Sell Stock : In this firstly take a loop then compare if best buy is less the i price then take maxProfit and then simply tak best buy by using min function.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > bestBuy){
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    int profit = sol.maxProfit(prices);
    cout << "Maximum Profit: " << profit << endl;
    return 0;
}
