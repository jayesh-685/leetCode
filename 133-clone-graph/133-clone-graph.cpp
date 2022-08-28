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
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        Node* cloneNode = new Node (node->val);
        unordered_map <Node*, Node*> m;
        m[node] = cloneNode;
        queue <Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            vector<Node*> nbrs;
            for (auto nbr: curr->neighbors) {
                if (!m[nbr]) {
                    m[nbr] = new Node (nbr->val);
                    q.push(nbr);
                }
                nbrs.push_back(m[nbr]);
            }
            m[curr]->neighbors = nbrs;
        }
        
        return cloneNode;
    }
};