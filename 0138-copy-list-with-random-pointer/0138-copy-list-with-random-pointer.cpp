
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp = temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while (temp) {
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        return dummy->next;
    }
};