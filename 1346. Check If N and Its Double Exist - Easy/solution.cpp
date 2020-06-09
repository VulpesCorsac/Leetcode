static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool checkIfExist(vector < int >& arr) {
        unordered_map < int, int > s;
        for (const auto& x: arr) {
            s[x]++;
        }

        for (const auto& x: arr) {
            if (x && s.count(x * 2)) {
                return true;
            } else if (!x && s[x] > 1) {
                return true;
            }
        }

        return false;
    }

    bool checkIfExistN2(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i) {
            for(int j = i+1; j < arr.size(); ++j) {
                if(arr[i] * 2 == arr[j] || arr[j] * 2 == arr[i]) {
                    return true;
                }
            }
        }

        return false;
    }
};