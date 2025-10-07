//24. Swap Nodes in Pairs

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while (first != NULL && sec != NULL) {
            ListNode* third = sec->next;

            sec->next = first;
            first->next = third;

            if (prev != NULL) {
                prev->next = sec;
            } else {
                head = sec;
            }

            prev = first;
            first = third;
            if (third != NULL) {
                sec = third->next;
            } else {
                sec = NULL;
            }
        }
        return head;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.swapPairs(head);

    cout << "Swapped List: ";
    printList(head);

    return 0;
}
