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
static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root || root->val == x || root->val == y) {
            return false;
        }
        
        queue < TreeNode* > nodes;
        nodes.push(root);
        
        while (!nodes.empty()) {
            int nodes_to_examine = nodes.size();
            bool found_x = false;
            bool found_y = false;
            for (int i = 0; i < nodes_to_examine; ++i) {
                auto node = nodes.front();
                nodes.pop();
                
                if (node->val == x) {
                    found_x = true;
                }
                if (node->val == y) {
                    found_y = true;
                }
                
                if (node->left && node->right) {
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
            
            if (found_x && found_y) {
                return true;
            }
        }
        
        return false;
    }
};