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
ListNode * reverse(ListNode * head){
ListNode *prev = NULL;
ListNode *curr = head;
ListNode *next = NULL;
while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
}
return prev;
}
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * slowNext = slow->next;
        slow->next = NULL;
        ListNode *revHead  = reverse(slowNext);
        slow = head;
        while(slow && revHead){
            if(slow->val!=revHead->val)return false;
        slow = slow->next;
        revHead = revHead->next;
        }


        return true;
    }
};