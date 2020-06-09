static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};

        for(auto c : magazine) {
            ++cnt[c-'a'];
        }
        for(auto c : ransomNote){
            if(--cnt[c-'a']<0) {
                return false;
            }
        }
        return true;
    }
};