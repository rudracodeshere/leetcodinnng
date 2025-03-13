class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* kth = kthNode(temp, k);
            if (kth == NULL) {
                if (prev) {
                    prev->next = temp;
                }
                break;
            }
            ListNode* next = kth->next;
            kth->next = NULL;
            ListNode* rev = reverse(temp);
            if (temp == head) {
                head = kth;
            } else {
                prev->next = kth;
            }
            prev = temp;
            temp = next;
        }
        return head;
    }
    ListNode* kthNode(ListNode* head, int k) {
        ListNode* temp = head;
       
        while(temp && k >1){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};