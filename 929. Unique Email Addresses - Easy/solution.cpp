static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map < string , int > unique_emails;
        
        for (const auto& item: emails) {
            unique_emails[filter(item)] = 1;
        }
        
        return unique_emails.size();
    }
    
    string filter(string s) {
        string ans = s;
        int ans_pos = 0;
        
        int stage = 0;
        // 0 - taking local name
        // 1 - ignoring local name
        // 2 - taking domain name
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '@') {
                ans[ans_pos++] = '@';
                stage = 2;
            } else if (s[i] == '+') {
                stage = 1;
            } else if (s[i] == '.') {
                if (stage == 2) {
                    ans[ans_pos++] = '.';                
                }
            } else {
                if (stage != 1) {
                    ans[ans_pos++] = s[i];
                }
            }
        }
        
        ans.resize(ans_pos);
        
        return ans;
    }
};