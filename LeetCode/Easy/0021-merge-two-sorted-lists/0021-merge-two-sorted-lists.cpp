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

        while (list1 && list2) {
            ListNode* newNode = new ListNode();
            if (list1->val < list2->val) {
                newNode->val = list1->val;
                list1 = list1->next;
            }
            else {
                newNode->val = list2->val;
                list2 = list2->next;
            }

            if (tmp == nullptr) {
                mergedList = newNode;
                tmp = newNode;
                continue;
            }
            
            tmp->next = newNode;
            tmp = tmp->next; 
        }

        if (list1) tmp->next = list1;
        if (list2) tmp->next = list2;

        return mergedList;
    }
};