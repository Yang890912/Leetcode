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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            res = merge(res, lists[i]);
        }

        return res;
    }

    ListNode* merge(ListNode* n1, ListNode* n2) {
        if (!n1 && !n2) return nullptr;
        else if (!n1) return n2;
        else if (!n2) return n1;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (n1 && n2) {
            if (n1->val < n2->val) {
                tail->next = n1;
                n1 = n1->next;
            }
            else {
                tail->next = n2;
                n2 = n2->next;
            }
            tail = tail->next;
        }

        while (n1) {
            tail->next = n1;
            tail = tail->next;
            n1 = n1->next;
        }
        while (n2) {
            tail->next = n2;
            tail = tail->next;
            n2 = n2->next;
        }

        return dummy->next;
    }
};