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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }
        int rotations = k % len;
        if (rotations == 0)
            return head;
        temp->next = head;
        temp = head;
        for (int i = 1; i < len - rotations; i++) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};