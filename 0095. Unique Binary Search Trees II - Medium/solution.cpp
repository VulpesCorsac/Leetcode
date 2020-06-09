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
    vector < TreeNode* > generateTrees(int n) {
        if (n == 0) {
            return {};
        } else {
            return generate(1, n);
        }
    }

    vector < TreeNode* > generate(int from, int to) {
        if (from > to) {
            return {nullptr};
        }

        if (from == to) {
            return {new TreeNode(from)};
        }

        vector < TreeNode* > ans;
        for (int i = from; i <= to; ++i) {
            auto left  = generate(from, i-1);
            auto right = generate(i+1 , to );

            for (auto left_node : left) {
                for (auto right_node : right) {
                    ans.push_back(new TreeNode(i, left_node, right_node));
                }
            }
        }

        return ans;
    }
};