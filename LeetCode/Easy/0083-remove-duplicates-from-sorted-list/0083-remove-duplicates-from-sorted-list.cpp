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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        int curr = head->val;
        ListNode* handle = head;
        ListNode* tmp = head->next;
        while (tmp != nullptr) {
            if (tmp->val == curr) {
                handle->next = tmp->next;
                tmp = tmp->next;
            }
            else if (tmp->val > curr) {
                curr = tmp->val;
                handle->next = tmp;
                tmp = tmp->next;
                handle = handle->next;
            }
        }
        return head;
    }
};