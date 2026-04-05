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
        bool buf = false;
        ListNode* head = l1;
        ListNode* pre = l1;
        while(l1) {
            int count = l1->val;
            if(buf) {
                ++count;
                buf = false;
            }
            if(l2) {
                count += l2->val;
                l2 = l2->next;
                if(count > 9) {
                    l1->val = count%10;
                    buf = true;
                } else {
                    buf = false;
                    l1->val = count;
                }
            } else {
                if(count > 9) {
                    l1->val = 0;
                    buf = true;
                } else {
                    l1->val = count;
                    return head;
                }
            }
            pre = l1;
            l1 = l1 -> next;
        }
        if(l2) {
            pre->next = l2;
        }
        while(l2) {
            int count = l2->val;
            if(buf) {
                if(++count > 9) {
                    buf = true;
                    l2->val = 0;
                } else {
                    l2->val = count;
                    return head;
                }
            } else {
                return head;
            }
            pre = l2;
            l2 = l2->next;
        }
        if(buf) {
            pre->next = new ListNode(1);
        }
        return head;
    }
};
