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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> um;
        for (int num : nums) um[num]++;

        while (um.count(head->val)) head = head->next;       

        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr != nullptr) {
            if (um.count(curr->val)) {
                curr = curr->next;
                prev->next = nullptr;
            }
            else {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};