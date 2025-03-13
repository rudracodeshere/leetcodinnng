class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        Node* dummy = new Node(-1);
        temp = head;
        Node* newTemp = mp[temp];
        dummy->next = newTemp;
        while (temp) {
            newTemp->next = mp[temp->next];
            newTemp->random = mp[temp->random];
            newTemp = newTemp->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};