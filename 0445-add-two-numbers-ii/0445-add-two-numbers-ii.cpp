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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st;
        stack<int> st1;

        ListNode* temp=l1;
        ListNode* temp1=l2;

        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }

        while(temp1){
            st1.push(temp1->val);
            temp1=temp1->next;
        }
        int carry=0;
       
        ListNode* head=NULL;
        while(!st.empty() || !st1.empty() || carry!=0){
            int sum=carry;
            if(!st.empty()){
                sum+=st.top();
                st.pop();
            }
            if(!st1.empty()){
                sum+=st1.top();
                st1.pop();
            }

            
            int num=sum%10;
            ListNode* newNode=new ListNode(num);
            newNode->next=head;
            head=newNode;
            carry=sum/10;

        }
        
        return head;

        


    }
};