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
    ListNode* reverseList(ListNode* head) {
        ListNode *res = new ListNode();
        // ListNode *tmp = nullptr;
        while(head) {
            ListNode *tmp = head->next;
            head->next = res->next;
            res->next = head;
            head = tmp;
        }
        return res->next;
    }
};
