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
        ListNode* temp = head;
        set<ListNode*> s;
        while (temp) {
            if (s.contains(temp)) {
                delete temp;
                return true;
            }
            s.insert(temp);
            temp = temp->next;
        }
        delete temp;
        return false;
    }
};