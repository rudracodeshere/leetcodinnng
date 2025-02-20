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
        unordered_set<ListNode *> st;
        ListNode * nA = headA;
        while(nA!=NULL){
            st.insert(nA);
            nA = nA->next;
        }
        ListNode * nB = headB;
        while(nB!=NULL){
            if(st.contains(nB)){
                return nB;
            }
            nB = nB->next;
        }
        return NULL;
    }
};