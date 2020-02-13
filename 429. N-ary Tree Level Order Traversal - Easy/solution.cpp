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
    vector<vector<int>> levelOrder(Node* root) {
        func(root, 0);
        
        return result;
    }
    
    void func(Node* root, int depth) {
        if (!root) {
            return;
        }
        
        if (result.size() <= depth) {
            result.resize(depth+1);
        }
        
        result[depth].push_back(root->val);
        
        for (auto& child: root->children) {
            func(child, depth+1);
        }
        
        return;
    }
    
    vector<vector<int>> result;
};