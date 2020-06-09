static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int evalRPN(vector < string >& tokens) {
        unordered_map < string, function < int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };

        stack < int > st;

        for (const auto& token : tokens) {
            if (!map.count(token)) {
                st.push(stoi(token));
            } else {
                auto op1 = st.top();
                st.pop();
                auto op2 = st.top();
                st.pop();
                st.push(map[token](op2, op1));
            }
        }
        return st.top();
    }
};