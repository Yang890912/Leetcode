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
        if (head == nullptr) return head;

        ListNode* prevPtr = nullptr;
        ListNode* currPtr = head;
        ListNode* nextPtr = head->next;

        while (nextPtr != nullptr) {
            ListNode* tmpPtr = nextPtr->next;
            nextPtr->next = currPtr;
            currPtr->next = prevPtr;
            
            prevPtr = currPtr;
            currPtr = nextPtr;
            nextPtr = tmpPtr;
        }

        return currPtr;
    }
};