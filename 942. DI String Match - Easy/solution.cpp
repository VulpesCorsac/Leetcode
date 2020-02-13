static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> result(S.size()+1, 0);

        int min_number = 0;
        int max_number = S.size();
        
        for (int i = 0; i < S.size(); ++i) {
            if(S[i] == 'I') {
                result[i] = min_number++;
            } else {
                result[i] = max_number--;
            }
        }
        
        result[result.size()-1] = min_number;
        return result;
    }
};