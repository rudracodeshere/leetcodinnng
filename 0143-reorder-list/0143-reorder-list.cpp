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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* sec = slow->next;
        slow->next = NULL;

        while (sec) {
            ListNode* next = sec->next;
            sec->next = prev;
            prev = sec;
            sec = next;
        }

        ListNode* first = head;
        sec = prev;
        while (sec) {
            ListNode* f1 = first->next;
            ListNode* s1 = sec->next;
            first->next = sec;
            sec->next = f1;
            first = f1;
            sec = s1;
        }
    }
};