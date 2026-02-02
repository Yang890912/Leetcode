/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    unordered_set<ListNode*> st;

public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        else if (st.count(head)) return true;
        else if (!st.count(head)) st.insert(head);
        return hasCycle(head->next);
    }
};