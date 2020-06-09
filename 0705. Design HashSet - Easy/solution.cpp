static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }

    void add(int key) {
        auto bucket = hash(key);
        for (const auto& item : data[bucket]) {
            if (item == key) {
                return;
            }
        }

        data[bucket].push_back(key);
    }

    void remove(int key) {
        auto bucket = hash(key);
        for (auto it = data[bucket].begin(); it != data[bucket].end(); ++it) {
            if (*it == key) {
                data[bucket].erase(it);

                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto bucket = hash(key);
        for (const auto& item : data[bucket]) {
            if (item == key) {
                return true;
            }
        }

        return false;
    }

private:
    int hash(int key) {
        return key % buckets;
    }

    static constexpr int buckets = 10000;

    array < list < int > , buckets > data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */