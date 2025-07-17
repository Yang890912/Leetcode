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
    ListNode* middleNode(ListNode* head) {
        int middlePos = -1;
        ListNode* tmpHead = head;
        ListNode* middle = nullptr;

        while (tmpHead != nullptr) {
            middlePos++;
            tmpHead = tmpHead->next;
        }

        tmpHead = head;
        middlePos = middlePos / 2 + middlePos % 2;

        for (int i = 0; i <= middlePos; i++) {
            middle = tmpHead;
            tmpHead = tmpHead->next;
        }

        return middle;
    }
};