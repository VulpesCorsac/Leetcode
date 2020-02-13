static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int last_erase = 0;
        unordered_map < char , int > index;
        
        for (int position = 0; position < s.length(); ++position) {
//            cout << position << " - " << s[position] << " ";
            if (!index.count(s[position])) {
//                cout << "add, ";
            } else {
//                cout << "erase [" << last_erase << " " << index[s[position]] << "], ";
                int q = index[s[position]];
                for (int temp = last_erase; temp <= index[s[position]]; ++temp) {
                    index.erase(s[temp]);
                }
                last_erase = q+1;
            }
            index[s[position]] = position;
            result = max(result, static_cast<int>(index.size()));
//            cout << result << " { ";
//            for (const auto& item: index) 
//                cout << item.first << ":" << item.second << " ";
//            cout << "}\n";
        }
        
        return result;
    }
};