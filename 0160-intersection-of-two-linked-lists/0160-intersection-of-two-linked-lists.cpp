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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA ||!headB)return NULL;
        ListNode * nA = headA;
        ListNode * nB = headB;
        while(nA!=nB){
            nA = nA == NULL?headB:nA->next;
            nB= nB == NULL?headA:nB->next;
        }
        return nA;
    }
};