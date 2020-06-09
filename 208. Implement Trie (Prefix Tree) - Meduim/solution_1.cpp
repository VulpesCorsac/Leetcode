static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        db.clear();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        db.emplace_back(word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        for (const auto& item : db) {
            if (item == word) {
                return true;
            }
        }

        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for (const auto& item : db) {
            if (item.length() >= prefix.length()) {
                bool match = true;

                for (size_t i = 0; i < prefix.length(); ++i) {
                    if (item[i] != prefix[i]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    return true;
                }
            }
        }

        return false;
    }

protected:
    vector < string > db;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */