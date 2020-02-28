static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector < string > fullJustify(vector < string > &words, int maxWidth) {
        vector < string > ans;
        
        int current_width = 0;
        int first_not_taken_word = 0;
        
        for (int i = 0; i < words.size(); ++i) {
            if (current_width == 0) {
                current_width = words[i].length();
            } else {
                if (current_width + 1 + words[i].length() <= maxWidth) {
                    current_width += 1 + words[i].length();
                } else {
                    ans.push_back(fully_justified(vector < string >(words.begin() + first_not_taken_word, 
                                                                    words.begin() + i
                                                                   ), 
                                                  maxWidth
                                                 )
                                 );
                    
                    current_width = words[i].length();
                    first_not_taken_word = i;
                }
            }
        }
        
        ans.push_back(left_justified(vector < string >(words.begin() + first_not_taken_word, 
                                                       words.begin() + words.size()
                                                      ),
                                     maxWidth
                                    )
                     );
        
        return ans;
    }
        
    string left_justified(const vector < string > &words, int maxWidth) {
        string ans;
        
        for (const auto &word : words) {
            if (ans.empty()) {
                ans = word;
            } else {
                ans += " " + word;
            }
        }
        
        return ans + spaces_string(maxWidth - ans.length());
    }
    
    string fully_justified(const vector < string > &words, int maxWidth) {
        if (words.size() <= 1) {
            return left_justified(words, maxWidth);
        }
        
        string ans;
        
        int words_length = 0;
        
        for (const auto &word : words) {
            words_length += word.length();
        }
        
        int spaces = (maxWidth - words_length) / (words.size() - 1);
        int words_with_extra_spaces = (maxWidth - words_length) % (words.size() - 1);

        for (int i = 0; i < words.size(); ++i) {
            if (i != words.size() - 1) {
                ans += words[i] + spaces_string(spaces + (i < words_with_extra_spaces ? 1 : 0));
            } else {
                ans += words[i];
            }
        }
        
        return ans;
    }
    
    string spaces_string(int width) {
        if (width == 0) {
            return "";
        }
        
        string ans;
        ans.resize(width);
        
        for (auto &c : ans) {
            c = ' ';
        }
        
        return ans;
    }
};