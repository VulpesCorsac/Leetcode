static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector < int > ans;
        
        unordered_map < char, int > dict;
        for (const auto& item : p) {
            --dict[item];
        }
        
        for (int i = 0; i < p.length(); ++i) {
            ++dict[s[i]];
            
            if (dict[s[i]] == 0) {
                dict.erase(s[i]);
            }
        }
        if (dict.size() == 0) {
            ans.push_back(0);
        }
       
        for (int i = p.length(); i < s.length(); ++i) {
            ++dict[s[i]];
            
            auto j = i-p.length();
            --dict[s[j]];
            
            if (dict[s[j]] == 0) {
                dict.erase(s[j]);
            }
            if (dict[s[i]] == 0) {
                dict.erase(s[i]);
            }

            if (dict.size() == 0) {
                ans.push_back(i-p.length()+1);
            }
        }
        
        return ans;
    }
};