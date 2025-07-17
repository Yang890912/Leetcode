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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedList = nullptr;
        ListNode* tmp = nullptr;
        
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val > list2->val) {
            tmp = list1;
            list1 = list2;
            list2 = tmp;
        }

        mergedList = list1;

        while (true) {
            if (list1->next == nullptr) {
                list1->next = list2;
                return mergedList;
            }

            if (list1->next->val > list2->val) {
                tmp = list1->next;
                list1->next = list2;
                list2 = tmp;
            }

            list1 = list1->next;
        }

        return mergedList;
    }
};