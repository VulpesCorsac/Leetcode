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
    bool isValidSequence(TreeNode* root, vector < int >& arr, int pos = 0) {
        if (!root || pos >= arr.size()) {
            return false;
        }
                
        if (root->val != arr[pos]) {
            return false;
        }
            
        if (pos+1 == arr.size()) {
            if (!root->left && !root->right) {
                return true;
            } else {
                return false;
            }
        }
        
        bool result = false;
        if (root->left) {
            result |= isValidSequence(root->left, arr, pos+1);
        }
        if (root->right) {
            result |= isValidSequence(root->right, arr, pos+1);
        }

        return result;
    }
    
    // Shorter code, longer runtime bacause more recursion
    bool isValidSequence1(TreeNode* root, vector < int >& arr, int pos = 0) {
        if (!root || root->val != arr[pos]) {
            return false;
        }
            
        if (pos+1 == arr.size()) {
            return !root->left && !root->right;
        }
        
        return isValidSequence(root->left, arr, pos+1) || isValidSequence(root->right, arr, pos+1);
    }
};