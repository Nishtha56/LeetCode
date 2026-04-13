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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        while(slow){
            ListNode* next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }

        int maxi=0;
        ListNode* t1=head;
        ListNode* t2=prev;

        while(t2){
            int a=t1->val+t2->val;
            maxi=max(maxi, a);
            t1=t1->next;
            t2=t2->next;
        }
        return maxi;
    }
};