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
        if (node == nullptr) return nullptr;

        queue<Node*> q, cq;
        map<int, Node*> valMap2Node;
        map<Node*, Node*> nodeMap;

        Node* cloneNode = new Node(node->val);
        valMap2Node[node->val] = cloneNode;
        nodeMap[node] = cloneNode;
        q.push(node);

        while (!q.empty()) {
            Node* n = q.front();
            Node* cn = nodeMap[n];
            q.pop();

            for (int i = 0; i < n->neighbors.size(); i++) {
                if (valMap2Node.find(n->neighbors[i]->val) != valMap2Node.end()) {
                    cn->neighbors.push_back(valMap2Node[n->neighbors[i]->val]);
                }
                else {
                    Node* neighbor = new Node(n->neighbors[i]->val);
                    cn->neighbors.push_back(neighbor);
                    valMap2Node[n->neighbors[i]->val] = neighbor;
                    nodeMap[n->neighbors[i]] = neighbor;
                    q.push(n->neighbors[i]);
                }
            }
        }

        return cloneNode;
    }
};