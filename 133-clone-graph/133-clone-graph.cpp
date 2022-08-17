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
        
        vector <bool> visited (101, false);
        vector <Node*> nodeAdd (101, NULL);
        
        queue <Node*> q;    
        if (node)   q.push(node);
        visited[1] = true;
        
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            // cout << "curr " << curr->val << endl;
            Node* cloneNode;
            
            if (nodeAdd[curr->val]==NULL) {
                cloneNode = new Node (curr->val);
                nodeAdd[curr->val] = cloneNode;
            } else {
                cloneNode = nodeAdd[curr->val];
            }
            
            for (auto nbr: curr->neighbors) {
                // cout << nbr->val << " ";
                if (!visited[nbr->val]) {
                    visited[nbr->val] = true;
                    q.push(nbr);
                }
                
                if (nodeAdd[nbr->val]==NULL) {
                    Node* tempNode = new Node (nbr->val);
                    nodeAdd[nbr->val] = tempNode;
                    cloneNode->neighbors.push_back(tempNode);
                } else {
                    cloneNode->neighbors.push_back(nodeAdd[nbr->val]);
                }
                // cout << endl;
            }
        }
        return nodeAdd[1];
    }
};