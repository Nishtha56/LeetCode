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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* first=head;
        ListNode* second=head;

        //First element
        for(int i=0;i<k-1;i++){
            first=first->next;
        }
        int total=0;
        while(temp){
            temp=temp->next;
            total++;
        }
        //second element
        int last=total-k+1;
        for(int i=0;i<last-1;i++){
            second=second->next;
        }

        //swapping
        swap(first->val, second->val);
        return head;


    }
};