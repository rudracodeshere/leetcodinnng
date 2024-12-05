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
    bool hasCycle(ListNode* head) {
        // ListNode* temp = head;
        // set<ListNode*> s;
        // while (temp) {
        //     if (s.contains(temp)) {
        //         return true;
        //     }
        //     s.insert(temp);
        //     temp = temp->next;
        // }
        // return false;
        if(head == NULL)return false;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            if (fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};