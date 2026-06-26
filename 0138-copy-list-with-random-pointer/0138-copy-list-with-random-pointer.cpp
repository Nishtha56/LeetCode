/*
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val=_val;
        next=NULL;
        random=NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;

        Node* curr=head;

        //make duplicate
        while(curr){
            Node* newNode=new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=curr->next->next;
        }

        //copy random ptr
        curr=head;
        while(curr){
            if(curr->random==NULL){
                curr->next->random=NULL;
            }
            else{
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }

        //extract both the lists
        curr=head;
        Node* newHead=curr->next;
        Node* newCurr=newHead;

        while(curr){
            curr->next=curr->next->next;

            if(newCurr->next)
                newCurr->next=newCurr->next->next;

            curr=curr->next;
            newCurr=newCurr->next;
        }

        return newHead;
    }
};