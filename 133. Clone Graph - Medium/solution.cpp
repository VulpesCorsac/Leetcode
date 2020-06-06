static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

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
private:
    unordered_map < Node*, Node* > hash;

public:
    Node* cloneGraph(Node* node) {
       if (!node) {
           return node;
       }
       
       if(!hash.count(node)) {
           hash[node] = new Node(node->val);
           for (const auto& x : node->neighbors) {
                hash[node]->neighbors.push_back(cloneGraph(x));
           }
       }
       
       return hash[node]; 
    }
};