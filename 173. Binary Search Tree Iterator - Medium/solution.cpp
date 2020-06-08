static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return flattened[idx++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return idx != flattened.size();
    }

private:
    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        
        traverse(root->left);
        flattened.push_back(root->val);
        traverse(root->right);
    }

    vector < int > flattened;
    int idx = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */