/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        if(lists.empty()) return NULL;
        ListNode* head=new ListNode();
        int f=0;
        for(int i=0;i<lists.size();i++){
            ListNode* node=lists[i];

            while(node!=NULL){
                pq.push(node->val);
                node=node->next;
                f=1;
            }
        }
        if(f==0){
            return NULL;
        }
        head->val=pq.top();
        ListNode*temp=head;
        pq.pop();
        while(!pq.empty()){
            
            ListNode* curr=new ListNode(pq.top());
            pq.pop();
            temp->next=curr;
            
            temp=temp->next;
        }
        return head;
        

    }
};