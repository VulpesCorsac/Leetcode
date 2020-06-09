static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : db(1, Node()) {

    }

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        size_t idx = 0;
        for (const auto &c : word) {
            if (db[idx].next[c-'a']) {
                idx = db[idx].next[c-'a'];
            } else {
                db.emplace_back();
                db[idx].next[c-'a'] = db.size()-1;
                idx = db.size()-1;
            }
        }
        db[idx].end_of_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        return find(word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        return find(prefix, false);
    }

protected:
    static const size_t aphabet_size = 26;

    class Node {
    public:
        size_t next[aphabet_size] = {};
        bool end_of_word = false;
    };

    vector < Node > db;

    bool find(const string& word, bool exact = true) {
        size_t idx = 0;
        for (const auto& c : word) {
            idx = db[idx].next[c-'a'];

            if (!idx) {
                return false;
            }
        }

        if (exact) {
            return db[idx].end_of_word;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */