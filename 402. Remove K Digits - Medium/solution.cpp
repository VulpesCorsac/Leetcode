static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    string removeKdigits(const string &num, int k) {
        if (k >= num.length()) {
            return "0";
        }
        
        int fall = k;
        
        vector < char > st;
        st.reserve(num.length());
        for (int i = 0; i < num.length(); ++i) {
            /*
            cout << "i = " << i << ", num[i] = " << num[i] << ", k = " << k <<"\n";
            //*/
            while (!st.empty() && num[i] < st.back() && k) {
                --k;
                st.pop_back();
            }
            st.push_back(num[i]);
            
            /*
            cout << "new stack: ";
            for (int i = 0; i < st.size(); ++i) {
                cout << st[i] << " ";
            }
            cout << "\n";
            //*/
        }

        string ans;
        ans.reserve(st.size());
        for(int i = 0; i < st.size(); ++i){
			if(!ans.empty() || st[i] != '0') {
				ans += st[i];
                
                if (ans.size() == num.size()-fall) {
                    break;
                }
            }
		}
        
        return ans.empty() ? "0" : ans;
    }
};