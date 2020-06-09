static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector < vector < int > > levelOrderBottom(TreeNode* root) {
        vector < vector < int > > ans;
        vector < TreeNode* > next_level;
        vector < TreeNode* > prev_level = {root};

        while (root && !prev_level.empty()) {
            vector < int > level;
            for (const auto& item: prev_level) {
                if (item) {
                    level.push_back(item->val);
                    next_level.push_back(item->left );
                    next_level.push_back(item->right);
                }
            }
            if (!level.empty()) {
                ans.push_back(level);
            }
            prev_level.clear();
            swap(next_level, prev_level);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};