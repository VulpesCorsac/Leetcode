static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

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
class Solution {
public:
    vector < TreeNode* > findDuplicateSubtrees(TreeNode* root) {
        serialize(root);


        vector < TreeNode* > ans;
        for (auto [k, v] : map) {
            if (v.size() > 1) {
                ans.push_back(v[0]);
            }
        }

        return ans;
    }

private:
    unordered_map < string, vector < TreeNode* > > map;

    string serialize(TreeNode* node) {
        if (!node) {
            return "#";
        }

        string s = "(" + serialize(node->left) + to_string(node->val) + serialize(node->right) + ")";

        map[s].push_back(node);

        return s;
    }
};