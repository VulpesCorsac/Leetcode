static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class FirstUnique {
public:
    FirstUnique(vector < int > & nums) {
        for(int num: nums){
            ++count[num];
            if (count[num] == 1) {
                q.push(num);
            }
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && count[q.front()] > 1){
            q.pop();
        }
        
        if(q.empty()){
            return -1;
        } else{
            return q.front();
        }
    }
    
    void add(int value) {
        ++count[value];
        if(count[value] == 1) {
            q.push(value);
        }
    }

    queue < int > q;
    unordered_map < int, int > count;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */