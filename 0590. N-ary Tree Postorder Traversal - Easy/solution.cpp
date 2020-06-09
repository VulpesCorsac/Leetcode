static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
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
class Solution {
public:
    vector<int> postorder(Node* root) {
        result.clear();

        addToVec(root);

        return result;
    }

    void addToVec(Node* root) {
        if (!root) {
            return;
        }

        for (auto& child: root->children) {
            addToVec(child);
        }
        result.push_back(root->val);
    }

    vector < int > result;
};