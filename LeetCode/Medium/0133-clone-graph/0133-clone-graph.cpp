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
    unordered_map<int, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        if (visited.count(node->val)) return visited[node->val];

        Node* nNode = new Node();
        nNode->val = node->val;
        visited[node->val] = nNode;
        for (Node* nbor : node->neighbors) {
            nNode->neighbors.push_back(cloneGraph(nbor));
        }

        return nNode;
    }
};