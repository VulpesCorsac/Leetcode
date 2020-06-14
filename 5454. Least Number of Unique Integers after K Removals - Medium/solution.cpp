static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int findLeastNumOfUniqueInts(vector < int >& arr, int k) {
		unordered_map < int , int > m;		
        for(const auto& item : arr) {
            ++m[item];
        }

        vector < int > v;
		for(const auto& item : m) {
			v.push_back(item.second);
		}
        
		int ans = m.size();
		sort(v.begin(), v.end());
		for(const auto& item : v) {
			if(k == 0 || k < item) {
                return ans;
            }
			k -= item;
			--ans;
		}
        
		return ans;  
    }
};