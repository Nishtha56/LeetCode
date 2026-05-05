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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int c=1;
        if(head==NULL){
            return head;
        }
        while(temp->next!=NULL){
            c++;
            temp=temp->next;
        } 
        temp->next=head;
        k=k%c;
        int n=c-k;
        
        ListNode* t=temp;
        while(n>0){
            t=t->next;
            n--;
        }
        ListNode* newHead=t->next;
        t->next=NULL;

        return newHead;
    }
};