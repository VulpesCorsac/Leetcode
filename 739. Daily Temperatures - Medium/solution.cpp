static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector < int > dailyTemperatures(vector < int >& T) {
        vector < int > ans (T.size(), 0);
        stack < int > st; 
        
        for (int i = T.size()-1; i >= 0; --i) {
            while (!st.empty() && T[i] >= T[st.top()]) {
                st.pop();
            }
            
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            
            st.push(i);
        }
        
        return ans;
    }
};