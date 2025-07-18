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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;

        ListNode* originalHead = head->next;
        ListNode* prevTail = head;

        while (true) {
            if (head == nullptr || head->next == nullptr) break;
            ListNode* tmp = head->next->next;

            head->next->next = head;
            prevTail->next = head->next;
            head->next = tmp;
            prevTail = head;
            head = tmp;
        }
        
        return originalHead;
    }
};