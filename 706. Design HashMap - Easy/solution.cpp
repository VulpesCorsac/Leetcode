static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket = hash(key);
        for (auto& [k, v] : data[bucket]) {
            if (k == key) {
                v = value;
                
                return;
            }
        }
        
        data[bucket].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucket = hash(key);
        for (auto& [k, v] : data[bucket]) {
            if (k == key) {
                return v;
            }
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucket = hash(key);
        for (auto it = data[bucket].begin(); it != data[bucket].end(); ++it) {
            if (it->first == key) {
                data[bucket].erase(it);
                
                return;
            }
        }
    }
    
private:
    int hash(int key) {
        return key % buckets;
    }

    static constexpr int buckets = 10000;
    
    array < list < pair < int , int > > , buckets > data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */