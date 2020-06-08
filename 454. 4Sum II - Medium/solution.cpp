static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int fourSumCount(vector < int > & A, vector < int > & B, vector < int > & C, vector < int > & D) {
        return kSumCount({A, B, C, D});
    }

private:
    unordered_map < int, int  > m;

    int kSumCount(const vector < vector < int > > &lists) {
        addToHash(lists, 0, 0);
        
        return countComplements(lists, lists.size() / 2, 0);
    }
    
    void addToHash(const vector < vector < int > > & lists, int i, int sum) {
        if (i == lists.size() / 2) {
            ++m[sum];
        } else {
            for (auto a : lists[i]) {
                addToHash(lists, i + 1, sum + a);
            }
        }
    }
    
    int countComplements(const vector < vector < int > > & lists, int i, int complement) {
        if (i == lists.size()) {
            auto it = m.find(complement);
            return it == m.end() ? 0 : it->second;
        }
        
        int cnt = 0;
        for (int a : lists[i]) {
            cnt += countComplements(lists, i + 1, complement - a);
        }
        
        return cnt;
    }
};