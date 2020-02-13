static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_position('z'-'a'+1);
        vector<int> result;
        
        for (int i = 0; i < S.length(); ++i) {
            last_position[S[i]-'a'] = i;
        }
        
        for (int i = 0; i < S.length(); ++i) {
            int temp_last = last_position[S[i]-'a'];
            for (int j = i; j <= temp_last; ++j) {
                temp_last = max(temp_last, last_position[S[j]-'a']);
            }
            result.push_back(temp_last-i+1);
            i = temp_last;
        }
        
        return result;
    }
};