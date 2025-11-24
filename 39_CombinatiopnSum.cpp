//Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
//You may return the combinations in any order.
//The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void makeCombination(vector<int>& arr, int remSum, vector<int>& curr, vector<vector<int>>& res, int index){
        if(remSum == 0){
            res.push_back(curr);
            return;
        }

        if(remSum < 0 || index >= arr.size()){
            return;
        }

        curr.push_back(arr[index]);  
        makeCombination(arr, remSum - arr[index], curr, res, index);

        curr.pop_back();  
        makeCombination(arr, remSum, curr, res, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        makeCombination(candidates, target, curr, res, 0);
        return res;
    }
};

int main(){
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> candidates[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    Solution obj;
    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "\nCombinations that sum to " << target << ":\n";
    for(auto &comb : result){
        cout << "{ ";
        for(int x : comb){
            cout << x << " ";
        }
        cout << "}\n";
    }

    return 0;
}
