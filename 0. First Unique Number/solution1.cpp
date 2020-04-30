static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class FirstUnique {
public:
    FirstUnique(vector < int >& nums) {
        for (const auto& item : nums) {
            add(item);
        }
    }
    
    int showFirstUnique() {
        if (unique_numbers.empty()) {
            return -1;
        }
        return unique_numbers.front();
    }
    
    void add(int value) {
        if (cnt[value] == 0) {
            unique_numbers.push_back(value);
            pos[value] = unique_numbers.end();
            --pos[value];
        } else if (cnt[value] == 1) {
            unique_numbers.erase(pos[value]);
        } else {
            // do nothing;
        }
        ++cnt[value];
    }
    
    list < int > unique_numbers;
    unordered_map < int , int > cnt;
    unordered_map < int , list < int >::iterator > pos;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */