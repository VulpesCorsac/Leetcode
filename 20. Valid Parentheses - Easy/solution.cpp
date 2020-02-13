static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool isValid(string s) {
        stack < char > st;
        
        for (const auto &symbol: s) {
            switch(symbol) {
                case '{' : 
                    st.push(symbol); 
                    break;
                case '(' : 
                    st.push(symbol); 
                    break;
                case '[' : 
                    st.push(symbol); 
                    break;
                case '}' : 
                    if (st.empty())
                        return false;
                    if (st.top() != '{')
                        return false;
                    st.pop();
                    break;
                case ')' : 
                    if (st.empty())
                        return false;
                    if (st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case ']' : 
                    if (st.empty())
                        return false;
                    if (st.top() != '[')
                        return false;
                    st.pop();
                    break;
            }
        }
        
        return st.empty();
    }
};