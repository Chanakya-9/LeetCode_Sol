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
    // unordered_set<int> check;
    unordered_map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return node;
        }
        auto it = mp.find(node->val);
        if (it != mp.end()) {
            return it->second;
        }
        Node* head = new Node(node->val);
        // check.insert(head->val);
        mp[head->val] = head;

        for (auto nei : node->neighbors) {
            head->neighbors.push_back(cloneGraph(nei));
        }
        return head;
    }
};