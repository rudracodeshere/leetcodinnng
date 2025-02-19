/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tempPtr = node;
        while (node->next != NULL) {
            if (node->next->next == NULL) {
                tempPtr = node;
            }
            int temp = node->val;
            node->val = node->next->val;
            node->next->val = temp;
            node = node->next;
        }
        tempPtr->next = NULL;
    }
};