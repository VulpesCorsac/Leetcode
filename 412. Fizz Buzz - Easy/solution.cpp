static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector < string > ans;
        ans.reserve(n);
        
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                ans.push_back("FizzBuzz");
            } else if (i % 5 == 0) {
                ans.push_back("Buzz");
            } else if (i % 3 == 0) {
                ans.push_back("Fizz");
            } else {
                ans.push_back(to_string(i));                
            }
        }
        
        return ans;
    }
};