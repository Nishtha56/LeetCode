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
        if(lists.empty()){
            return NULL;

        }
        ListNode* head=new ListNode();
        int f=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* curr=lists[i];
            while(curr!=NULL){
                pq.push(curr->val);
                curr=curr->next;
                f=1;
            }

        }

        if(f==0) return NULL;

        head->val=pq.top();
        pq.pop();
        ListNode* temp=head;

        while(!pq.empty()){
            ListNode* curr=new ListNode(pq.top());
            pq.pop();
            temp->next=curr;
            temp=temp->next;


        }
        return head;
    }
};