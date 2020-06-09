static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum()
        : root(new TrieNode(0)) {

    }

    void insert(string key, int val) {
        return insert_helper(key, val);
    }

    int sum(string prefix) const noexcept {
        return sum_helper(prefix);
    }

public:
    struct TrieNode {
        unordered_map < char, TrieNode* > children;
        int total;
        int value;
        bool end_of_word;

        TrieNode(int value = 0)
            : total(value)
            , value(value)
            , end_of_word(false) {

        }
    };

    int sum_helper(const string& key) const noexcept {
        auto node = get(key, false);

        return node ? node->total : 0;
    }

    void insert_helper(const string& key, int val) {
        int old = get(key, true)->value;

        auto node = root;
        for (const auto& c : key) {
            node->total += val - old;
            node = node->children[c];
        }

        node->value = val;
        node->total += val - old;
        node->end_of_word = true;
    }

    TrieNode* get(const string& key, bool create) const noexcept {
        auto node = root;

        for (const auto& c : key) {
            if (!node->children.count(c)) {
                if (create) {
                    node->children[c] = new TrieNode();
                } else {
                    return nullptr;
                }
            }

            node = node->children[c];
        }

        return node;
    }

protected:
    TrieNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */