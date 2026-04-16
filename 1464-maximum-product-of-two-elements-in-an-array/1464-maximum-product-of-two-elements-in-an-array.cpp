class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq; //minHeap

        for(int i : nums){
            pq.push(i);
            if(pq.size()>2){
                pq.pop();
            }
        }
        int a=pq.top();
        pq.pop();

        int b=pq.top();
        pq.pop();

        return (b-1)*(a-1);

    }
};