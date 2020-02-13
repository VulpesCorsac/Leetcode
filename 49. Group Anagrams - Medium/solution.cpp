static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int get_mask_to_vector_position(string s) {
        sort(s.begin(), s.end());
        auto find = mask_to_vector_position.find(s);
        
        if (find != mask_to_vector_position.end()) {
            return find->second;
        } else {
            mask_to_vector_position[s] = result.size();
            result.resize(mask_to_vector_position[s] + 1);
            return mask_to_vector_position[s];
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (const auto& str: strs) {
            result[get_mask_to_vector_position(str)].push_back(str);
        }
        
        return result;
    }
    
private:
    unordered_map<string, int> mask_to_vector_position;
    vector<vector<string>> result;
};