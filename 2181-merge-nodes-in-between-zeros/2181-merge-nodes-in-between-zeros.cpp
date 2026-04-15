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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=head->next;
        ListNode* curr=dummy;
        int sum=0;
        if(head->val!=0){
            sum+=head->val;
        }
        while(temp){

            if(temp->val==0){
                curr->next=new ListNode(sum);
                curr=curr->next;
                sum=0;
            }

            sum+=temp->val;
            temp=temp->next;
        }
        return dummy->next;
    }
};