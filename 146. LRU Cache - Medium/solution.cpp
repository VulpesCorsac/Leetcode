static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class LRUCache {
public:
    LRUCache(int capacity)
        : max_capacity(capacity) {
        
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        } else {
//            touch(cache[key]);
            touchViaSplice(key);
            
            return used.begin()->second;
        }
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
//            touch(cache[key]);
            touchViaSplice(key);
            
            used.begin()->second = value;
        } else {
            if(cache.size() == max_capacity) {
                int delete_key = used.back().first;
                cache.erase(delete_key);
                used.pop_back();
            }
            used.push_front({key, value});
            cache[key] = used.begin();
        }
    }
    
protected:
    template < class Iterator >
    void touch(Iterator it) {
        auto key = it->first;
        auto value = it->second;
        
        used.erase(it);
        used.push_front({key, value});
        cache[key] = used.begin();
    }
    
    void touchViaSplice(int key) {
        used.splice(used.begin(), used, cache[key]);    
    }
    
protected:
    int max_capacity = 0;
    list < pair < int, int > > used;
    unordered_map < int , list < pair < int, int > >::iterator > cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */