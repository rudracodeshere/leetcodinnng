/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*, Node*>& mp) {
        if (node == NULL)
            return NULL;
        if (mp.count(node)) {
            return mp[node];
        }

        mp[node] = new Node(node->val);

        for (auto n : node->neighbors) {
            mp[node]->neighbors.push_back(dfs(n,mp));
        }

        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};