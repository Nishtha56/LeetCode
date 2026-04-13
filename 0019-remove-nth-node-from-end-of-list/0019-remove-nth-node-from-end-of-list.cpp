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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        
         ListNode* temp1=head;
        if(c>=n){
            int d=c-n;
           
           if(n==c){
            return head->next;
           }
            else if(d==0){
                return NULL;
            }
           else{

           

            
            for(int i=1;i<c;i++){
                if(i==d){
                    temp1->next=temp1->next->next;
                }
                else{
                    temp1=temp1->next;
                }
            }
           }
            
        }
       return head;
            
    }
};