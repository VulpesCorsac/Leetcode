static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0;
        
        for (Node* child : root->children) {
            ans = max(ans, maxDepth(child));
        }
        
//        cout << root->val << " - " << ans << endl;
        
        return ans+1;
    }
};