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
        int size = 0;
        ListNode* travel = head;
        while(travel) {
            ++size;
            travel = travel->next;
        }
        cout << size ;
        if(size - n == 0) {
            return head->next;
        }
        travel = head;
        for(int i = 0; i < size - n - 1; ++i) {
            travel = travel->next;
        }
        travel->next = travel->next->next;
        return head;
    }
};
