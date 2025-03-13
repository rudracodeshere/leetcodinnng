class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        while (temp) {
            temp->next->random = temp->random ? temp->random->next : nullptr;
            temp = temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* copy = dummy;
        temp = head;
        while (temp) {
            copy->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            copy = copy->next;
        }

        return dummy->next;
    }
};
