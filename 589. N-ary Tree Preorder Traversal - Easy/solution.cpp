/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<int> preorder(Node* root) {
        result.clear();
        
        addToVec(root);
        
        return result;
    }
    
    void addToVec(Node* root) {
        if (!root) {
            return;
        }
        
        result.push_back(root->val);
        for (auto& child: root->children) {
            addToVec(child);
        }
    }
    
    vector < int > result;
};