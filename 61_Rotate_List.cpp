// 61 Rotating a list : firstly make a corcular list then use (total count -k(steps)) then break the circular list by making a newHead

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* temp = head;
        int c = 1;
        while(temp->next != NULL){
            temp = temp->next;
            c++;
        }
        temp->next = head;
        k = k % c;
        int n = c - k;
        ListNode* t = head;
        for(int i = 1; i < n; i++) t = t->next;
        ListNode* newHead = t->next;
        t->next = NULL;
        return newHead;
    }
};

ListNode* createList(int arr[], int n){
    if(n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1; i < n; i++){
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode* head = createList(arr, n);
    Solution sol;
    int k = 2;
    head = sol.rotateRight(head, k);
    printList(head);
    return 0;
}
