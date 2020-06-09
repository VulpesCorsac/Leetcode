static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    class Log {
    public:
        Log(const string& s, int position_in_vector)
            : log("")
            , tag("")
            , position(position_in_vector)
            , isDigital(true) {

            int pos = 0;
            for (; s[pos] != ' '; ++pos);

            tag = string(s, 0, pos);
            log = string(s, pos);

            for (; pos < s.length(); ++pos) {
                if (s[pos] != ' ' && !isdigit(s[pos])) {
                    isDigital = false;
                    break;
                }
            }
        }

        bool operator < (const Log &rhs) {
            auto& lhs = *this;

            if (lhs.isDigital ^ rhs.isDigital) {
                return !lhs.isDigital;
            }

            if (lhs.isDigital) {
                return lhs.position < rhs.position;
            }

            if (lhs.log != rhs.log) {
                return lhs.log < rhs.log;
            }

            return lhs.tag < rhs.tag;
        }

        string log;
        string tag;
        int position;
        bool isDigital;
    };

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector < Log > log;
        log.reserve(logs.size());

        for (int i = 0; i < logs.size(); ++i) {
            log.emplace_back(Log(logs[i], i));
        }

        sort(log.begin(), log.end());

        vector < string > ans;
        ans.reserve(logs.size());

        for (int i = 0; i < logs.size(); ++i) {
            ans.push_back(log[i].tag + log[i].log);
        }

        return ans;
    }
};