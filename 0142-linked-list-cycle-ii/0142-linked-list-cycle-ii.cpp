/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //TC=O(n)
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;    //It only detect the cycle not where is the starting point

            if(slow==fast){
                slow=head; //Now move 1 step fast and slow
                //It runs only once — after cycle is detected. 

                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
    
                
            }
        }
        return NULL;
    }
};