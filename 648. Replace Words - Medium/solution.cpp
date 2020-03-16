static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    class Node {
    public:
        bool eow = false;
        Node* next[26] = {nullptr};
    };

    void add(Node *node, const string &s) {
        for (int i = 0; i < s.length(); ++i) {
            if (!node->next[s[i]-'a']) {
                node->next[s[i]-'a'] = new Node;
            }
            node = node->next[s[i]-'a'];
        }
        node->eow = true;
    }

    string root_word(Node *node, const string &s) {
        string ans;

        for (int i = 0; i < s.length(); ++i) {
            if (node->next[s[i]-'a']) {
                node = node->next[s[i]-'a'];

                ans += s[i];

                if (node->eow) {
                    return ans;
                }
            } else {
                return s;
            }
        }

        return ans;
    }

    string replaceWords(const vector < string > &dict, const string &sentence) {
        Node* root = new Node;
        for (const string& word : dict) {
            add(root, word);
        }

        string ans;
        stringstream s(sentence);
        string word;
        bool first = true;
        while (s >> word) {
            if (first) {
                first = false;
            } else {
                ans += " ";
            }
            ans += root_word(root, word);
        }

        return ans;
    }
};