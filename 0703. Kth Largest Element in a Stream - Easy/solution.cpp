static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class KthLargest {
public:
    KthLargest(int k, vector < int > & nums)
        : size(k) {
        for(const auto& item : nums) {
            pq.push(item);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > size) {
            pq.pop();
        }
        return pq.top();
    }

public:
    priority_queue < int, vector < int >, greater < int > > pq;
    int size;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */